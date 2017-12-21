#pragma once
#include <memory>
#include "IBrush3.h"
#include "ILightComponent.h"
#include "ReflectionProperties.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a diffuse light component.
    /// This type captures the principles of diffuse lighting.
    struct DiffuseLightComponent : public virtual ILightComponent
    {
        /// \brief Creates a diffuse light component from the given brush.
        DiffuseLightComponent(std::shared_ptr<IBrush3> Brush);

        /// \brief Gets the light component's color for the given point,
        /// normal, direction and reflection properties.
        Vector4 GetColor(Vector3 Point, Vector3 Normal, Vector3 Direction, ReflectionProperties Properties) const override;

        /// \brief The brush that defines this light component's color.
        std::shared_ptr<IBrush3> Brush;
    };
}