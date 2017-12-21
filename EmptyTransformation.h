#pragma once
#include <memory>
#include "ITransformation.h"

namespace Engine
{
    /// \brief An empty transformation.
    template<typename T>
    struct EmptyTransformation : public virtual ITransformation<T>
    {
        EmptyTransformation();

        /// \brief Inverts this transformation.
        std::shared_ptr<ITransformation<T>> Invert() const override;

        /// \brief Applies this transformation to the given value.
        T Transform(T Value) const override;
    };
}

#include "EmptyTransformation.hxx"