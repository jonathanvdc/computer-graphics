#pragma once
#include <memory>
#include "ArraySlice.h"
#include "IBrush.h"
#include "IRenderTarget.h"
#include "MultiLineRenderCommand.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a render command for a projected multi-line.
    class ProjectedMultiLineRenderCommand : public MultiLineRenderCommand
    {
    public:
        /// \brief Creates a new projected multi-line from the given
        /// arguments.
        ProjectedMultiLineRenderCommand(stdx::ArraySlice<Vector2> Points, stdx::ArraySlice<Vector3> OriginalPoints, std::shared_ptr<IBrush> Brush, bool FillPath, double ProjectionDistance);

        /// \brief Executes the command on the given target.
        void Execute(std::shared_ptr<IRenderTarget> Target) override;

        /// \brief Gets the projected multi-line's original points.
        stdx::ArraySlice<Vector3> getOriginalPoints() const;

        /// \brief Gets the projection distance (d).
        double getProjectionDistance() const;
    private:
        /// \brief Sets the projected multi-line's original points.
        void setOriginalPoints(stdx::ArraySlice<Vector3> value);

        /// \brief Sets the projection distance (d).
        void setProjectionDistance(double value);

        stdx::ArraySlice<Vector3> OriginalPoints_value;
        double ProjectionDistance_value;
    };
}