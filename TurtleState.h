#pragma once
#include "Vector2.h"

namespace Engine
{
    /// \brief Represents a turtle path state.
    struct TurtleState
    {
        /// \brief Creates a turtle path state at the origin, with an angle
        /// of zero.
        TurtleState();
        /// \brief Creates a turtle path state from the given position and
        /// angle.
        TurtleState(Vector2 Position, double Angle);

        /// \brief The turtle path state's angle.
        double Angle;
        /// \brief The turtle path state's position.
        Vector2 Position;
    };
}