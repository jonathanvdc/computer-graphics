#pragma once
#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITransformation.h"
#include "RectangleBounds.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a projected line segment.
    struct ProjectedLineSegment : public virtual IShape
    {
        /// \brief Creates a new projected line segment of length zero at the
        /// origin.
        ProjectedLineSegment();
        /// \brief Creates a new projected line segment from the given
        /// arguments.
        ProjectedLineSegment(Vector3 StartPosition, Vector3 EndPosition, Vector2 ProjectedStartPosition, Vector2 ProjectedEndPosition);

        /// \brief Creates a render command for this shape.
        std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> Render(std::shared_ptr<IBrush> Brush) const override;

        /// \brief Creates a new shape that corresponds to this shape after
        /// the given transformation has been applied.
        std::shared_ptr<IShape> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;

        /// \brief Gets the projected line segment's rectangular bounds.
        RectangleBounds getBounds() const override;

        /// \brief The projected line segment's end position.
        Vector3 EndPosition;
        /// \brief The projected line segment's projected end position.
        Vector2 ProjectedEndPosition;
        /// \brief The projected line segment's projected start position.
        Vector2 ProjectedStartPosition;
        /// \brief The projected line segment's start position.
        Vector3 StartPosition;
    };
}