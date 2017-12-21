#pragma once
#include <memory>
#include "ITransformation.h"

namespace Engine
{
    /// \brief Defines a transformation that is the composition of two
    /// transformations.
    template<typename T>
    struct CompositeTransformation : public virtual ITransformation<T>
    {
        /// \brief Creates a new composite transformation from the given
        /// transformations.
        CompositeTransformation(std::shared_ptr<ITransformation<T>> First, std::shared_ptr<ITransformation<T>> Second);

        /// \brief Inverts this transformation.
        std::shared_ptr<ITransformation<T>> Invert() const override;

        /// \brief Applies this transformation to the given value.
        T Transform(T Value) const override;

        /// \brief The first transformation to apply.
        std::shared_ptr<ITransformation<T>> First;
        /// \brief The second transformation to apply.
        std::shared_ptr<ITransformation<T>> Second;
    };
}

#include "CompositeTransformation.hxx"