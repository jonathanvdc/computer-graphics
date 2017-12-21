#include "DepthSkin.h"

#include <memory>
#include "DepthSkinBase.h"
#include "ITexture.h"
#include "ProjectedPolygonTexture.h"

using namespace Engine;

DepthSkin::DepthSkin()
{ }

/// \brief Creates a texture based on the given projected polygon
/// depth texture.
std::shared_ptr<ITexture> DepthSkin::CreateTexture(std::shared_ptr<ProjectedPolygonTexture> DepthTexture) const
{
    return DepthTexture;
}