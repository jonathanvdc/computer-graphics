#pragma once
#include <memory>
#include "ICommand.h"
#include "IVectorInstructionStream.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief A command that draws a line between two points.
    class WriteLineSegmentCommand : public virtual ICommand<std::shared_ptr<IVectorInstructionStream>>
    {
    public:
        WriteLineSegmentCommand(Vector2 StartPoint, Vector2 EndPoint);

        /// \brief Executes the command on the given target.
        void Execute(std::shared_ptr<IVectorInstructionStream> Stream) override;

        /// \brief Gets the line segment's end position.
        Vector2 getEndPoint() const;

        /// \brief Gets the line segment's start position.
        Vector2 getStartPoint() const;
    private:
        /// \brief Sets the line segment's end position.
        void setEndPoint(Vector2 value);

        /// \brief Sets the line segment's start position.
        void setStartPoint(Vector2 value);

        Vector2 EndPoint_value;
        Vector2 StartPoint_value;
    };
}