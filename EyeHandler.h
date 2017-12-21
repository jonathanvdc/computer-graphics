#pragma once
#include "RenderHandler.h"
#include "Helpers.h"

class EyeHandler : public RenderHandlerBase
{
public:
	void RenderQuarterCircle(img::EasyImage& Image, const ini::Configuration& Configuration)
	{
		unsigned int nrLines = GetValue<unsigned int>(Configuration["LineProperties"]["nrLines"], 5);

		auto lineColor = GetValue<img::Color>(Configuration["LineProperties"]["lineColor"], { 255, 255, 255 });

		unsigned int lineDeltaX = Image.get_width() / (nrLines - 1);
		unsigned int lineDeltaY = Image.get_height() / (nrLines - 1);

		for (unsigned int i = 0; i < nrLines; i++)
		{
			Image.draw_line(i * lineDeltaX, 0, Image.get_height() - 1, i * lineDeltaY, lineColor);
		}
	}

	std::shared_ptr<Engine::IOutputImage> Render(const ini::Configuration& Configuration) override
	{
		auto image = CreateImageFromSpecification(Configuration);

		auto bgColor = GetValue(Configuration["LineProperties"]["bgColor"], img::Color(0, 0, 0));

		image.clear(bgColor);

		RenderQuarterCircle(image, Configuration);

		return std::make_shared<Engine::EasyBitmap>(image);
	}
};