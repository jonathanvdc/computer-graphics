#include "LinePathBase.h"

#include <memory>
#include "ArraySlice.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IPartialSegment.h"
#include "IRenderTarget.h"
#include "ISegment.h"
#include "IShape.h"
#include "ITransformation.h"
#include "LineSegment.h"
#include "RectangleBounds.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a new line path.
LinePathBase::LinePathBase()
{
    this->setFillPath(false);
}

LinePathBase::LinePathBase(stdx::ArraySlice<std::shared_ptr<ISegment>> Segments, bool FillPath)
{
    this->setSegments(Segments);
    this->setFillPath(FillPath);
}

LinePathBase::LinePathBase(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint, bool FillPath)
{
    this->setFillPath(FillPath);
    this->setSegments(this->CloseSegments(Segs, EndPoint));
}

/// \brief Closes the given partial line segments with the given end
/// point.
stdx::ArraySlice<std::shared_ptr<ISegment>> LinePathBase::CloseSegments(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint)
{
    stdx::ArraySlice<std::shared_ptr<ISegment>> results(Segs.GetLength());
    for (int i = 0; i < results.GetLength(); ++i)
        results[i] = Segs[i]->Close(this->GetStartPoint(i + 1, Segs, EndPoint));
    return results;
}

/// \brief Gets the starting point of the line segment with the given
/// index, based on an array of partial segments, and an end
/// point.
Vector2 LinePathBase::GetStartPoint(int Index, stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint)
{
    if (Index == Segs.GetLength())
        return EndPoint;
    else
        return Segs[Index]->getStartPoint();

}

/// \brief Approximates the given segments with line segments.
stdx::ArraySlice<LineSegment> LinePathBase::ToLineSegments(std::shared_ptr<ISegment> Segment) const
{
    int lineCount = (int)Segment->getLength() / 5;
    double delta = 1.0 / (double)lineCount;
    stdx::ArraySlice<LineSegment> results(lineCount);
    for (int i = 0; i < lineCount; ++i)
        results[i] = LineSegment(Segment->GetPosition((double)i * delta), 
                                 Segment->GetPosition((double)(i + 1) * delta));
    return results;
}

/// \brief Gets the shape's rectangular bounds.
RectangleBounds LinePathBase::getBounds() const
{
    RectangleBounds result(this->getSegments()[0]->GetPosition(0.0));
    for (int i = 0; i < this->getSegments().GetLength(); ++i)
    {
        result = result.Union(RectangleBounds(this->getSegments()[i]->GetPosition(0.0)));
        result = result.Union(RectangleBounds(this->getSegments()[i]->GetPosition(1.0)));
    }
    return result;
}

/// \brief Sets a boolean value that indicates if the path will be
/// filled, rather than have its outline drawn.
void LinePathBase::setFillPath(bool value)
{
    this->FillPath_value = value;
}

/// \brief Gets a boolean value that indicates if the path will be
/// filled, rather than have its outline drawn.
bool LinePathBase::getFillPath() const
{
    return this->FillPath_value;
}

/// \brief Sets the line path's segments.
void LinePathBase::setSegments(stdx::ArraySlice<std::shared_ptr<ISegment>> value)
{
    this->Segments_value = value;
}

/// \brief Gets the line path's segments.
stdx::ArraySlice<std::shared_ptr<ISegment>> LinePathBase::getSegments() const
{
    return this->Segments_value;
}