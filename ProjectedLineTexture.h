#pragma once
#include <memory>
#include "IBrush.h"
#include "IRenderTarget.h"
#include "ITexture.h"
#include "ITransformation.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Engine
{
    struct ProjectedLineTexture : public virtual ITexture
    {
        ProjectedLineTexture(Vector3 OriginalStartPoint, Vector3 OriginalEndPoint, Vector2 ProjectedStartPoint, Vector2 ProjectedEndPoint);

        /// \brief Converts the texture to a brush for the given render
        /// target based on the given brush.
        std::shared_ptr<IBrush> ToBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const override;

        /// \brief Transforms the texture with the given two-dimensional
        /// transformation.
        std::shared_ptr<ITexture> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;

        Vector3 OriginalEndPoint;
        Vector3 OriginalStartPoint;
        Vector2 ProjectedEndPoint;
        Vector2 ProjectedStartPoint;
    };
}