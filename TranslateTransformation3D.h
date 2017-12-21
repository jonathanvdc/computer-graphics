#pragma once
#include <memory>
#include "ITransformation.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief A three-dimensional translation transformation.
    struct TranslateTransformation3D : public virtual ITransformation<Vector3>
    {
        TranslateTransformation3D(Vector3 Offset);

        /// \brief Inverts this transformation.
        std::shared_ptr<ITransformation<Vector3>> Invert() const override;

        /// \brief Applies this transformation to the given value.
        Vector3 Transform(Vector3 Value) const override;

        /// \brief The offset for this translation.
        Vector3 Offset;
    };
}