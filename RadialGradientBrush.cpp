#include "RadialGradientBrush.h"

#include "IBrush.h"
#include "PixelPosition.h"
#include "Vector2.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new radial color brush based on the given
/// arguments.
RadialGradientBrush::RadialGradientBrush(Vector2 Center, double Radius, Vector4 ColorStart, Vector4 ColorEnd)
{
    this->setCenter(Center);
    this->setRadius(Radius);
    this->setColorStart(ColorStart);
    this->setColorEnd(ColorEnd);
}

/// \brief Gets the brush's color at the given position.
Vector4 RadialGradientBrush::GetColor(PixelPosition Position)
{
    auto offset = Position.RelativePosition - this->getCenter();
    double dist = offset.getLength();
    if (dist < this->getRadius())
    {
        double relDist = dist / this->getRadius();
        return this->getColorStart() * (1.0 - relDist) + 
               this->getColorEnd() * relDist;
    }
    else
    {
        return this->getColorEnd();
    }
}

/// \brief Gets the radial gradient's center.
Vector2 RadialGradientBrush::getCenter() const
{
    return this->Center_value;
}

/// \brief Sets the radial gradient's center.
void RadialGradientBrush::setCenter(Vector2 value)
{
    this->Center_value = value;
}

/// \brief Gets the brush's end color.
Vector4 RadialGradientBrush::getColorEnd() const
{
    return this->ColorEnd_value;
}

/// \brief Sets the brush's end color.
void RadialGradientBrush::setColorEnd(Vector4 value)
{
    this->ColorEnd_value = value;
}

/// \brief Gets the brush's start color.
Vector4 RadialGradientBrush::getColorStart() const
{
    return this->ColorStart_value;
}

/// \brief Sets the brush's start color.
void RadialGradientBrush::setColorStart(Vector4 value)
{
    this->ColorStart_value = value;
}

/// \brief Gets the radial gradient's radius.
double RadialGradientBrush::getRadius() const
{
    return this->Radius_value;
}

/// \brief Sets the radial gradient's radius.
void RadialGradientBrush::setRadius(double value)
{
    this->Radius_value = value;
}