#pragma once
#include "Vector2.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines common functionality for projections.
    struct IProjection
    {
        /// \brief Projects the two-dimensional vector onto a two-dimensional
        /// plane.
        virtual Vector2 Project(Vector3 Value) const = 0;
    };
}