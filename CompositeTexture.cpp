#include "CompositeTexture.h"

#include <memory>
#include "IBrush.h"
#include "IRenderTarget.h"
#include "ITexture.h"
#include "ITransformation.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a composite texture from the given textures.
CompositeTexture::CompositeTexture(std::shared_ptr<ITexture> First, std::shared_ptr<ITexture> Second)
    : First(First), Second(Second)
{ }

/// \brief Converts the texture to a brush for the given render
/// target based on the given brush.
std::shared_ptr<IBrush> CompositeTexture::ToBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const
{
    auto firstBrush = this->First->ToBrush(RenderTarget, Brush);
    return this->Second->ToBrush(RenderTarget, firstBrush);
}

/// \brief Transforms the texture with the given two-dimensional
/// transformation.
std::shared_ptr<ITexture> CompositeTexture::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    return std::make_shared<CompositeTexture>(this->First->Transform(Transformation), 
                                              this->Second->Transform(Transformation));
}