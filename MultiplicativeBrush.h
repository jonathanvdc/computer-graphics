#pragma once
#include <memory>
#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a brush which performs multiplicative blending:
    /// the top brush's colors are multiplied with the bottom
    /// brush's colors. The resulting alpha channel is equal to the
    /// product of the top brush's alpha channel and the bottom
    /// brush's alpha channel.
    struct MultiplicativeBrush : public virtual IBrush3
    {
        /// \brief Creates a new multiplicative brush from the given top and
        /// bottom brush.
        MultiplicativeBrush(std::shared_ptr<IBrush3> Top, std::shared_ptr<IBrush3> Bottom);

        /// \brief Gets the brush's color at the given position, encoded as a
        /// three-dimensional double-precision vector.
        Vector4 GetColor(Vector3 Position) override;

        /// \brief The multiplicative brush's "bottom" brush.
        /// \remark The difference between the "top" and "bottom" brush is
        /// rather insignificant here due to the commutativity of
        /// multiplication.
        std::shared_ptr<IBrush3> Bottom;
        /// \brief The multiplicative brush's "top" brush.
        /// \remark The difference between the "top" and "bottom" brush is
        /// rather insignificant here due to the commutativity of
        /// multiplication.
        std::shared_ptr<IBrush3> Top;
    };
}