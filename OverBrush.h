#pragma once
#include <memory>
#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a brush that performs "over" alpha blending, which
    /// uses blends two brushes based on their alpha channels.
    struct OverBrush : public virtual IBrush3
    {
        /// \brief Creates a new "over" brush based on the given top and
        /// bottom brush.
        OverBrush(std::shared_ptr<IBrush3> Top, std::shared_ptr<IBrush3> Bottom);

        /// \brief Gets the brush's color at the given position, encoded as a
        /// three-dimensional double-precision vector.
        Vector4 GetColor(Vector3 Position) override;

        /// \brief The "over" brush's "bottom" brush.
        std::shared_ptr<IBrush3> Bottom;
        /// \brief The "over" brush's "top" brush.
        std::shared_ptr<IBrush3> Top;
    };
}