#pragma once
#include <ostream>
#include <string>
#include <sstream>
#include "VectorPathBase.h"
#include "SvgInstructionStream.h"
#include "SvgHelpers.h"

namespace Engine
{
	/// \brief Defines a mutable SVG vector path.
	class SvgVectorPath : public VectorPathBase
	{
	public:
		/// \brief Creates a new SVG path from the given image dimensions.
		SvgVectorPath(double Width, double Height) : VectorPathBase() { this->instrStream = std::make_shared<SvgInstructionStream>(Width, Height); }

		/// \brief Gets the vector path's instruction stream.
		std::shared_ptr<IVectorInstructionStream> GetInstructionStream() override { return instrStream; }

		/// \brief Writes the SVG vector path to the given output stream.
		friend std::ostream& operator<<(std::ostream& Target, SvgVectorPath& Path);

	private:
		std::shared_ptr<SvgInstructionStream> instrStream;
	};

	/// \brief Writes the SVG vector path to the given output stream.
	std::ostream& operator<<(std::ostream& Target, SvgVectorPath& Path);
}