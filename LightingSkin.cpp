#include "LightingSkin.h"

#include <memory>
#include "DepthSkinBase.h"
#include "ITexture.h"
#include "LightingState.h"
#include "LightingTexture.h"
#include "ProjectedPolygonTexture.h"
#include "ReflectionProperties.h"

using namespace Engine;

/// \brief Creates a new lighting skin from the given reflection
/// properties and global lighting state.
LightingSkin::LightingSkin(ReflectionProperties Properties, std::shared_ptr<LightingState> State)
{
    this->Properties = Properties;
    this->State = State;
}

/// \brief Creates a texture based on the given projected polygon
/// depth texture.
std::shared_ptr<ITexture> LightingSkin::CreateTexture(std::shared_ptr<ProjectedPolygonTexture> DepthTexture) const
{
    return std::make_shared<LightingTexture>(this->Properties, 
                                             this->State, DepthTexture);
}