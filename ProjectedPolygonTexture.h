#pragma once
#include <memory>
#include "ArraySlice.h"
#include "IBrush.h"
#include "IRenderTarget.h"
#include "ITexture.h"
#include "ITransformation.h"
#include "PolygonDepthBrush.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a depth texture for projected polygons.
    class ProjectedPolygonTexture : public virtual ITexture
    {
    public:
        /// \brief Creates a new projected polygon depth texture from the
        /// given points.
        ProjectedPolygonTexture(stdx::ArraySlice<Vector3> OriginalPoints, stdx::ArraySlice<Vector2> ProjectedPoints);
        /// \brief Creates a new projected polygon depth texture from the
        /// given points and projection distance.
        ProjectedPolygonTexture(stdx::ArraySlice<Vector3> OriginalPoints, stdx::ArraySlice<Vector2> ProjectedPoints, double ProjectionDistance);

        /// \brief Converts the texture to a brush for the given render
        /// target based on the given brush.
        std::shared_ptr<IBrush> ToBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const override;

        /// \brief Creates a polygon depth brush for this projected polygon
        /// depth texture.
        std::shared_ptr<PolygonDepthBrush> ToDepthBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const;

        /// \brief Transforms the texture with the given two-dimensional
        /// transformation.
        std::shared_ptr<ITexture> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;

        /// \brief Transforms this projected polygon depth brush.
        std::shared_ptr<ProjectedPolygonTexture> TransformTexture(std::shared_ptr<ITransformation<Vector2>> Transformation) const;

        /// \brief The projected polygon's original points.
        stdx::ArraySlice<Vector3> OriginalPoints;
        /// \brief The projected polygon's projected points.
        stdx::ArraySlice<Vector2> ProjectedPoints;
        /// \brief The projection distance.
        double ProjectionDistance;
    private:
        /// \brief Transforms the screen distance with the given
        /// transformation.
        double TransformProjectionDistance(std::shared_ptr<ITransformation<Vector2>> Transformation) const;
    };
}