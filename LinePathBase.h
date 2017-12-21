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
#include "LineSegment.h"
#include "RectangleBounds.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Defines a base class for line paths: paths that render
    /// themselves by approximating their segments using line
    /// segments.
    class LinePathBase : public virtual IShape
    {
    public:
        LinePathBase(stdx::ArraySlice<std::shared_ptr<ISegment>> Segments, bool FillPath);
        LinePathBase(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint, bool FillPath);

        /// \brief Gets a boolean value that indicates if the path will be
        /// filled, rather than have its outline drawn.
        bool getFillPath() const;

        /// \brief Gets the line path's segments.
        stdx::ArraySlice<std::shared_ptr<ISegment>> getSegments() const;

        /// \brief Creates a render command for this shape.
        virtual std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> Render(std::shared_ptr<IBrush> Brush) const override = 0;

        /// \brief Creates a new shape that corresponds to this shape after
        /// the given transformation has been applied.
        virtual std::shared_ptr<IShape> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override = 0;

        /// \brief Gets the shape's rectangular bounds.
        RectangleBounds getBounds() const override;
    protected:
        /// \brief Creates a new line path.
        LinePathBase();

        /// \brief Closes the given partial line segments with the given end
        /// point.
        stdx::ArraySlice<std::shared_ptr<ISegment>> CloseSegments(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint);

        /// \brief Gets the starting point of the line segment with the given
        /// index, based on an array of partial segments, and an end
        /// point.
        Vector2 GetStartPoint(int Index, stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint);

        /// \brief Sets a boolean value that indicates if the path will be
        /// filled, rather than have its outline drawn.
        void setFillPath(bool value);

        /// \brief Sets the line path's segments.
        void setSegments(stdx::ArraySlice<std::shared_ptr<ISegment>> value);

        /// \brief Approximates the given segments with line segments.
        stdx::ArraySlice<LineSegment> ToLineSegments(std::shared_ptr<ISegment> Segment) const;
    private:
        bool FillPath_value;
        stdx::ArraySlice<std::shared_ptr<ISegment>> Segments_value;
    };
}