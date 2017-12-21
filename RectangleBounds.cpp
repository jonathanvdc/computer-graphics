#include "RectangleBounds.h"

#include <algorithm>
#include "Contracts.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates rectangular bounds from the point at the origin.
RectangleBounds::RectangleBounds()
    : MinX(0.0), MaxX(0.0), MinY(0.0), MaxY(0.0)
{ }

/// \brief Creates rectangular bounds from a single point.
RectangleBounds::RectangleBounds(Vector2 Point)
    : MinX(Point.X), MaxX(Point.X), MinY(Point.Y), MaxY(Point.Y)
{ }

/// \brief Creates rectangular bounds from the given arguments.
/// \pre require(MinX <= MaxX);
/// \pre require(MinY <= MaxY);
RectangleBounds::RectangleBounds(double MinX, double MinY, double MaxX, double MaxY)
    : MinX(MinX), MinY(MinY), MaxX(MaxX), MaxY(MaxY)
{
    require(MinX <= MaxX);
    require(MinY <= MaxY);
}

/// \brief Creates a bounding rectangle that covers the union of this
/// rectangle and the given rectangle.
RectangleBounds RectangleBounds::Union(RectangleBounds Other) const
{
    return RectangleBounds(std::min<double>(this->MinX, Other.MinX), 
                           std::min<double>(this->MinY, Other.MinY), 
                           std::max<double>(this->MaxX, Other.MaxX), 
                           std::max<double>(this->MaxY, Other.MaxY));
}

/// \brief Gets the bounding rectangle's center.
Vector2 RectangleBounds::getCenter() const
{
    return Vector2((this->MinX + this->MaxX) / 2.0, 
                   (this->MinY + this->MaxY) / 2.0);
}

/// \brief Gets the bounding rectangle's height.
double RectangleBounds::getHeight() const
{
    return this->MaxY - this->MinY;
}

/// \brief Gets the bounding rectangle's width.
double RectangleBounds::getWidth() const
{
    return this->MaxX - this->MinX;
}

/// \brief Checks if this bounding rectangle equals the given other
/// rectangle.
bool RectangleBounds::operator==(RectangleBounds Bounds) const
{
    return this->MinX == Bounds.MinX && this->MinY == Bounds.MinY && 
           this->MaxX == Bounds.MaxX && this->MaxY == Bounds.MaxY;
}

/// \brief Checks if this bounding rectangle is not equal to the
/// given other rectangle.
bool RectangleBounds::operator!=(RectangleBounds Bounds) const
{
    return this->MinX != Bounds.MinX || this->MinY != Bounds.MinY || 
           this->MaxX != Bounds.MaxX || this->MaxY != Bounds.MaxY;
}