#include "SolidColorBrush.h"

#include "IBrush.h"
#include "PixelPosition.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new solid color brush that is fully transparent.
SolidColorBrush::SolidColorBrush()
{
    this->setColor(Vector4(1.0, 1.0, 1.0, 0.0));
}

/// \brief Creates a new solid color brush based on the given color.
SolidColorBrush::SolidColorBrush(Vector4 Color)
{
    this->setColor(Color);
}

/// \brief Gets the brush's color at the given position.
Vector4 SolidColorBrush::GetColor(PixelPosition Position)
{
    return this->getColor();
}

/// \brief Sets the brush's color.
void SolidColorBrush::setColor(Vector4 value)
{
    this->Color_value = value;
}

/// \brief Gets the brush's color.
Vector4 SolidColorBrush::getColor() const
{
    return this->Color_value;
}