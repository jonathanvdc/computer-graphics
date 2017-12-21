#pragma once
#include <memory>
#include "ArraySlice.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IPartialSegment.h"
#include "IRenderTarget.h"
#include "ISegment.h"
#include "IShape.h"
#include "ITransformation.h"
#include "LinePathBase.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Defines a bitmap line path: a path that renders to a
    /// bitmap by approximating its segments with line segments.
    class BitmapLinePath : public LinePathBase
    {
    public:
        /// \brief Creates a new bitmap line path from the given segments.
        BitmapLinePath(stdx::ArraySlice<std::shared_ptr<ISegment>> Segments);
        /// \brief Creates a new bitmap line path from the given segments and
        /// a boolean flag that indicates whether the path should be
        /// filled or not.
        BitmapLinePath(stdx::ArraySlice<std::shared_ptr<ISegment>> Segments, bool FillPath);
        /// \brief Creates a new bitmap line path from the given partial
        /// segments and end point.
        BitmapLinePath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint);
        /// \brief Creates a new bitmap line path from the given partial
        /// segments, end point and a booleanflag that indicates
        /// whether the path should be filled or not.
        BitmapLinePath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint, bool FillPath);

        /// \brief Creates a render command for this shape.
        std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> Render(std::shared_ptr<IBrush> Brush) const override;

        /// \brief Creates a new shape that corresponds to this shape after
        /// the given transformation has been applied.
        std::shared_ptr<IShape> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;
    private:
        /// \brief Renders a single path segment.
        std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> RenderSegment(std::shared_ptr<ISegment> Segment, std::shared_ptr<IBrush> Brush) const;
    };
}