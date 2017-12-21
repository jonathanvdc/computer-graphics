#pragma once
#include "Vector3.h"

namespace Engine
{
    /// \brief Represents a turtle mesh state.
    struct TurtleMeshState
    {
        /// \brief Creates a new turtle mesh state from the default settings.
        TurtleMeshState();
        /// \brief Creates a new turtle mesh state from the given arguments.
        TurtleMeshState(Vector3 Position, Vector3 Direction, Vector3 Left, Vector3 Up);

        /// \brief The turtle mesh's direction vector.
        Vector3 Direction;
        /// \brief The turtle mesh's left vector.
        Vector3 Left;
        /// \brief The turtle mesh's position.
        Vector3 Position;
        /// \brief The turtle mesh's up vector.
        Vector3 Up;
    };
}