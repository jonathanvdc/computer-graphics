#pragma once
#include <string>
#include "IVectorInstructionStream.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief A base implementation for IVectorInstructionStream.
    class VectorInstructionStreamBase : public virtual IVectorInstructionStream
    {
    public:
        /// \brief Creates a new vector instruction stream.
        VectorInstructionStreamBase();

        /// \brief Emits a command that closes the path.
        void WriteClosePath() override;

        /// \brief Emits a command that draws a cubic bezier curve.
        void WriteCubicBezier(Vector2 Control1, Vector2 Control2, Vector2 Target) override;

        /// \brief Emits a command that draws a line to the given point.
        void WriteLine(Vector2 Target) override;

        /// \brief Emits a command that moves the vector graphic to the given
        /// point.
        void WriteMoveTo(Vector2 Target) override;
    protected:
        /// \brief Writes a string to the stream.
        virtual void Write(std::string Value) = 0;

        /// \brief Writes a double to the stream.
        virtual void Write(double Value);

        /// \brief Writes a two-dimensional vector to the stream.
        virtual void Write(Vector2 Value);

        /// \brief Writes an instruction type to the stream.
        void WriteInstructionType(std::string Type);

        /// \brief Writes a point, updating the current position.
        void WritePoint(Vector2 Value);
    private:
        std::string lastInstrType;
        Vector2 lastPosition;
    };
}