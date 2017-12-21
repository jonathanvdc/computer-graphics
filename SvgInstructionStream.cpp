#include "SvgInstructionStream.h"

namespace Engine
{
	std::ostream& operator<<(std::ostream& Target, SvgInstructionStream& Stream)
	{
		return Target << Stream.results.str();
	}
}