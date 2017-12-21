#include "BitmapLinePath.h"

#include <memory>
#include "ArraySlice.h"
#include "CommandBlock.h"
#include "IBitmapSegment.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IPartialSegment.h"
#include "IRenderTarget.h"
#include "ISegment.h"
#include "IShape.h"
#include "IsInstance.h"
#include "ITransformation.h"
#include "LinePathBase.h"
#include "LineSegment.h"
#include "RenderBitmapSegmentCommand.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a new bitmap line path from the given segments.
BitmapLinePath::BitmapLinePath(stdx::ArraySlice<std::shared_ptr<ISegment>> Segments)
{
    this->setSegments(Segments);
}

/// \brief Creates a new bitmap line path from the given segments and
/// a boolean flag that indicates whether the path should be
/// filled or not.
BitmapLinePath::BitmapLinePath(stdx::ArraySlice<std::shared_ptr<ISegment>> Segments, bool FillPath)
{
    this->setSegments(Segments);
    this->setFillPath(FillPath);
}

/// \brief Creates a new bitmap line path from the given partial
/// segments and end point.
BitmapLinePath::BitmapLinePath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint)
{
    this->setSegments(this->CloseSegments(Segs, EndPoint));
}

/// \brief Creates a new bitmap line path from the given partial
/// segments, end point and a booleanflag that indicates
/// whether the path should be filled or not.
BitmapLinePath::BitmapLinePath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint, bool FillPath)
{
    this->setFillPath(FillPath);
    this->setSegments(this->CloseSegments(Segs, EndPoint));
}

/// \brief Creates a render command for this shape.
std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> BitmapLinePath::Render(std::shared_ptr<IBrush> Brush) const
{
    stdx::ArraySlice<std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>>> results(this->getSegments().GetLength());
    for (int i = 0; i < results.GetLength(); ++i)
        results[i] = this->RenderSegment(this->getSegments()[i], Brush);
    return std::make_shared<CommandBlock<std::shared_ptr<IRenderTarget>>>(results);
}

/// \brief Renders a single path segment.
std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> BitmapLinePath::RenderSegment(std::shared_ptr<ISegment> Segment, std::shared_ptr<IBrush> Brush) const
{
    if (stdx::isinstance<IBitmapSegment>(Segment))
        return std::make_shared<RenderBitmapSegmentCommand>(std::dynamic_pointer_cast<IBitmapSegment>(Segment), 
                                                            Brush);

    auto segs = this->ToLineSegments(Segment);
    stdx::ArraySlice<std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>>> commands(segs.GetLength());
    for (int i = 0; i < segs.GetLength(); ++i)
        commands[i] = std::make_shared<RenderBitmapSegmentCommand>(std::shared_ptr<LineSegment>(new LineSegment(segs[i])), 
                                                                   Brush);
    return std::make_shared<CommandBlock<std::shared_ptr<IRenderTarget>>>(commands);
}

/// \brief Creates a new shape that corresponds to this shape after
/// the given transformation has been applied.
std::shared_ptr<IShape> BitmapLinePath::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    auto segs = this->getSegments();
    stdx::ArraySlice<std::shared_ptr<ISegment>> transformedSegs(segs.GetLength());
    for (int i = 0; i < transformedSegs.GetLength(); ++i)
        transformedSegs[i] = segs[i]->Transform(Transformation);
    return std::make_shared<BitmapLinePath>(transformedSegs);
}