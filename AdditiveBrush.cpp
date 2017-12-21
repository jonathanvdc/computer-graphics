#include "AdditiveBrush.h"

#include <memory>
#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates an additive blending brush from the given operand
/// brushes.
AdditiveBrush::AdditiveBrush(std::shared_ptr<IBrush3> Top, std::shared_ptr<IBrush3> Bottom)
    : Top(Top), Bottom(Bottom)
{ }

/// \brief Gets the brush's color at the given position, encoded as a
/// three-dimensional double-precision vector.
Vector4 AdditiveBrush::GetColor(Vector3 Position)
{
    auto topColor = this->Top->GetColor(Position);
    auto bottomColor = this->Bottom->GetColor(Position);
    auto result = topColor + bottomColor;
    return result.Clamp(Vector4(0.0), Vector4(1.0));
}