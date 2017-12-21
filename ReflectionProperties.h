#pragma once
#include <memory>
#include "IBrush3.h"

namespace Engine
{
    /// \brief Encapsulates a mesh's reflection properties.
    struct ReflectionProperties
    {
        /// \brief Creates an empty reflection properties object.
        /// Note that this is not a valid state for reflection
        /// properties: this is merely intended to default-initialize
        /// stack-allocated ReflectionProperties objects.
        ReflectionProperties();
        /// \brief Creates a reflection properties object from the given
        /// reflection brushes and specular reflectivity factor.
        ReflectionProperties(std::shared_ptr<IBrush3> AmbientReflection, std::shared_ptr<IBrush3> DiffuseReflection, std::shared_ptr<IBrush3> SpecularReflection, double Reflectivity);

        /// \brief The ambient reflection brush.
        std::shared_ptr<IBrush3> AmbientReflection;
        /// \brief The diffuse reflection brush.
        std::shared_ptr<IBrush3> DiffuseReflection;
        /// \brief The specular reflectivity factor.
        double Reflectivity;
        /// \brief The specular reflection brush.
        std::shared_ptr<IBrush3> SpecularReflection;
    };
}