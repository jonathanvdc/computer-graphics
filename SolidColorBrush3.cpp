#include "SolidColorBrush3.h"

#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new solid color brush from the given color.
SolidColorBrush3::SolidColorBrush3(Vector4 Color)
    : Color(Color)
{ }

/// \brief Gets the brush's color at the given position, encoded as a
/// three-dimensional double-precision vector.
Vector4 SolidColorBrush3::GetColor(Vector3 Position)
{
    return this->Color;
}