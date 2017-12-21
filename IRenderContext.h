#pragma once
#include <memory>
#include "ArraySlice.h"
#include "IPartialSegment.h"
#include "ISurface.h"
#include "Vector2.h"

namespace Engine
{
    struct IRenderTarget;
    struct IShape;

    /// \brief Provides common functionality for a render context, which
    /// is a surface that supports the creation of primitive
    /// shapes.
    struct IRenderContext : public virtual ISurface
    {
        /// \brief Creates a new partial line segment that starts at the
        /// given position.
        virtual std::shared_ptr<IPartialSegment> CreateLineSegment(Vector2 Start) const = 0;

        /// \brief Closes the given path segments with the given end point,
        /// returning a shape that represents the filled path.
        virtual std::shared_ptr<IShape> FillPath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segments, Vector2 End) const = 0;

        /// \brief Closes the given path segments with the given end point,
        /// returning a shape that represents the path's outline.
        virtual std::shared_ptr<IShape> StrokePath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segments, Vector2 End) const = 0;
    };
}