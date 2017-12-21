#include "PartialLineSegment.h"

#include <memory>
#include "IPartialSegment.h"
#include "ISegment.h"
#include "LineSegment.h"
#include "Vector2.h"

using namespace Engine;

PartialLineSegment::PartialLineSegment()
{
    this->setStartPoint(Vector2());
}

PartialLineSegment::PartialLineSegment(Vector2 StartPoint)
{
    this->setStartPoint(StartPoint);
}

/// \brief Closes the partial segment to form a curve segment.
std::shared_ptr<ISegment> PartialLineSegment::Close(Vector2 EndPoint) const
{
    return std::make_shared<LineSegment>(this->getStartPoint(), 
                                         EndPoint);
}

/// \brief Gets the line segment's start position.
Vector2 PartialLineSegment::getStartPoint() const
{
    return this->StartPoint_value;
}

/// \brief Sets the line segment's start position.
void PartialLineSegment::setStartPoint(Vector2 value)
{
    this->StartPoint_value = value;
}