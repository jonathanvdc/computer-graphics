#include "OverBrush.h"

#include <memory>
#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new "over" brush based on the given top and
/// bottom brush.
OverBrush::OverBrush(std::shared_ptr<IBrush3> Top, std::shared_ptr<IBrush3> Bottom)
    : Top(Top), Bottom(Bottom)
{ }

/// \brief Gets the brush's color at the given position, encoded as a
/// three-dimensional double-precision vector.
Vector4 OverBrush::GetColor(Vector3 Position)
{
    auto topColor = this->Top->GetColor(Position);
    auto bottomColor = this->Bottom->GetColor(Position);
    return topColor.Over(bottomColor);
}