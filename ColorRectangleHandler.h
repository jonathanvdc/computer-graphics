#pragma once
#include "RenderHandler.h"
#include "Helpers.h"
#include "IOutputImage.h"
#include "EasyBitmap.h"

class ColorRectangleHandler : public RenderHandlerBase
{
public:
	std::shared_ptr<Engine::IOutputImage> Render(const ini::Configuration& Configuration) override
	{
		img::EasyImage image = CreateImageFromSpecification(Configuration);

		for (unsigned int i = 0; i < image.get_width(); i++)
		{
			for (unsigned int j = 0; j < image.get_height(); j++)
			{
				image(i, j).red = i;
				image(i, j).green = j;
				image(i, j).blue = (i + j) % 256;
			}
		}

		return std::make_shared<Engine::EasyBitmap>(image);
	}
};