#include "TextureSkin.h"

#include <memory>
#include "ArraySlice.h"
#include "ISkin.h"
#include "ITexture.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new texture skin from the given texture.
TextureSkin::TextureSkin(std::shared_ptr<ITexture> Texture)
    : Texture(Texture)
{ }

/// \brief Creates a texture that represents this skin for a polygon
/// with the given original and projected points.
std::shared_ptr<ITexture> TextureSkin::CreateTexture(stdx::ArraySlice<Vector3> OriginalPoints, stdx::ArraySlice<Vector2> ProjectedPoints) const
{
    return this->Texture;
}