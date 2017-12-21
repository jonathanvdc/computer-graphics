#include "PixelPosition.h"

#include "Contracts.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a pixel position at the origin.
PixelPosition::PixelPosition()
    : X(0), Y(0), RelativePosition()
{ }

/// \brief Creates a new pixel position from the given arguments.
PixelPosition::PixelPosition(int X, int Y)
    : X(X), Y(Y), RelativePosition()
{ }

/// \brief Creates a new pixel position from the given arguments.
/// \pre require(RelativePosition.X >= 0.0 && RelativePosition.X <= 1.0);
/// \pre require(RelativePosition.Y >= 0.0 && RelativePosition.Y <= 1.0);
PixelPosition::PixelPosition(int X, int Y, Vector2 RelativePosition)
    : X(X), Y(Y), RelativePosition(RelativePosition)
{
    require(RelativePosition.X >= 0.0 && RelativePosition.X <= 1.0);
    require(RelativePosition.Y >= 0.0 && RelativePosition.Y <= 1.0);
}

/// \brief Gets the pixel position's absolute position.
Vector2 PixelPosition::getAbsolutePosition() const
{
    return Vector2((double)this->X, (double)this->Y);
}