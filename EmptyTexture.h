#pragma once
#include <memory>
#include "IBrush.h"
#include "IRenderTarget.h"
#include "ITexture.h"
#include "ITransformation.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Defines an empty texture, which simply returns the shape's
    /// pre-existing brush.
    struct EmptyTexture : public virtual ITexture
    {
        /// \brief Creates a new empty texture.
        EmptyTexture();

        /// \brief Converts the texture to a brush for the given render
        /// target based on the given brush.
        std::shared_ptr<IBrush> ToBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const override;

        /// \brief Transforms the texture with the given two-dimensional
        /// transformation.
        std::shared_ptr<ITexture> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;
    };
}