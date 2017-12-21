#pragma once
#include <memory>
#include "ICommand.h"
#include "IVectorInstructionStream.h"

namespace Engine
{
    /// \brief Provides a common interface for segments that can
    /// translate themselves to vector drawing instructions.
    struct IVectorSegment
    {
        /// \brief Gets a command that writes the vector segment's data to a
        /// vector instruction stream.
        virtual std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> Write() = 0;
    };
}