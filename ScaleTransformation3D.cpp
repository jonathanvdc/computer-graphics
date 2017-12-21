#include "ScaleTransformation3D.h"

#include <memory>
#include "ITransformation.h"
#include "Vector3.h"

using namespace Engine;

ScaleTransformation3D::ScaleTransformation3D(Vector3 Scale)
    : Scale(Scale)
{ }

/// \brief Inverts this transformation.
std::shared_ptr<ITransformation<Vector3>> ScaleTransformation3D::Invert() const
{
    return std::make_shared<ScaleTransformation3D>(Vector3(1.0 / this->Scale.X, 1.0 / this->Scale.Y, 
                                                           1.0 / this->Scale.Z));
}

/// \brief Applies this transformation to the given value.
Vector3 ScaleTransformation3D::Transform(Vector3 Value) const
{
    return Vector3(Value.X * this->Scale.X, Value.Y * this->Scale.Y, 
                   Value.Z * this->Scale.Z);
}