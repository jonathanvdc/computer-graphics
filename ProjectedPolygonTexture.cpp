#include "ProjectedPolygonTexture.h"

#include <memory>
#include "ArraySlice.h"
#include "IBrush.h"
#include "IRenderTarget.h"
#include "ITexture.h"
#include "ITransformation.h"
#include "PolygonDepthBrush.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new projected polygon depth texture from the
/// given points.
ProjectedPolygonTexture::ProjectedPolygonTexture(stdx::ArraySlice<Vector3> OriginalPoints, stdx::ArraySlice<Vector2> ProjectedPoints)
    : OriginalPoints(OriginalPoints), ProjectedPoints(ProjectedPoints)
{
    int i = OriginalPoints.GetLength();
    int j = 0;
    int k = ProjectedPoints.GetLength();
    while (j < i && j < k)
    {
        if (OriginalPoints[j].X != 0.0)
        {
            this->ProjectionDistance = -ProjectedPoints[j].X * OriginalPoints[j].Z / 
                                       OriginalPoints[j].X;
            break;
        }
        else if (OriginalPoints[j].Y != 0.0)
        {
            this->ProjectionDistance = -ProjectedPoints[j].Y * OriginalPoints[j].Z / 
                                       OriginalPoints[j].Y;
            break;
        }
        ++j;
    }
    this->ProjectionDistance = 1.0;
}

/// \brief Creates a new projected polygon depth texture from the
/// given points and projection distance.
ProjectedPolygonTexture::ProjectedPolygonTexture(stdx::ArraySlice<Vector3> OriginalPoints, stdx::ArraySlice<Vector2> ProjectedPoints, double ProjectionDistance)
    : OriginalPoints(OriginalPoints), ProjectedPoints(ProjectedPoints), ProjectionDistance(ProjectionDistance)
{ }

/// \brief Converts the texture to a brush for the given render
/// target based on the given brush.
std::shared_ptr<IBrush> ProjectedPolygonTexture::ToBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const
{
    return this->ToDepthBrush(RenderTarget, Brush);
}

/// \brief Creates a polygon depth brush for this projected polygon
/// depth texture.
std::shared_ptr<PolygonDepthBrush> ProjectedPolygonTexture::ToDepthBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const
{
    return std::make_shared<PolygonDepthBrush>(Brush, 
                                               RenderTarget->getDepthBuffer(), 
                                               this->ProjectedPoints, 
                                               this->OriginalPoints, 
                                               this->ProjectionDistance);
}

/// \brief Transforms the texture with the given two-dimensional
/// transformation.
std::shared_ptr<ITexture> ProjectedPolygonTexture::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    return this->TransformTexture(Transformation);
}

/// \brief Transforms the screen distance with the given
/// transformation.
double ProjectedPolygonTexture::TransformProjectionDistance(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    Vector2 origin;
    Vector2 element(1.0, 0.0);
    auto transOrigin = Transformation->Transform(origin);
    auto transElement = Transformation->Transform(element);
    auto scaledElement = transElement - transOrigin;
    double factor = scaledElement.getLength();
    return this->ProjectionDistance * factor;
}

/// \brief Transforms this projected polygon depth brush.
std::shared_ptr<ProjectedPolygonTexture> ProjectedPolygonTexture::TransformTexture(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    stdx::ArraySlice<Vector2> transProjPoints(this->ProjectedPoints.GetLength());
    for (int i = 0; i < transProjPoints.GetLength(); ++i)
        transProjPoints[i] = Transformation->Transform(this->ProjectedPoints[i]);
    return std::make_shared<ProjectedPolygonTexture>(this->OriginalPoints, 
                                                     transProjPoints, 
                                                     this->TransformProjectionDistance(Transformation));
}