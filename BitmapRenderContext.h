#pragma once
#include <memory>
#include "ArraySlice.h"
#include "IPartialSegment.h"
#include "IRenderContext.h"
#include "IShape.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief A render context for bitmaps.
    class BitmapRenderContext : public virtual IRenderContext
    {
    public:
        /// \brief Creates a new bitmap render context with the given
        /// dimensions.
        BitmapRenderContext(double Width, double Height);

        /// \brief Creates a new partial line segment that starts at the
        /// given position.
        std::shared_ptr<IPartialSegment> CreateLineSegment(Vector2 Start) const override;

        /// \brief Closes the given path segments with the given end point,
        /// returning a shape that represents the filled path.
        std::shared_ptr<IShape> FillPath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segments, Vector2 End) const override;

        /// \brief Gets the surface's height.
        double getHeight() const override;

        /// \brief Gets the surface's width.
        double getWidth() const override;

        /// \brief Closes the given path segments with the given end point,
        /// returning a shape that represents the path's outline.
        std::shared_ptr<IShape> StrokePath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segments, Vector2 End) const override;
    private:
        void setHeight(double value);

        void setWidth(double value);

        double Height_value;
        double Width_value;
    };
}