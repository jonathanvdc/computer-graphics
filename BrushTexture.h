#pragma once
#include <memory>
#include "IBrush.h"
#include "IRenderTarget.h"
#include "ITexture.h"
#include "ITransformation.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Defines a brush texture, which sets the resulting brush to
    /// the brush contained in the brush texture.
    struct BrushTexture : public virtual ITexture
    {
        BrushTexture(std::shared_ptr<IBrush> Brush);

        /// \brief Converts the texture to a brush for the given render
        /// target based on the given brush.
        std::shared_ptr<IBrush> ToBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const override;

        /// \brief Transforms the texture with the given two-dimensional
        /// transformation.
        std::shared_ptr<ITexture> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;

        /// \brief The brush to apply.
        std::shared_ptr<IBrush> Brush;
    };
}