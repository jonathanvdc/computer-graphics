#pragma once
#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "ProjectedLineSegment.h"

namespace Engine
{
    /// \brief A render command for projected line segments.
    struct ProjectedLineSegmentRenderCommand : public virtual ICommand<std::shared_ptr<IRenderTarget>>
    {
        /// \brief Creates a new projected line segment render command based
        /// on the given segment and brush.
        ProjectedLineSegmentRenderCommand(ProjectedLineSegment Segment, std::shared_ptr<IBrush> Brush);

        /// \brief Executes the command on the given target.
        void Execute(std::shared_ptr<IRenderTarget> Target) override;

        std::shared_ptr<IBrush> Brush;
        ProjectedLineSegment Segment;
    };
}