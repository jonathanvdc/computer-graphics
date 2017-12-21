#include "LineSegment.h"

#include <cmath>
#include <memory>
#include "IBitmap.h"
#include "IBitmapSegment.h"
#include "IBrush.h"
#include "ICommand.h"
#include "ISegment.h"
#include "ITransformation.h"
#include "IVectorInstructionStream.h"
#include "IVectorSegment.h"
#include "Vector2.h"
#include "WriteLineSegmentCommand.h"

using namespace Engine;

LineSegment::LineSegment()
{
    this->setStartPoint(Vector2());
    this->setEndPoint(Vector2());
}

LineSegment::LineSegment(Vector2 StartPoint, Vector2 EndPoint)
{
    this->setStartPoint(StartPoint);
    this->setEndPoint(EndPoint);
}

/// \brief Draws the segment on the target bitmap with the given
/// brush.
void LineSegment::Draw(std::shared_ptr<IBitmap> TargetBitmap, std::shared_ptr<IBrush> Brush)
{
    TargetBitmap->DrawLine((int)this->getStartPoint().X, 
                           (int)this->getStartPoint().Y, 
                           (int)this->getEndPoint().X, 
                           (int)this->getEndPoint().Y, Brush);
}

/// \brief Gets the segment's position at the given offset (where
/// offset is a value between 0.0 and 1.0).
Vector2 LineSegment::GetPosition(double Offset) const
{
    return Vector2(this->getStartPoint().X + Offset * this->getEndPoint().X, 
                   this->getStartPoint().Y + Offset * this->getEndPoint().Y);
}

/// \brief Creates a new segment that corresponds to this segment
/// after the given transformation has been applied.
std::shared_ptr<ISegment> LineSegment::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    return std::make_shared<LineSegment>(Transformation->Transform(this->getStartPoint()), 
                                         Transformation->Transform(this->getEndPoint()));
}

/// \brief Gets a command that writes the vector segment's data to a
/// vector instruction stream.
std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> LineSegment::Write()
{
    return std::make_shared<WriteLineSegmentCommand>(this->getStartPoint(), 
                                                     this->getEndPoint());
}

/// \brief Sets the line segment's end position.
void LineSegment::setEndPoint(Vector2 value)
{
    this->EndPoint_value = value;
}

/// \brief Gets the line segment's end position.
Vector2 LineSegment::getEndPoint() const
{
    return this->EndPoint_value;
}

/// \brief Gets the segment's length.
double LineSegment::getLength() const
{
    double dx = this->getEndPoint().X - this->getStartPoint().X;
    double dy = this->getEndPoint().Y - this->getStartPoint().Y;
    return std::hypot(dx, dy);
}

/// \brief Sets the line segment's start position.
void LineSegment::setStartPoint(Vector2 value)
{
    this->StartPoint_value = value;
}

/// \brief Gets the line segment's start position.
Vector2 LineSegment::getStartPoint() const
{
    return this->StartPoint_value;
}