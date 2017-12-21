#pragma once
#include <memory>
#include "DepthSkinBase.h"
#include "ITexture.h"
#include "LightingState.h"
#include "ProjectedPolygonTexture.h"
#include "ReflectionProperties.h"

namespace Engine
{
    /// \brief Defines a lighting skin, which applies Z-buffering, and
    /// also lights the meshes in the scene.
    class LightingSkin : public DepthSkinBase
    {
    public:
        /// \brief Creates a new lighting skin from the given reflection
        /// properties and global lighting state.
        LightingSkin(ReflectionProperties Properties, std::shared_ptr<LightingState> State);

        /// \brief The reflection properties of the lighting skin's
        /// associated mesh.
        ReflectionProperties Properties;
        /// \brief The lighting skin's lighting state.
        std::shared_ptr<LightingState> State;
    protected:
        /// \brief Creates a texture based on the given projected polygon
        /// depth texture.
        std::shared_ptr<ITexture> CreateTexture(std::shared_ptr<ProjectedPolygonTexture> DepthTexture) const override;
    };
}