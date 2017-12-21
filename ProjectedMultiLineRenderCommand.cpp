#include "ProjectedMultiLineRenderCommand.h"

#include <initializer_list>
#include <memory>
#include "ArraySlice.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "MultiLineRenderCommand.h"
#include "ProjectedLineSegment.h"
#include "ProjectedPolygonTexture.h"
#include "TexturedShape.h"
#include "Triangle.h"
#include "TriangleShape.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new projected multi-line from the given
/// arguments.
ProjectedMultiLineRenderCommand::ProjectedMultiLineRenderCommand(stdx::ArraySlice<Vector2> Points, stdx::ArraySlice<Vector3> OriginalPoints, std::shared_ptr<IBrush> Brush, bool FillPath, double ProjectionDistance)
{
    this->setPoints(Points);
    this->setOriginalPoints(OriginalPoints);
    this->setBrush(Brush);
    this->setFillPath(FillPath);
    this->setProjectionDistance(ProjectionDistance);
}

/// \brief Executes the command on the given target.
void ProjectedMultiLineRenderCommand::Execute(std::shared_ptr<IRenderTarget> Target)
{
    int i;
    if (!this->getFillPath())
        for (i = 1; i < this->getPoints().GetLength(); ++i)
        {
            ProjectedLineSegment shape(this->getOriginalPoints()[i - 1], 
                                       this->getOriginalPoints()[i], 
                                       this->getPoints()[i - 1], 
                                       this->getPoints()[i]);
            shape.Render(this->getBrush())->Execute(Target);
        }
    else
    {
        auto originalPt = this->getOriginalPoints()[0];
        auto projectedPt = this->getPoints()[0];
        double projDist = this->getProjectionDistance();
        for (i = 1; i < this->getPoints().GetLength() - 2; ++i)
        {
            stdx::ArraySlice<Vector3> origTriangle({
                                                       originalPt, this->getOriginalPoints()[i], 
                                                       this->getOriginalPoints()[i + 1]
                                                   });
            stdx::ArraySlice<Vector2> trianglePts({
                                                      projectedPt, this->getPoints()[i], 
                                                      this->getPoints()[i + 1]
                                                  });
            Triangle<Vector2> projTriangle(projectedPt, 
                                           this->getPoints()[i], 
                                           this->getPoints()[i + 1]);
            TexturedShape shape0(std::make_shared<TriangleShape>(projTriangle), 
                                 std::make_shared<ProjectedPolygonTexture>(origTriangle, 
                                                                           trianglePts, 
                                                                           projDist));
            shape0.Render(this->getBrush())->Execute(Target);
        }
    }

}

/// \brief Sets the projected multi-line's original points.
void ProjectedMultiLineRenderCommand::setOriginalPoints(stdx::ArraySlice<Vector3> value)
{
    this->OriginalPoints_value = value;
}

/// \brief Gets the projected multi-line's original points.
stdx::ArraySlice<Vector3> ProjectedMultiLineRenderCommand::getOriginalPoints() const
{
    return this->OriginalPoints_value;
}

/// \brief Sets the projection distance (d).
void ProjectedMultiLineRenderCommand::setProjectionDistance(double value)
{
    this->ProjectionDistance_value = value;
}

/// \brief Gets the projection distance (d).
double ProjectedMultiLineRenderCommand::getProjectionDistance() const
{
    return this->ProjectionDistance_value;
}