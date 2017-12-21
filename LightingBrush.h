#pragma once
#include <memory>
#include "IBrush.h"
#include "ITransformation.h"
#include "LightingState.h"
#include "PixelPosition.h"
#include "PolygonDepthBrush.h"
#include "ReflectionProperties.h"
#include "Vector2.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a brush that applies lighting to a shape.
    struct LightingBrush : public virtual IBrush
    {
        /// \brief Creates a new lighting brush from the given arguments.
        LightingBrush(ReflectionProperties Properties, std::shared_ptr<PolygonDepthBrush> DepthBrush, std::shared_ptr<LightingState> State, std::shared_ptr<ITransformation<Vector2>> InvertedTransformation);

        /// \brief Gets the brush's color at the given position.
        Vector4 GetColor(PixelPosition Position) override;

        /// \brief The depth brush of the lighting brush's associated mesh.
        std::shared_ptr<PolygonDepthBrush> DepthBrush;
        /// \brief The lighting brush's inverted transformation.
        std::shared_ptr<ITransformation<Vector2>> InvertedTransformation;
        /// \brief The lighting brush's associated mesh's reflection
        /// properties.
        ReflectionProperties Properties;
        /// \brief The scene's lighting state.
        std::shared_ptr<LightingState> State;
    };
}