#pragma once
#include <memory>
#include "DepthSkinBase.h"
#include "ITexture.h"
#include "ProjectedPolygonTexture.h"

namespace Engine
{
    /// \brief Defines a depth skin, which applies Z-buffering.
    class DepthSkin : public DepthSkinBase
    {
    public:
        DepthSkin();
    protected:
        /// \brief Creates a texture based on the given projected polygon
        /// depth texture.
        std::shared_ptr<ITexture> CreateTexture(std::shared_ptr<ProjectedPolygonTexture> DepthTexture) const override;
    };
}