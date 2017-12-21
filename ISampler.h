#pragma once
#include <memory>
#include "IBitmap.h"
#include "Vector2.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a common interface for samplers, which are objects
    /// that read and manipulate colors from a bitmap.
    struct ISampler
    {
        /// \brief Gets or approximates the color at the given (u, v)
        /// coordinates in the bitmap.
        virtual Vector4 GetColor(std::shared_ptr<IBitmap> Bitmap, Vector2 UV) const = 0;
    };
}