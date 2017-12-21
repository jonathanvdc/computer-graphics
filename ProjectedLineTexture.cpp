#include "ProjectedLineTexture.h"

#include <memory>
#include "IBrush.h"
#include "IRenderTarget.h"
#include "ITexture.h"
#include "ITransformation.h"
#include "LineDepthBrush.h"
#include "ProjectedLineSegment.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace Engine;

ProjectedLineTexture::ProjectedLineTexture(Vector3 OriginalStartPoint, Vector3 OriginalEndPoint, Vector2 ProjectedStartPoint, Vector2 ProjectedEndPoint)
    : OriginalStartPoint(OriginalStartPoint), OriginalEndPoint(OriginalEndPoint), ProjectedStartPoint(ProjectedStartPoint), ProjectedEndPoint(ProjectedEndPoint)
{ }

/// \brief Converts the texture to a brush for the given render
/// target based on the given brush.
std::shared_ptr<IBrush> ProjectedLineTexture::ToBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const
{
    ProjectedLineSegment segment(this->OriginalStartPoint, 
                                 this->OriginalEndPoint, 
                                 this->ProjectedStartPoint, 
                                 this->ProjectedEndPoint);
    return std::make_shared<LineDepthBrush>(Brush, 
                                            RenderTarget->getDepthBuffer(), 
                                            segment);
}

/// \brief Transforms the texture with the given two-dimensional
/// transformation.
std::shared_ptr<ITexture> ProjectedLineTexture::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    return std::make_shared<ProjectedLineTexture>(this->OriginalStartPoint, 
                                                  this->OriginalEndPoint, 
                                                  Transformation->Transform(this->ProjectedStartPoint), 
                                                  Transformation->Transform(this->ProjectedEndPoint));
}