#include "ProjectedMultiLine.h"

#include <memory>
#include "ArraySlice.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITransformation.h"
#include "MultiLine.h"
#include "ProjectedMultiLineRenderCommand.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new projected multi-line from the given
/// projected and original points.
ProjectedMultiLine::ProjectedMultiLine(stdx::ArraySlice<Vector2> Points, stdx::ArraySlice<Vector3> OriginalPoints)
{
    this->setPoints(Points);
    this->setOriginalPoints(OriginalPoints);
    this->setFillPath(false);
    this->setProjectionDistance(this->CalculateProjectionDistance());
}

/// \brief Creates a new projected multi-line from the given
/// projected and original points, as well as a boolean flag
/// that specifies if the multi-line is to be filled.
ProjectedMultiLine::ProjectedMultiLine(stdx::ArraySlice<Vector2> Points, stdx::ArraySlice<Vector3> OriginalPoints, bool FillPath)
{
    this->setPoints(Points);
    this->setOriginalPoints(OriginalPoints);
    this->setFillPath(FillPath);
    this->setProjectionDistance(this->CalculateProjectionDistance());
}

/// \brief Creates a new projected multi-line from the given
/// projected and original points, as well as a boolean flag
/// that specifies if the multi-line is to be filled.
/// The projection distance is also specified.
ProjectedMultiLine::ProjectedMultiLine(stdx::ArraySlice<Vector2> Points, stdx::ArraySlice<Vector3> OriginalPoints, bool FillPath, double ProjectionDistance)
{
    this->setPoints(Points);
    this->setOriginalPoints(OriginalPoints);
    this->setFillPath(FillPath);
    this->setProjectionDistance(ProjectionDistance);
}

/// \brief Calculates the initial screen distance.
double ProjectedMultiLine::CalculateProjectionDistance() const
{
    auto arr = this->getOriginalPoints();
    int i = arr.GetLength();
    int j = 0;
    auto temp = this->getPoints();
    int k = temp.GetLength();
    while (j < i && j < k)
    {
        if (arr[j].X != 0.0)
            return -temp[j].X * arr[j].Z / arr[j].X;
        else if (arr[j].Y != 0.0)
            return -temp[j].Y * arr[j].Z / arr[j].Y;

        ++j;
    }
    return 1.0;
}

/// \brief Creates a render command for this shape.
std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> ProjectedMultiLine::Render(std::shared_ptr<IBrush> Brush) const
{
    return std::make_shared<ProjectedMultiLineRenderCommand>(this->getPoints(), 
                                                             this->getOriginalPoints(), 
                                                             Brush, 
                                                             this->getFillPath(), 
                                                             this->getProjectionDistance());
}

/// \brief Creates a new shape that corresponds to this shape after
/// the given transformation has been applied.
std::shared_ptr<IShape> ProjectedMultiLine::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    auto oldPoints = this->getPoints();
    stdx::ArraySlice<Vector2> newPoints(oldPoints.GetLength());
    for (int i = 0; i < newPoints.GetLength(); ++i)
        newPoints[i] = Transformation->Transform(oldPoints[i]);
    return std::make_shared<ProjectedMultiLine>(newPoints, 
                                                this->getOriginalPoints(), 
                                                this->getFillPath(), 
                                                this->TransformProjectionDistance(Transformation));
}

/// \brief Transforms the screen distance with the given
/// transformation.
double ProjectedMultiLine::TransformProjectionDistance(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    Vector2 origin;
    Vector2 element(1.0, 0.0);
    auto transOrigin = Transformation->Transform(origin);
    auto transElement = Transformation->Transform(element);
    auto scaledElement = transElement - transOrigin;
    double factor = scaledElement.getLength();
    return this->getProjectionDistance() * factor;
}

/// \brief Gets the array that contains this multi-line's points.
stdx::ArraySlice<Vector3> ProjectedMultiLine::getOriginalPoints() const
{
    return this->OriginalPoints_value;
}

/// \brief Sets the array that contains this multi-line's points.
void ProjectedMultiLine::setOriginalPoints(stdx::ArraySlice<Vector3> value)
{
    this->OriginalPoints_value = value;
}

/// \brief Gets the projection distance (d).
double ProjectedMultiLine::getProjectionDistance() const
{
    return this->ProjectionDistance_value;
}

/// \brief Sets the projection distance (d).
void ProjectedMultiLine::setProjectionDistance(double value)
{
    this->ProjectionDistance_value = value;
}