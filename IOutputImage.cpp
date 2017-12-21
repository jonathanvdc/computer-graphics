#include <ostream>
#include <memory>
#include <string>
#include "ISurface.h"
#include "IOutputImage.h"

namespace Engine
{
	std::ostream& operator<<(std::ostream& Target, IOutputImage& Image)
	{
		Image.WriteTo(Target);
		return Target;
	}
	std::ostream& operator<<(std::ostream& Target, std::shared_ptr<IOutputImage> Image)
	{
		return Target << *Image;
	}
}