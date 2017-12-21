#pragma once
#include <memory>
#include "ArraySlice.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITransformation.h"
#include "MultiLine.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a projected multi-line: a multi-line that is the
    /// result of projecting a three-dimensional mesh onto a
    /// two-dimensional plane. Unlike a normal multi-line, this
    /// type is depth-aware.
    class ProjectedMultiLine : public MultiLine
    {
    public:
        /// \brief Creates a new projected multi-line from the given
        /// projected and original points.
        ProjectedMultiLine(stdx::ArraySlice<Vector2> Points, stdx::ArraySlice<Vector3> OriginalPoints);
        /// \brief Creates a new projected multi-line from the given
        /// projected and original points, as well as a boolean flag
        /// that specifies if the multi-line is to be filled.
        ProjectedMultiLine(stdx::ArraySlice<Vector2> Points, stdx::ArraySlice<Vector3> OriginalPoints, bool FillPath);
        /// \brief Creates a new projected multi-line from the given
        /// projected and original points, as well as a boolean flag
        /// that specifies if the multi-line is to be filled.
        /// The projection distance is also specified.
        ProjectedMultiLine(stdx::ArraySlice<Vector2> Points, stdx::ArraySlice<Vector3> OriginalPoints, bool FillPath, double ProjectionDistance);

        /// \brief Gets the array that contains this multi-line's points.
        stdx::ArraySlice<Vector3> getOriginalPoints() const;

        /// \brief Gets the projection distance (d).
        double getProjectionDistance() const;

        /// \brief Creates a render command for this shape.
        std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> Render(std::shared_ptr<IBrush> Brush) const override;

        /// \brief Creates a new shape that corresponds to this shape after
        /// the given transformation has been applied.
        std::shared_ptr<IShape> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;
    private:
        /// \brief Calculates the initial screen distance.
        double CalculateProjectionDistance() const;

        /// \brief Sets the array that contains this multi-line's points.
        void setOriginalPoints(stdx::ArraySlice<Vector3> value);

        /// \brief Sets the projection distance (d).
        void setProjectionDistance(double value);

        /// \brief Transforms the screen distance with the given
        /// transformation.
        double TransformProjectionDistance(std::shared_ptr<ITransformation<Vector2>> Transformation) const;

        stdx::ArraySlice<Vector3> OriginalPoints_value;
        double ProjectionDistance_value;
    };
}