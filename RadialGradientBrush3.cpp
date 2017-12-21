#include "RadialGradientBrush3.h"

#include <memory>
#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new radial color brush based on the given
/// arguments.
RadialGradientBrush3::RadialGradientBrush3(Vector3 Center, double Radius, std::shared_ptr<IBrush3> StartBrush, std::shared_ptr<IBrush3> EndBrush)
{
    this->setCenter(Center);
    this->setRadius(Radius);
    this->setStartBrush(StartBrush);
    this->setEndBrush(EndBrush);
}

/// \brief Gets the brush's color at the given position.
Vector4 RadialGradientBrush3::GetColor(Vector3 Position)
{
    auto offset = Position - this->getCenter();
    double dist = offset.getLength();
    if (dist < this->getRadius())
    {
        double relDist = dist / this->getRadius();
        return this->getStartBrush()->GetColor(Position) * (1.0 - relDist) + this->getEndBrush()->GetColor(Position) * relDist;
    }
    else
    {
        return this->getEndBrush()->GetColor(Position);
    }
}

/// \brief Gets the radial gradient's center.
Vector3 RadialGradientBrush3::getCenter() const
{
    return this->Center_value;
}

/// \brief Sets the radial gradient's center.
void RadialGradientBrush3::setCenter(Vector3 value)
{
    this->Center_value = value;
}

/// \brief Gets the radial gradient's end brush.
std::shared_ptr<IBrush3> RadialGradientBrush3::getEndBrush() const
{
    return this->EndBrush_value;
}

/// \brief Sets the radial gradient's end brush.
void RadialGradientBrush3::setEndBrush(std::shared_ptr<IBrush3> value)
{
    this->EndBrush_value = value;
}

/// \brief Gets the radial gradient's radius.
double RadialGradientBrush3::getRadius() const
{
    return this->Radius_value;
}

/// \brief Sets the radial gradient's radius.
void RadialGradientBrush3::setRadius(double value)
{
    this->Radius_value = value;
}

/// \brief Gets the radial gradient's start brush.
std::shared_ptr<IBrush3> RadialGradientBrush3::getStartBrush() const
{
    return this->StartBrush_value;
}

/// \brief Sets the radial gradient's start brush.
void RadialGradientBrush3::setStartBrush(std::shared_ptr<IBrush3> value)
{
    this->StartBrush_value = value;
}