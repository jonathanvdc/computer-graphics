#pragma once
#include <memory>
#include "IBrush.h"
#include "IRenderTarget.h"
#include "ITexture.h"
#include "ITransformation.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Defines a composite texture, which amounts to the
    /// application of two textures in sequence.
    struct CompositeTexture : public virtual ITexture
    {
        /// \brief Creates a composite texture from the given textures.
        CompositeTexture(std::shared_ptr<ITexture> First, std::shared_ptr<ITexture> Second);

        /// \brief Converts the texture to a brush for the given render
        /// target based on the given brush.
        std::shared_ptr<IBrush> ToBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const override;

        /// \brief Transforms the texture with the given two-dimensional
        /// transformation.
        std::shared_ptr<ITexture> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;

        /// \brief The first texture to apply.
        std::shared_ptr<ITexture> First;
        /// \brief The second texture to apply.
        std::shared_ptr<ITexture> Second;
    };
}