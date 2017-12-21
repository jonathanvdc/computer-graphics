#pragma once
#include <memory>
#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a subtracting brush, which subtracts the top
    /// brush's colors from the bottom brush's corresponding
    /// colors. The alpha channel of the top brush is preserved.
    /// The bottom brush's alpha channel is discarded.
    /// \remark Discarding the bottom brush's alpha channel may seem like
    /// a strange notion, but it does serve a purpose: subtracting
    /// a yellow solid color brush from a white solid color brush
    /// should intuitively result in a blue brush.
    /// After all: (1.0, 1.0, 1.0) - (1.0, 1.0, 0.0) == (0.0, 0.0,
    /// 1.0). This is indeed the case if the current subtracting
    /// brush model is respected. The more "pure" subtracting brush
    /// model, where the alpha channels are also subtracted,
    /// however, would result in a transparent brush, because (1.0,
    /// 1.0, 1.0, 1.0) - (1.0, 1.0, 0.0, 1.0) == (0.0, 0.0, 1.0,
    /// 0.0), which is a (blue) transparent brush.
    struct SubtractBrush : public virtual IBrush3
    {
        /// \brief Creates a new subtracting brush instance from the top and
        /// bottom brush.
        SubtractBrush(std::shared_ptr<IBrush3> Top, std::shared_ptr<IBrush3> Bottom);

        /// \brief Gets the brush's color at the given position, encoded as a
        /// three-dimensional double-precision vector.
        Vector4 GetColor(Vector3 Position) override;

        /// \brief The subtracting brush's bottom brush.
        std::shared_ptr<IBrush3> Bottom;
        /// \brief The subtracting brush's top brush.
        std::shared_ptr<IBrush3> Top;
    };
}