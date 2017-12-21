#include "Triangle.h"

#include <memory>
#include "ITransformation.h"

using namespace Engine;

/// \brief Creates a new empty triangle at the origin.
template<typename T>
Triangle<T>::Triangle()
    : A(), B(), C()
{ }

/// \brief Creates a triangle from the given points.
template<typename T>
Triangle<T>::Triangle(T A, T B, T C)
    : A(A), B(B), C(C)
{ }

/// \brief Computes the transformation of this triangle, using the
/// given transform.
template<typename T>
Triangle<T> Triangle<T>::Transform(std::shared_ptr<ITransformation<T>> Transform) const
{
    auto a = Transform->Transform(this->A);
    auto b = Transform->Transform(this->B);
    auto c = Transform->Transform(this->C);
    return Triangle<T>(a, b, c);
}