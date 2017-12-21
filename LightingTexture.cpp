#include "LightingTexture.h"

#include <memory>
#include "IBrush.h"
#include "IRenderTarget.h"
#include "ITexture.h"
#include "ITransformation.h"
#include "LightingBrush.h"
#include "LightingState.h"
#include "ProjectedPolygonTexture.h"
#include "ReflectionProperties.h"
#include "TransformationAnalyzer.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a new lighting texture from the given reflection
/// properties, lighting state and depth texture.
LightingTexture::LightingTexture(ReflectionProperties Properties, std::shared_ptr<LightingState> State, std::shared_ptr<ProjectedPolygonTexture> DepthTexture)
    : Properties(Properties), State(State), DepthTexture(DepthTexture), Analyzer()
{ }

/// \brief Creates a new lighting texture from the given reflection
/// properties, lighting state, depth texture and
/// transformation analyzer.
LightingTexture::LightingTexture(ReflectionProperties Properties, std::shared_ptr<LightingState> State, std::shared_ptr<ProjectedPolygonTexture> DepthTexture, TransformationAnalyzer Analyzer)
    : Properties(Properties), State(State), DepthTexture(DepthTexture), Analyzer(Analyzer)
{ }

/// \brief Converts the texture to a brush for the given render
/// target based on the given brush.
std::shared_ptr<IBrush> LightingTexture::ToBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const
{
    return std::make_shared<LightingBrush>(this->Properties, 
                                           this->DepthTexture->ToDepthBrush(RenderTarget, Brush), 
                                           this->State, 
                                           this->Analyzer.getInvertedTransformation());
}

/// \brief Transforms the texture with the given two-dimensional
/// transformation.
std::shared_ptr<ITexture> LightingTexture::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    auto transDepthTexture = this->DepthTexture->TransformTexture(Transformation);
    auto analyzed = this->Analyzer.AddTransformation(Transformation);
    return std::make_shared<LightingTexture>(this->Properties, 
                                             this->State, 
                                             transDepthTexture, 
                                             analyzed);
}