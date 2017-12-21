#include "SubtractBrush.h"

#include <memory>
#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new subtracting brush instance from the top and
/// bottom brush.
SubtractBrush::SubtractBrush(std::shared_ptr<IBrush3> Top, std::shared_ptr<IBrush3> Bottom)
    : Top(Top), Bottom(Bottom)
{ }

/// \brief Gets the brush's color at the given position, encoded as a
/// three-dimensional double-precision vector.
Vector4 SubtractBrush::GetColor(Vector3 Position)
{
    auto topColor = this->Top->GetColor(Position);
    auto bottomColor = this->Bottom->GetColor(Position);
    Vector4 result(topColor.getXYZ() - bottomColor.getXYZ(), 
                   topColor.W);
    return result.Clamp(Vector4(0.0), Vector4(1.0));
}