#pragma once
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a common functionality for brushes that can be
    /// applied to three-dimensional meshes.
    struct IBrush3
    {
        /// \brief Gets the brush's color at the given position, encoded as a
        /// three-dimensional double-precision vector.
        virtual Vector4 GetColor(Vector3 Position) = 0;
    };
}