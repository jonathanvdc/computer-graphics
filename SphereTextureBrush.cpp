#include "SphereTextureBrush.h"

#include <cmath>
#include <memory>
#include "IBitmap.h"
#include "IBrush3.h"
#include "ISampler.h"
#include "ISurface.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new spherical texture brush from the given
/// center of the sphere, texture map and sampler.
SphereTextureBrush::SphereTextureBrush(Vector3 center, std::shared_ptr<IBitmap> texture, std::shared_ptr<ISampler> sampler)
    : center(center), texture(texture), sampler(sampler)
{ }

/// \brief Gets the brush's color at the given position, encoded as a
/// three-dimensional double-precision vector.
Vector4 SphereTextureBrush::GetColor(Vector3 Position)
{
    auto offset = Position - this->center;
    auto normal = offset.Normalize();
    double width = this->texture->getWidth();
    double height = this->texture->getHeight();
    double u = std::asin(normal.X) / 3.14159265358979 + 0.5;
    double v = std::asin(normal.Y) / 3.14159265358979 + 0.5;
    return this->sampler->GetColor(this->texture, 
                                   Vector2(width * u, height * v));
}