#include "MultiplicativeBrush.h"

#include <memory>
#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new multiplicative brush from the given top and
/// bottom brush.
MultiplicativeBrush::MultiplicativeBrush(std::shared_ptr<IBrush3> Top, std::shared_ptr<IBrush3> Bottom)
    : Top(Top), Bottom(Bottom)
{ }

/// \brief Gets the brush's color at the given position, encoded as a
/// three-dimensional double-precision vector.
Vector4 MultiplicativeBrush::GetColor(Vector3 Position)
{
    auto topColor = this->Top->GetColor(Position);
    auto bottomColor = this->Bottom->GetColor(Position);
    return topColor.Scale(bottomColor);
}