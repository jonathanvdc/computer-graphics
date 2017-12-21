#pragma once
#include <memory>
#include <string>
#include <iostream>
#include "EasyBitmap.h"
#include "IShape.h"
#include "lparser.h"
#include "RenderHandler.h"
#include "NormalizedShape.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Helpers.h"
#include "SolidColorBrush.h"
#include "TurtlePath.h"
#include "SvgRenderTarget.h"
#include "ScaleTransformation.h"
#include "TranslateTransformation.h"

class LSystem2DHandler : public RenderHandlerBase
{
public:
	void DrawCharacter(Engine::TurtlePath& Path, LParser::LSystem2D& LSys, char Value, int RecursionLevel)
	{
		if (Value == '(')
		{
			Path.PushState();
		}
		else if (Value == ')')
		{
			Path.PopState();
		}
		else if (Value == '+')
		{
			Path.TurnLeft(ToRadians(LSys.get_angle()));
		}
		else if (Value == '-')
		{
			Path.TurnRight(ToRadians(LSys.get_angle()));
		}
		else if (RecursionLevel == 0)
		{
			if (LSys.draw(Value))
			{
				Path.StartDrawing();
			}
			else
			{
				Path.StopDrawing();
			}
			Path.MoveForward(Value);
		}
		else
		{
			for (char item : LSys.get_replacement(Value))
			{
				DrawCharacter(Path, LSys, item, RecursionLevel - 1);
			}
		}
	}

	std::shared_ptr<Engine::IShape> CreateShape(std::string Path)
	{
		LParser::LSystem2D lsys;

		std::ifstream fin(Path);
		fin >> lsys;
		fin.close();

		Engine::TurtlePath tPath(Engine::Vector2(), ToRadians(lsys.get_starting_angle()));

		for (char item : lsys.get_initiator())
		{
			DrawCharacter(tPath, lsys, item, lsys.get_nr_iterations());
		}
	    
		return tPath.ToShape();
	}

	std::shared_ptr<Engine::IOutputImage> Render(const ini::Configuration& Configuration)
	{
		Engine::Vector4 fgColor(GetValue<Engine::Vector3>(Configuration["2DLSystem"]["color"], Engine::Vector3(0, 0, 1)), 1);

		auto shape = CreateShape(Configuration["2DLSystem"]["inputfile"].as_string_or_die());

		auto fgBrush = std::make_shared<Engine::SolidColorBrush>(fgColor);

		return CreateRelativeImage(Configuration, shape, fgBrush, false);
	}
};