#include "DepthSkinBase.h"

#include <memory>
#include "ArraySlice.h"
#include "ISkin.h"
#include "ITexture.h"
#include "ProjectedPolygonTexture.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace Engine;

DepthSkinBase::DepthSkinBase()
{ }

/// \brief Creates a texture that represents this skin for a polygon
/// with the given original and projected points.
std::shared_ptr<ITexture> DepthSkinBase::CreateTexture(stdx::ArraySlice<Vector3> OriginalPoints, stdx::ArraySlice<Vector2> ProjectedPoints) const
{
    auto texture = std::make_shared<ProjectedPolygonTexture>(OriginalPoints, 
                                                             ProjectedPoints);
    return this->CreateTexture(texture);
}