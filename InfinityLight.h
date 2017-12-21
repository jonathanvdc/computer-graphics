#pragma once
#include <memory>
#include "ILight.h"
#include "ILightComponent.h"
#include "ReflectionProperties.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a light that is infinitely far away.
    struct InfinityLight : public virtual ILight
    {
        /// \brief Creates a new light from the given direction and light
        /// component.
        InfinityLight(Vector3 Direction, std::shared_ptr<ILightComponent> Component);

        /// \brief Gets the light's color for the given point, normal and
        /// reflection properties.
        Vector4 GetColor(Vector3 Point, Vector3 Normal, ReflectionProperties Properties) const override;

        /// \brief The light's underlying light component.
        std::shared_ptr<ILightComponent> Component;
        /// \brief The light's direction.
        Vector3 Direction;
    };
}