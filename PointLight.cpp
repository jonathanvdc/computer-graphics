#include "PointLight.h"

#include <memory>
#include "ILight.h"
#include "ILightComponent.h"
#include "ReflectionProperties.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new point light at the given position from the
/// given light component.
PointLight::PointLight(Vector3 Position, std::shared_ptr<ILightComponent> Component)
    : Position(Position), Component(Component)
{ }

/// \brief Gets the light's color for the given point, normal and
/// reflection properties.
Vector4 PointLight::GetColor(Vector3 Point, Vector3 Normal, ReflectionProperties Properties) const
{
    auto offset = this->Position - Point;
    return this->Component->GetColor(Point, Normal, 
                                     offset.Normalize(), Properties);
}