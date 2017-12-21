#include <memory>
#include <sstream>
#include "IBrush.h"
#include "SvgHelpers.h"
#include "PixelPosition.h"

#ifdef _MSC_VER
#define sprintf sprintf_s
#endif

namespace Engine
{
	void WriteHex(std::ostream& Target, uint8_t Value)
	{
		char buf[3];
		sprintf(buf, "%02X", Value);
		Target << buf;
	}

	std::ostream& WriteSvgColor(std::ostream& Target, Vector4 Value)
	{
		Target << '#';
		WriteHex(Target, (uint8_t)(Value.X * 255));
		WriteHex(Target, (uint8_t)(Value.Y * 255));
		WriteHex(Target, (uint8_t)(Value.Z * 255));
		return Target;
	}

	std::ostream& WriteSvgBrush(std::ostream& Target, std::string Name, std::shared_ptr<IBrush> Brush, PixelPosition Position)
	{
		Vector4 sample = Brush->GetColor(Position);

		Target << Name << ":";
		if (sample.W == 0.0)
		{
			Target << "none";
		}
		else
		{
			WriteSvgColor(Target, sample);
		}
		Target << ";";
		if (sample.W > 0.0 && sample.W < 1.0)
		{
			Target << " " << Name << "-opacity:";
			Target << sample.W << ";";
		}
		return Target;
	}
}
