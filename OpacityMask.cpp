#include "OpacityMask.h"

#include <cmath>
#include <memory>
#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new opacity mask brush based on the given base
/// brush and mask brush.
OpacityMask::OpacityMask(std::shared_ptr<IBrush3> Brush, std::shared_ptr<IBrush3> Mask)
    : Brush(Brush), Mask(Mask)
{ }

/// \brief Gets the brush's color at the given position, encoded as a
/// three-dimensional double-precision vector.
Vector4 OpacityMask::GetColor(Vector3 Position)
{
    auto opacityMask = this->Mask->GetColor(Position);
    auto rgb = opacityMask.getXYZ();
    double intensity = rgb.getLength() / std::sqrt(3.0);
    auto brushColor = this->Brush->GetColor(Position);
    return Vector4(brushColor.getXYZ(), brushColor.W * intensity);
}