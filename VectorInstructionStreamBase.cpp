#include "VectorInstructionStreamBase.h"

#include <string>
#include "IVectorInstructionStream.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a new vector instruction stream.
VectorInstructionStreamBase::VectorInstructionStreamBase()
    : lastPosition(), lastInstrType("")
{ }

/// \brief Writes a double to the stream.
void VectorInstructionStreamBase::Write(double Value)
{
    this->Write(" " + std::to_string(Value));
}

/// \brief Writes a two-dimensional vector to the stream.
void VectorInstructionStreamBase::Write(Vector2 Value)
{
    this->Write(Value.X);
    this->Write(",");
    this->Write(Value.Y);
}

/// \brief Emits a command that closes the path.
void VectorInstructionStreamBase::WriteClosePath()
{
    this->WriteInstructionType("Z");
}

/// \brief Emits a command that draws a cubic bezier curve.
void VectorInstructionStreamBase::WriteCubicBezier(Vector2 Control1, Vector2 Control2, Vector2 Target)
{
    if (this->lastPosition != Target)
    {
        this->WriteInstructionType("C");
        this->Write(Control1);
        this->Write(Control2);
        this->WritePoint(Target);
    }
}

/// \brief Writes an instruction type to the stream.
void VectorInstructionStreamBase::WriteInstructionType(std::string Type)
{
    if (this->lastInstrType != "")
        this->Write(" ");

    if (Type != this->lastInstrType)
    {
        this->Write(Type);
        this->lastInstrType = Type;
    }
}

/// \brief Emits a command that draws a line to the given point.
void VectorInstructionStreamBase::WriteLine(Vector2 Target)
{
    if (this->lastPosition != Target)
    {
        this->WriteInstructionType("L");
        this->WritePoint(Target);
    }
}

/// \brief Emits a command that moves the vector graphic to the given
/// point.
void VectorInstructionStreamBase::WriteMoveTo(Vector2 Target)
{
    if (this->lastPosition != Target)
    {
        this->WriteInstructionType("M");
        this->WritePoint(Target);
    }
}

/// \brief Writes a point, updating the current position.
void VectorInstructionStreamBase::WritePoint(Vector2 Value)
{
    this->Write(Value);
    this->lastPosition = Value;
}