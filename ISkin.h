#pragma once
#include <memory>
#include "ArraySlice.h"
#include "ITexture.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a skin: an object that creates textures for
    /// projected polygons.
    /// \remark Skins occur during the "mesh" stage of the pipeline.
    /// Skin -> Texture -> Brush.
    /// Mesh -> Shape   -> Render Command.
    struct ISkin
    {
        /// \brief Creates a texture that represents this skin for a polygon
        /// with the given original and projected points.
        virtual std::shared_ptr<ITexture> CreateTexture(stdx::ArraySlice<Vector3> OriginalPoints, stdx::ArraySlice<Vector2> ProjectedPoints) const = 0;
    };
}