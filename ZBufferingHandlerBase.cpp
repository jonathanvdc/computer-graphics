#include "ZBufferingHandlerBase.h"

#include "RenderHandler.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <exception>
#include "IOutputImage.h"
#include "RenderHandler.h"
#include "IShape.h"
#include "IProjection.h"
#include "MultiLine.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Face.h"
#include "Wireframe.h"
#include "Helpers.h"
#include "MatrixTransformation.h"
#include "MatrixHelpers.h"
#include "SolidColorBrush.h"
#include "NormalizedShape.h"
#include "PerspectiveProjection.h"
#include "ParallelProjection.h"
#include "Cube.h"
#include "Tetrahedron.h"
#include "Octahedron.h"
#include "Icosahedron.h"
#include "Dodecahedron.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Torus.h"
#include "lparser.h"
#include "TurtleMesh.h"
#include "CompositeShape.h"
#include "MeshHandlerBase.h"

bool ZBufferingHandlerBase::UseZBuffer()
{
	return true;
}

void ZBufferingHandlerBase::OutputZBuffer(std::shared_ptr<Engine::IDepthBuffer> zbuf, std::string Name)
{
	double maxZ = std::numeric_limits<double>::infinity(), minZ = -std::numeric_limits<double>::infinity();

	for (size_t i = 0; i < zbuf->getWidth(); i++)
	{
		for (size_t j = 0; j < zbuf->getHeight(); j++)
		{
			auto val = zbuf->getItem(Engine::PixelPosition(i, j, Engine::Vector2(i / (double)zbuf->getWidth(), j / (double)zbuf->getHeight())));
			if (!std::isinf(val))
			{
				if (std::isinf(maxZ))
				{
					maxZ = val;
				}
				if (std::isinf(minZ))
				{
					minZ = val;
				}

				if (maxZ < val)
				{
					maxZ = val;
				}
				else if (minZ > val)
				{
					minZ = val;
				}
			}
		}
	}

	auto zbufImg = img::EasyImage(zbuf->getWidth(), zbuf->getHeight());

	for (size_t i = 0; i < zbufImg.get_width(); i++)
	{
		for (size_t j = 0; j < zbufImg.get_height(); j++)
		{
			auto val = zbuf->getItem(Engine::PixelPosition(i, j, Engine::Vector2(i / (double)zbufImg.get_width(), j / (double)zbufImg.get_height())));
			zbufImg(i, j) = ToZBufferColor(val, minZ, maxZ);
		}
	}
	std::ofstream zbufOut;
	zbufOut.open("zbuf_" + Name + ".bmp");
	zbufOut << zbufImg;
}

void ZBufferingHandlerBase::OutputZBuffer(const ini::Section& Configuration, std::string Name, std::shared_ptr<Engine::IDepthBuffer> buffer)
{
	if (Configuration["outputZBuffer"].as_bool_or_default(false))
	{
		OutputZBuffer(buffer, Name);
	}
}

void ZBufferingHandlerBase::OutputZBuffer(const ini::Section& Configuration, std::string Name, std::shared_ptr<Engine::IOutputImage> image)
{
	if (Configuration["outputZBuffer"].as_bool_or_default(false))
	{
		auto zbuf = std::dynamic_pointer_cast<Engine::IRenderTarget>(image)->getDepthBuffer();

		OutputZBuffer(zbuf, Name);
	}
}

void ZBufferingHandlerBase::OutputZBuffer(const ini::Section& Configuration, std::shared_ptr<Engine::IOutputImage> image)
{
	return OutputZBuffer(Configuration, GetValue<std::string>(Configuration["name"], "main"), image);
}

std::shared_ptr<Engine::IOutputImage> ZBufferingHandlerBase::Render(const ini::Configuration& Configuration)
{
	auto image = this->MeshHandlerBase::Render(Configuration);

	OutputZBuffer(Configuration["General"], image);

	return image;
}