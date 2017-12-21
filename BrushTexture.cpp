#include "BrushTexture.h"

#include <memory>
#include "IBrush.h"
#include "IRenderTarget.h"
#include "ITexture.h"
#include "ITransformation.h"
#include "Vector2.h"

using namespace Engine;

BrushTexture::BrushTexture(std::shared_ptr<IBrush> Brush)
    : Brush(Brush)
{ }

/// \brief Converts the texture to a brush for the given render
/// target based on the given brush.
std::shared_ptr<IBrush> BrushTexture::ToBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const
{
    return this->Brush;
}

/// \brief Transforms the texture with the given two-dimensional
/// transformation.
std::shared_ptr<ITexture> BrushTexture::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    return std::make_shared<BrushTexture>(this->Brush);
}