#include "CompositeLightComponent.h"

#include <memory>
#include "ILightComponent.h"
#include "ReflectionProperties.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new composite light component from the given
/// light components.
CompositeLightComponent::CompositeLightComponent(std::shared_ptr<ILightComponent> First, std::shared_ptr<ILightComponent> Second)
    : First(First), Second(Second)
{ }

/// \brief Gets the light component's color for the given point,
/// normal, direction and reflection properties.
Vector4 CompositeLightComponent::GetColor(Vector3 Point, Vector3 Normal, Vector3 Direction, ReflectionProperties Properties) const
{
    return this->First->GetColor(Point, Normal, Direction, Properties) + this->Second->GetColor(Point, Normal, Direction, Properties);
}