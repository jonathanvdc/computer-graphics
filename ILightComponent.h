#pragma once
#include "ReflectionProperties.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a light component: an object that decides how to
    /// color a pixel.
    struct ILightComponent
    {
        /// \brief Gets the light component's color for the given point,
        /// normal, direction and reflection properties.
        virtual Vector4 GetColor(Vector3 Point, Vector3 Normal, Vector3 Direction, ReflectionProperties Properties) const = 0;
    };
}