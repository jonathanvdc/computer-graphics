#pragma once
#include <memory>
#include "IBrush3.h"
#include "ILightComponent.h"
#include "ReflectionProperties.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a specular light component.
    /// This type captures the principles of specular lighting.
    struct SpecularLightComponent : public virtual ILightComponent
    {
        /// \brief Creates a specular light component from the given brush.
        SpecularLightComponent(std::shared_ptr<IBrush3> Brush);

        /// \brief Gets the light component's color for the given point,
        /// normal, direction and reflection properties.
        Vector4 GetColor(Vector3 Point, Vector3 Normal, Vector3 Direction, ReflectionProperties Properties) const override;

        /// \brief The brush that defines this light component's color.
        std::shared_ptr<IBrush3> Brush;
    };
}