#pragma once
#include <memory>
#include "ILight.h"
#include "ILightComponent.h"
#include "ReflectionProperties.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a point light.
    struct PointLight : public virtual ILight
    {
        /// \brief Creates a new point light at the given position from the
        /// given light component.
        PointLight(Vector3 Position, std::shared_ptr<ILightComponent> Component);

        /// \brief Gets the light's color for the given point, normal and
        /// reflection properties.
        Vector4 GetColor(Vector3 Point, Vector3 Normal, ReflectionProperties Properties) const override;

        /// \brief The point light's light component.
        std::shared_ptr<ILightComponent> Component;
        /// \brief The point light's position.
        Vector3 Position;
    };
}