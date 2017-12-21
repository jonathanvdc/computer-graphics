#pragma once
#include "PixelPosition.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Describes a brush: a mechanism for applying color to a
    /// surface.
    struct IBrush
    {
        /// \brief Gets the brush's color at the given position.
        virtual Vector4 GetColor(PixelPosition Position) = 0;
    };
}