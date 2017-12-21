#pragma once
#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Describes a three-dimensional solid color brush, which
    /// always returns the same color, regardless of the point it
    /// is applied to.
    struct SolidColorBrush3 : public virtual IBrush3
    {
        /// \brief Creates a new solid color brush from the given color.
        SolidColorBrush3(Vector4 Color);

        /// \brief Gets the brush's color at the given position, encoded as a
        /// three-dimensional double-precision vector.
        Vector4 GetColor(Vector3 Position) override;

        /// \brief The solid color brush's color.
        Vector4 Color;
    };
}