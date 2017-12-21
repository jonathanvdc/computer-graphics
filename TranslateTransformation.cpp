#include "TranslateTransformation.h"

#include <memory>
#include "ITransformation.h"
#include "Vector2.h"

using namespace Engine;

TranslateTransformation::TranslateTransformation(Vector2 Offset)
    : Offset(Offset)
{ }

/// \brief Inverts this transformation.
std::shared_ptr<ITransformation<Vector2>> TranslateTransformation::Invert() const
{
    return std::make_shared<TranslateTransformation>(this->Offset * -1.0);
}

/// \brief Applies this transformation to the given value.
Vector2 TranslateTransformation::Transform(Vector2 Value) const
{
    return Value + this->Offset;
}