#include "InfinityLight.h"

#include <memory>
#include "ILight.h"
#include "ILightComponent.h"
#include "ReflectionProperties.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new light from the given direction and light
/// component.
InfinityLight::InfinityLight(Vector3 Direction, std::shared_ptr<ILightComponent> Component)
    : Component(Component), Direction(Direction.Normalize())
{ }

/// \brief Gets the light's color for the given point, normal and
/// reflection properties.
Vector4 InfinityLight::GetColor(Vector3 Point, Vector3 Normal, ReflectionProperties Properties) const
{
    return this->Component->GetColor(Point, Normal, this->Direction, 
                                     Properties);
}