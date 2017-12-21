#include "ScaleTransformation.h"

#include <memory>
#include "ITransformation.h"
#include "Vector2.h"

using namespace Engine;

ScaleTransformation::ScaleTransformation(Vector2 Scale)
    : Scale(Scale)
{ }

/// \brief Inverts this transformation.
std::shared_ptr<ITransformation<Vector2>> ScaleTransformation::Invert() const
{
    return std::make_shared<ScaleTransformation>(Vector2(1.0 / this->Scale.X, 1.0 / this->Scale.Y));
}

/// \brief Applies this transformation to the given value.
Vector2 ScaleTransformation::Transform(Vector2 Value) const
{
    return Vector2(Value.X * this->Scale.X, Value.Y * this->Scale.Y);
}