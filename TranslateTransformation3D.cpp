#include "TranslateTransformation3D.h"

#include <memory>
#include "ITransformation.h"
#include "Vector3.h"

using namespace Engine;

TranslateTransformation3D::TranslateTransformation3D(Vector3 Offset)
    : Offset(Offset)
{ }

/// \brief Inverts this transformation.
std::shared_ptr<ITransformation<Vector3>> TranslateTransformation3D::Invert() const
{
    return std::make_shared<TranslateTransformation3D>(this->Offset * -1.0);
}

/// \brief Applies this transformation to the given value.
Vector3 TranslateTransformation3D::Transform(Vector3 Value) const
{
    return Value + this->Offset;
}