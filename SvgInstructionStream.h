#pragma once
#include <ostream>
#include <string>
#include <sstream>
#include "IVectorInstructionStream.h"
#include "VectorInstructionStreamBase.h"
#include "PixelPosition.h"

namespace Engine
{
	class SvgInstructionStream : public VectorInstructionStreamBase
	{
	public:
		SvgInstructionStream(double Width, double Height) : width(Width), height(Height), ptCount(0), ptSum() { }

		void Write(std::string Value) override { results << Value; }
		void Write(double Value) override { results << Value; }
		void Write(Vector2 Value) override { ptSum += Value; ptCount++; Write(Value.X); Write(", "); Write(this->height - Value.Y); }

		Vector2 GetAveragePoint() const { return ptSum / ptCount; }
		PixelPosition GetAveragePosition() const { auto avg = GetAveragePoint(); return PixelPosition((int)(avg.X * width), (int)(avg.Y * height), avg); }

		friend std::ostream& operator<<(std::ostream& Target, SvgInstructionStream& Stream);
	private:
		std::ostringstream results;
		double width, height;
		int ptCount;
		Vector2 ptSum;
	};

	std::ostream& operator<<(std::ostream& Target, SvgInstructionStream& Stream);
}