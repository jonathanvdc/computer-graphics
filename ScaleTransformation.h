#pragma once
#include <memory>
#include "ITransformation.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief A two-dimensional scaling transformation.
    struct ScaleTransformation : public virtual ITransformation<Vector2>
    {
        ScaleTransformation(Vector2 Scale);

        /// \brief Inverts this transformation.
        std::shared_ptr<ITransformation<Vector2>> Invert() const override;

        /// \brief Applies this transformation to the given value.
        Vector2 Transform(Vector2 Value) const override;

        /// \brief The scaling vector for this scaling transformation.
        Vector2 Scale;
    };
}