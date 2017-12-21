#include "SpecularLightComponent.h"

#include <cmath>
#include <memory>
#include "IBrush3.h"
#include "ILightComponent.h"
#include "ReflectionProperties.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a specular light component from the given brush.
SpecularLightComponent::SpecularLightComponent(std::shared_ptr<IBrush3> Brush)
    : Brush(Brush)
{ }

/// \brief Gets the light component's color for the given point,
/// normal, direction and reflection properties.
Vector4 SpecularLightComponent::GetColor(Vector3 Point, Vector3 Normal, Vector3 Direction, ReflectionProperties Properties) const
{
    double cosa = Normal.Dot(Direction);
    auto reflectionDirection = Normal * 2.0 * cosa - Direction;
    auto cameraVector = Point.Normalize() * -1.0;
    double cosb = reflectionDirection.Dot(cameraVector);
    if (cosb < 0.0)
        return Vector4();
    else
    {
        auto lightColor = this->Brush->GetColor(Point);
        auto specularRefl = Properties.SpecularReflection->GetColor(Point);
        return lightColor.Scale(specularRefl) * 
               std::pow(cosb, Properties.Reflectivity);
    }

}