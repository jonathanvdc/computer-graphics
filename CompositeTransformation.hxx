#include "CompositeTransformation.h"

#include <memory>
#include "ITransformation.h"

using namespace Engine;

/// \brief Creates a new composite transformation from the given
/// transformations.
template<typename T>
CompositeTransformation<T>::CompositeTransformation(std::shared_ptr<ITransformation<T>> First, std::shared_ptr<ITransformation<T>> Second)
    : First(First), Second(Second)
{ }

/// \brief Inverts this transformation.
template<typename T>
std::shared_ptr<ITransformation<T>> CompositeTransformation<T>::Invert() const
{
    return std::make_shared<CompositeTransformation<T>>(this->Second->Invert(), 
                                                        this->First->Invert());
}

/// \brief Applies this transformation to the given value.
template<typename T>
T CompositeTransformation<T>::Transform(T Value) const
{
    return this->Second->Transform(this->First->Transform(Value));
}