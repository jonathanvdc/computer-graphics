#include "WriteLineSegmentCommand.h"

#include <memory>
#include "ICommand.h"
#include "IVectorInstructionStream.h"
#include "Vector2.h"

using namespace Engine;

WriteLineSegmentCommand::WriteLineSegmentCommand(Vector2 StartPoint, Vector2 EndPoint)
{
    this->setStartPoint(StartPoint);
    this->setEndPoint(EndPoint);
}

/// \brief Executes the command on the given target.
void WriteLineSegmentCommand::Execute(std::shared_ptr<IVectorInstructionStream> Stream)
{
    Stream->WriteMoveTo(this->getStartPoint());
    Stream->WriteLine(this->getEndPoint());
}

/// \brief Sets the line segment's end position.
void WriteLineSegmentCommand::setEndPoint(Vector2 value)
{
    this->EndPoint_value = value;
}

/// \brief Gets the line segment's end position.
Vector2 WriteLineSegmentCommand::getEndPoint() const
{
    return this->EndPoint_value;
}

/// \brief Sets the line segment's start position.
void WriteLineSegmentCommand::setStartPoint(Vector2 value)
{
    this->StartPoint_value = value;
}

/// \brief Gets the line segment's start position.
Vector2 WriteLineSegmentCommand::getStartPoint() const
{
    return this->StartPoint_value;
}