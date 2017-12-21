#pragma once
#include <memory>
#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a brush that performs additive blending, i.e.
    /// color addition, of two other brushes.
    /// The alpha channel of the resulting color is the sum of the
    /// top and bottom brush's colors.
    struct AdditiveBrush : public virtual IBrush3
    {
        /// \brief Creates an additive blending brush from the given operand
        /// brushes.
        AdditiveBrush(std::shared_ptr<IBrush3> Top, std::shared_ptr<IBrush3> Bottom);

        /// \brief Gets the brush's color at the given position, encoded as a
        /// three-dimensional double-precision vector.
        Vector4 GetColor(Vector3 Position) override;

        /// \brief The additive brush's "bottom" brush.
        /// \remark The difference between the "top" and "bottom" brush is
        /// rather insignificant here due to the commutativity of
        /// addition.
        std::shared_ptr<IBrush3> Bottom;
        /// \brief The additive brush's "top" brush.
        /// \remark The difference between the "top" and "bottom" brush is
        /// rather insignificant here due to the commutativity of
        /// addition.
        std::shared_ptr<IBrush3> Top;
    };
}