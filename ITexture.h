#pragma once
#include <memory>
#include "IBrush.h"
#include "IRenderTarget.h"
#include "ITransformation.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Defines a texture, which is a layer of abstraction over a
    /// brush.
    struct ITexture
    {
        /// \brief Converts the texture to a brush for the given render
        /// target based on the given brush.
        virtual std::shared_ptr<IBrush> ToBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const = 0;

        /// \brief Transforms the texture with the given two-dimensional
        /// transformation.
        virtual std::shared_ptr<ITexture> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const = 0;
    };
}