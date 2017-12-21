#include "ReflectionProperties.h"

#include <memory>
#include "IBrush3.h"

using namespace Engine;

/// \brief Creates an empty reflection properties object.
/// Note that this is not a valid state for reflection
/// properties: this is merely intended to default-initialize
/// stack-allocated ReflectionProperties objects.
ReflectionProperties::ReflectionProperties()
{ }

/// \brief Creates a reflection properties object from the given
/// reflection brushes and specular reflectivity factor.
ReflectionProperties::ReflectionProperties(std::shared_ptr<IBrush3> AmbientReflection, std::shared_ptr<IBrush3> DiffuseReflection, std::shared_ptr<IBrush3> SpecularReflection, double Reflectivity)
    : AmbientReflection(AmbientReflection), DiffuseReflection(DiffuseReflection), SpecularReflection(SpecularReflection), Reflectivity(Reflectivity)
{ }