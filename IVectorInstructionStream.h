#pragma once
#include "Vector2.h"

namespace Engine
{
    /// \brief Defines a stream that accepts vector path instructions.
    struct IVectorInstructionStream
    {
        /// \brief Emits a command that closes the path.
        virtual void WriteClosePath() = 0;

        /// \brief Emits a command that draws a cubic bezier curve.
        virtual void WriteCubicBezier(Vector2 Control1, Vector2 Control2, Vector2 Target) = 0;

        /// \brief Emits a command that draws a line to the given point.
        virtual void WriteLine(Vector2 Target) = 0;

        /// \brief Emits a command that moves the vector graphic to the given
        /// point.
        virtual void WriteMoveTo(Vector2 Target) = 0;
    };
}