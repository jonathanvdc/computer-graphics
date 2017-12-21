#pragma once
#include <memory>
#include "DepthBrushBase.h"
#include "IBrush.h"
#include "IDepthBuffer.h"
#include "PixelPosition.h"
#include "ProjectedLineSegment.h"

namespace Engine
{
    /// \brief Represents a line depth brush.
    struct LineDepthBrush : public DepthBrushBase
    {
        /// \brief Creates a new line depth brush from the given brush, depth
        /// buffer and projected line segment.
        LineDepthBrush(std::shared_ptr<IBrush> Brush, std::shared_ptr<IDepthBuffer> DepthBuffer, ProjectedLineSegment Segment);

        /// \brief Gets the mesh's depth at the given pixel position.
        double GetDepth(PixelPosition Position) const override;

        /// \brief The projected line segment the line depth brush bases
        /// itself on.
        ProjectedLineSegment Segment;
    };
}