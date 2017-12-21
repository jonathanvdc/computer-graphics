#include "SvgVectorPath.h"
#include "SvgHelpers.h"

namespace Engine
{
	std::ostream& operator<<(std::ostream& Target, SvgVectorPath& Path)
	{
		Target << "<path style=\"";
		WriteSvgBrush(Target, "stroke", Path.getStroke(), Path.instrStream->GetAveragePosition());
		Target << " stroke-width:" << Path.getStrokeThickness() << ";";
		WriteSvgBrush(Target, "fill", Path.getFill(), Path.instrStream->GetAveragePosition());
		Target << "\" d=\"";
		Target << *Path.instrStream;
		Target << "\" />";
		return Target;
	}
}