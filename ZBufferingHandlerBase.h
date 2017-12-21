#pragma once
#include "RenderHandler.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <exception>
#include "MeshHandlerBase.h"
#include "IOutputImage.h"
#include "IShape.h"
#include "IProjection.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

class ZBufferingHandlerBase : public MeshHandlerBase
{
public:
	virtual bool ShouldFillMesh(const ini::Section& Figure) = 0;
	bool UseZBuffer() override;

	static inline double clamp(double Value, double Min, double Max)
	{
		return std::min<double>(std::max<double>(Value, Min), Max);
	}

	static inline img::Color ToZBufferColor(double Depth, double Min, double Max)
	{
		if (std::isinf(Depth))
		{
			return img::Color(0, 0, 0);
		}

		uint8_t color = (uint8_t)(int)clamp((1.0 - (Depth - Min) / (Max - Min)) * 235.0 + 15.0, 15.0, 240.0);

		return img::Color(color, color, color);
	}

	void OutputZBuffer(std::shared_ptr<Engine::IDepthBuffer> zbuf, std::string Name);

	void OutputZBuffer(const ini::Section& Configuration, std::string Name, std::shared_ptr<Engine::IDepthBuffer> buffer);

	void OutputZBuffer(const ini::Section& Configuration, std::string Name, std::shared_ptr<Engine::IOutputImage> image);

	void OutputZBuffer(const ini::Section& Configuration, std::shared_ptr<Engine::IOutputImage> image);

	virtual std::shared_ptr<Engine::IOutputImage> Render(const ini::Configuration& Configuration) override;
};