#pragma once
#include <memory>
#include "IBrush.h"
#include "IRenderTarget.h"
#include "ITexture.h"
#include "ITransformation.h"
#include "LightingState.h"
#include "ProjectedPolygonTexture.h"
#include "ReflectionProperties.h"
#include "TransformationAnalyzer.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Defines a texture object that applies lighting to meshes.
    /// \remark Lighting textures are really just a vehicle for lighting
    /// brushes, to which they are lowered after the render step.
    struct LightingTexture : public virtual ITexture
    {
        /// \brief Creates a new lighting texture from the given reflection
        /// properties, lighting state and depth texture.
        LightingTexture(ReflectionProperties Properties, std::shared_ptr<LightingState> State, std::shared_ptr<ProjectedPolygonTexture> DepthTexture);
        /// \brief Creates a new lighting texture from the given reflection
        /// properties, lighting state, depth texture and
        /// transformation analyzer.
        LightingTexture(ReflectionProperties Properties, std::shared_ptr<LightingState> State, std::shared_ptr<ProjectedPolygonTexture> DepthTexture, TransformationAnalyzer Analyzer);

        /// \brief Converts the texture to a brush for the given render
        /// target based on the given brush.
        std::shared_ptr<IBrush> ToBrush(std::shared_ptr<IRenderTarget> RenderTarget, std::shared_ptr<IBrush> Brush) const override;

        /// \brief Transforms the texture with the given two-dimensional
        /// transformation.
        std::shared_ptr<ITexture> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;

        /// \brief The lighting brush's transformation analyzer.
        TransformationAnalyzer Analyzer;
        /// \brief The depth texture of the lighting brush's associated mesh.
        std::shared_ptr<ProjectedPolygonTexture> DepthTexture;
        /// \brief The reflection properties of the lighting brush's
        /// associated mesh.
        ReflectionProperties Properties;
        /// \brief The scene's lighting state.
        std::shared_ptr<LightingState> State;
    };
}