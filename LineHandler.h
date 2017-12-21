#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "EasyImage.h"
#include "EasyBitmap.h"
#include "RenderHandler.h"
#include "Helpers.h"
#include "Vector4.h"
#include "SolidColorBrush.h"
#include "RadialGradientBrush.h"
#include "RandomBrush.h"
#include "MultiLine.h"
#include "NormalizedShape.h"

class LineHandler : public RenderHandlerBase
{
public:
	std::shared_ptr<Engine::IOutputImage> Render(const ini::Configuration& Configuration) override
	{
		auto brush = std::make_shared<Engine::RadialGradientBrush>(Engine::Vector2(0, 0), 1, Engine::Vector4(1, 0, 0, 1), Engine::Vector4(0.5, 0.5, 0.0, 1));

		Engine::Vector2 origin(-200, 200);
		int maxWidth = 5000;
		int maxHeight = 5000;

		stdx::ArraySlice<Engine::Vector2> points(2);
		for (int i = 0; i < points.GetLength(); i++)
		{
			points[i] = Engine::Vector2(std::rand() % (maxWidth - 1), std::rand() % (maxHeight - 1)) + origin;
		}

		auto shape = std::make_shared<Engine::MultiLine>(points);
		return CreateRelativeImage(Configuration, shape, brush, false);
	}
};