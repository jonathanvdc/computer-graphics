#pragma once
#include <ostream>
#include <memory>
#include <string>
#include "ISurface.h"

namespace Engine
{
	struct IOutputImage : public virtual ISurface
	{
		virtual std::string GetExtension() const = 0;
		virtual void WriteTo(std::ostream& Target) = 0;
	};

	std::ostream& operator<<(std::ostream& Target, IOutputImage& Image);
	std::ostream& operator<<(std::ostream& Target, std::shared_ptr<IOutputImage> Image);
}