#pragma once
#include <memory>
#include "ITransformation.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief A two-dimensional translation transformation.
    struct TranslateTransformation : public virtual ITransformation<Vector2>
    {
        TranslateTransformation(Vector2 Offset);

        /// \brief Inverts this transformation.
        std::shared_ptr<ITransformation<Vector2>> Invert() const override;

        /// \brief Applies this transformation to the given value.
        Vector2 Transform(Vector2 Value) const override;

        /// \brief The offset for this translation.
        Vector2 Offset;
    };
}