#pragma once
#include <memory>

namespace Engine
{
    /// \brief Defines a simple transformation interface.
    template<typename T>
    struct ITransformation
    {
        /// \brief Inverts this transformation.
        virtual std::shared_ptr<ITransformation<T>> Invert() const = 0;

        /// \brief Applies this transformation to the given value.
        virtual T Transform(T Value) const = 0;
    };
}