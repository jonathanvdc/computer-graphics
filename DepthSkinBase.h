#pragma once
#include <memory>
#include "ArraySlice.h"
#include "ISkin.h"
#include "ITexture.h"
#include "ProjectedPolygonTexture.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a base class for depth skins, whose common trait
    /// is the consumption of depth information when rendering.
    class DepthSkinBase : public virtual ISkin
    {
    public:
        DepthSkinBase();

        /// \brief Creates a texture that represents this skin for a polygon
        /// with the given original and projected points.
        std::shared_ptr<ITexture> CreateTexture(stdx::ArraySlice<Vector3> OriginalPoints, stdx::ArraySlice<Vector2> ProjectedPoints) const override;
    protected:
        /// \brief Creates a texture based on the given projected polygon
        /// depth texture.
        virtual std::shared_ptr<ITexture> CreateTexture(std::shared_ptr<ProjectedPolygonTexture> DepthTexture) const = 0;
    };
}