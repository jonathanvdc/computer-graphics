#pragma once
#include <string>
#include <vector>
#include "EasyImage.h"
#include "RenderHandler.h"
#include "Helpers.h"
#include "EasyBitmap.h"

class BlocksHandler : public RenderHandlerBase
{
public:
	std::shared_ptr<Engine::IOutputImage> Render(const ini::Configuration& Configuration) override
	{
		auto image = CreateImageFromSpecification(Configuration);

		img::Color whiteColor = GetValue(Configuration["BlockProperties"]["colorWhite"], img::Color(255, 255, 255));
		img::Color blackColor = GetValue(Configuration["BlockProperties"]["colorBlack"], img::Color(0, 0, 0));
		unsigned int nrXBlocks = GetValue<unsigned int>(Configuration["BlockProperties"]["nrXBlocks"], 4);
		unsigned int nrYBlocks = GetValue<unsigned int>(Configuration["BlockProperties"]["nrYBlocks"], 4);
		bool invertColors = GetValue<bool>(Configuration["BlockProperties"]["invertColors"], false);

		if (invertColors)
		{
			std::swap(whiteColor, blackColor);
		}

		unsigned int blockWidth = image.get_width() / nrXBlocks;
		unsigned int blockHeight = image.get_height() / nrYBlocks;

		for (unsigned int i = 0; i < image.get_width(); i++)
		{
			for (unsigned int j = 0; j < image.get_height(); j++)
			{
				unsigned int blockX = i / blockWidth;
				unsigned int blockY = j / blockHeight;
				image(i, j) = (blockX + blockY) % 2 == 0 ? whiteColor : blackColor;
			}
		}

		return std::make_shared<Engine::EasyBitmap>(image);
	}
};