#include "ShadowPointLight.h"

#include <algorithm>
#include <memory>
#include "IDepthBuffer.h"
#include "ILight.h"
#include "ILightComponent.h"
#include "IProjection.h"
#include "ISurface.h"
#include "ITransformation.h"
#include "PixelPosition.h"
#include "ReflectionProperties.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a shadow point light from the given arguments.
ShadowPointLight::ShadowPointLight(Vector3 Position, std::shared_ptr<ILightComponent> Component, std::shared_ptr<IDepthBuffer> Mask, std::shared_ptr<ITransformation<Vector3>> GlobalTransformation, std::shared_ptr<IProjection> Projection, std::shared_ptr<ITransformation<Vector2>> ShapeTransformation)
    : Position(Position), Component(Component), Mask(Mask), GlobalTransformation(GlobalTransformation), Projection(Projection), ShapeTransformation(ShapeTransformation)
{ }

/// \brief Clamps the given integer between the given values.
int ShadowPointLight::Clamp(int Value, int Min, int Max) const
{
    return std::max<int>(std::min<int>(Value, Max), Min);
}

/// \brief Gets the light's color for the given point, normal and
/// reflection properties.
Vector4 ShadowPointLight::GetColor(Vector3 Point, Vector3 Normal, ReflectionProperties Properties) const
{
    if (this->IsShadowed(Point))
        return Vector4();
    else
    {
        auto offset = this->Position - Point;
        return this->Component->GetColor(Point, Normal, 
                                         offset.Normalize(), Properties);
    }

}

/// \brief Determines whether the given point is shadowed by another
/// point.
bool ShadowPointLight::IsShadowed(Vector3 Point) const
{
    auto transPt = this->GlobalTransformation->Transform(Point);
    auto projPt = this->ShapeTransformation->Transform(this->Projection->Project(transPt));
    int width = (int)this->Mask->getWidth() - 1;
    int height = (int)this->Mask->getHeight() - 1;
    int x1 = this->Clamp((int)projPt.X, 0, width);
    int x2 = this->Clamp(x1 + 1, 0, width);
    int y1 = this->Clamp((int)projPt.Y, 0, height);
    int y2 = this->Clamp(y1 + 1, 0, height);
    double alphax = projPt.X - (double)x1;
    double alphay = projPt.Y - (double)y1;
    double topLeft = this->Mask->getItem(PixelPosition(x1, y1));
    double bottomLeft = this->Mask->getItem(PixelPosition(x1, y2));
    double topRight = this->Mask->getItem(PixelPosition(x2, y1));
    double bottomRight = this->Mask->getItem(PixelPosition(x2, y2));
    double top = (1.0 - alphax) * topLeft + alphax * topRight;
    double bottom = (1.0 - alphax) * bottomLeft + alphax * bottomRight;
    double totalDepth = (1.0 - alphay) * top + alphay * bottom;
    double epsilon = 0.0001;
    double depth = 1.0 / totalDepth;
    double depthDiff = transPt.Z - depth;
    return depth * depth > epsilon && depthDiff * depthDiff > epsilon;
}