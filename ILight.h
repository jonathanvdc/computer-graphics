#pragma once
#include "ReflectionProperties.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a light object.
    struct ILight
    {
        /// \brief Gets the light's color for the given point, normal and
        /// reflection properties.
        virtual Vector4 GetColor(Vector3 Point, Vector3 Normal, ReflectionProperties Properties) const = 0;
    };
}