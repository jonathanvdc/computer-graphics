#include "EmptyTransformation.h"

#include <memory>
#include "ITransformation.h"

using namespace Engine;

template<typename T>
EmptyTransformation<T>::EmptyTransformation()
{ }

/// \brief Inverts this transformation.
template<typename T>
std::shared_ptr<ITransformation<T>> EmptyTransformation<T>::Invert() const
{
    return std::make_shared<EmptyTransformation<T>>();
}

/// \brief Applies this transformation to the given value.
template<typename T>
T EmptyTransformation<T>::Transform(T Value) const
{
    return Value;
}