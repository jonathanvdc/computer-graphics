#pragma once
#include "Vector2.h"
#include "Vector4.h"
#include "IBrush.h"
#include <cstdlib>

namespace Engine
{
	class RandomBrush : public IBrush
	{
		Vector4 GetColor(PixelPosition Position) override
		{
			return Vector4((rand() % 256) / 255.0, (rand() % 256) / 255.0, (rand() % 256) / 255.0, 1.0);
		}
	};
}

