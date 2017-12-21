#pragma once
#include <memory>
#include <ostream>
#include "IBrush.h"

namespace Engine
{
	std::ostream& WriteSvgBrush(std::ostream& Target, std::string Name, std::shared_ptr<IBrush> Brush, PixelPosition Position);
	std::ostream& WriteSvgColor(std::ostream& Target, Vector4 Value);
}

