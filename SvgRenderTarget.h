#pragma once
#include <ostream>
#include <vector>
#include "ISurface.h"
#include "IRenderContext.h"
#include "IRenderTarget.h"
#include "IVectorRenderTarget.h"
#include "VectorRenderContext.h"
#include "SvgVectorPath.h"
#include "IOutputImage.h"
#include "ConstantDepthBuffer.h"

namespace Engine
{
	class SvgRenderTarget : public IVectorRenderTarget, public IOutputImage
	{
	public:
		SvgRenderTarget(double Width, double Height) : width(Width), height(Height) { }

		// Gets the surface's width.
		double getWidth() const override { return this->width; }

		// Gets the surface's height.
		double getHeight() const override { return this->height; }

		// Gets the render target's render context, which supports the creation of shapes to draw on this render target.
		std::shared_ptr<IRenderContext> getContext() const override { return std::make_shared<VectorRenderContext>(this->width, this->height); }
		std::shared_ptr<IDepthBuffer> getDepthBuffer() const override { return std::make_shared<ConstantDepthBuffer>(this->width, this->height); }

		std::shared_ptr<VectorPathBase> AddPath() override
		{ 
			auto path = std::make_shared<SvgVectorPath>(this->width, this->height);
			paths.push_back(path);
			return path;
		}

		std::string GetExtension() const override { return "svg"; }
		void WriteTo(std::ostream& Target) override
		{
			Target << "<svg xmlns=\"http://www.w3.org/2000/svg\"" << std::endl;
			Target << "xmlns:xlink=\"http://www.w3.org/1999/xlink\"" << std::endl;
			Target << "width=\"" << getWidth() << "px\"" << std::endl;
			Target << "height=\"" << getHeight() << "px\" >" << std::endl;
			for (auto ptr : paths)
			{
				Target << *ptr << std::endl;
			}
			Target << "</svg>" << std::endl;
		}

	private:
		double width, height;
		std::vector<std::shared_ptr<SvgVectorPath>> paths;
	};
}

