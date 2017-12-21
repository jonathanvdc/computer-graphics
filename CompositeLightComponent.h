#pragma once
#include <memory>
#include "ILightComponent.h"
#include "ReflectionProperties.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a composite light component: a light component
    /// that performs additive blending on two other light
    /// components.
    struct CompositeLightComponent : public virtual ILightComponent
    {
        /// \brief Creates a new composite light component from the given
        /// light components.
        CompositeLightComponent(std::shared_ptr<ILightComponent> First, std::shared_ptr<ILightComponent> Second);

        /// \brief Gets the light component's color for the given point,
        /// normal, direction and reflection properties.
        Vector4 GetColor(Vector3 Point, Vector3 Normal, Vector3 Direction, ReflectionProperties Properties) const override;

        /// \brief The first light component.
        std::shared_ptr<ILightComponent> First;
        /// \brief The second light component.
        std::shared_ptr<ILightComponent> Second;
    };
}