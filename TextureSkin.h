#pragma once
#include <memory>
#include "ArraySlice.h"
#include "ISkin.h"
#include "ITexture.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a texture skin: a skin that returns a
    /// predetermined texture. Original and projected points are
    /// ignored entirely.
    struct TextureSkin : public virtual ISkin
    {
        /// \brief Creates a new texture skin from the given texture.
        TextureSkin(std::shared_ptr<ITexture> Texture);

        /// \brief Creates a texture that represents this skin for a polygon
        /// with the given original and projected points.
        std::shared_ptr<ITexture> CreateTexture(stdx::ArraySlice<Vector3> OriginalPoints, stdx::ArraySlice<Vector2> ProjectedPoints) const override;

        /// \brief The texture skin's underlying color.
        std::shared_ptr<ITexture> Texture;
    };
}