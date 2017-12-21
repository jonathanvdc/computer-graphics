#pragma once
#include <memory>
#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines an opacity mask brush: a brush that applies an
    /// opacity mask brush to another brush, returning colors whose
    /// alpha channels correspond to the opacity mask's pixel's
    /// grayscale, and RGB channels that equal the base brush's
    /// pixel's RGB channels.
    /// \remark The resulting alpha channel for a pixel is:
    /// MaskPixel.XYZ.Length / sqrt(3)
    struct OpacityMask : public virtual IBrush3
    {
        /// \brief Creates a new opacity mask brush based on the given base
        /// brush and mask brush.
        OpacityMask(std::shared_ptr<IBrush3> Brush, std::shared_ptr<IBrush3> Mask);

        /// \brief Gets the brush's color at the given position, encoded as a
        /// three-dimensional double-precision vector.
        Vector4 GetColor(Vector3 Position) override;

        /// \brief The base brush that is "masked" by the mask brush.
        std::shared_ptr<IBrush3> Brush;
        /// \brief The mask brush that "masks" the base brush.
        std::shared_ptr<IBrush3> Mask;
    };
}