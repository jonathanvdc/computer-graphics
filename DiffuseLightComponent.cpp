#include "DiffuseLightComponent.h"

#include <memory>
#include "IBrush3.h"
#include "ILightComponent.h"
#include "ReflectionProperties.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a diffuse light component from the given brush.
DiffuseLightComponent::DiffuseLightComponent(std::shared_ptr<IBrush3> Brush)
    : Brush(Brush)
{ }

/// \brief Gets the light component's color for the given point,
/// normal, direction and reflection properties.
Vector4 DiffuseLightComponent::GetColor(Vector3 Point, Vector3 Normal, Vector3 Direction, ReflectionProperties Properties) const
{
    double cosa = Normal.Dot(Direction);
    if (cosa < 0.0)
        return Vector4();
    else
    {
        auto lightColor = this->Brush->GetColor(Point);
        auto diffuseRefl = Properties.DiffuseReflection->GetColor(Point);
        return lightColor.Scale(diffuseRefl) * cosa;
    }

}