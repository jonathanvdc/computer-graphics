#include "LinearInterpolationSampler.h"

#include <memory>
#include "IBitmap.h"
#include "ISampler.h"
#include "ISurface.h"
#include "Vector2.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a linear interpolation sampler based on the given
/// underlying sampler.
LinearInterpolationSampler::LinearInterpolationSampler(std::shared_ptr<ISampler> Sampler)
{
    this->setSampler(Sampler);
}

/// \brief Gets or approximates the color at the given (u, v)
/// coordinates in the bitmap.
Vector4 LinearInterpolationSampler::GetColor(std::shared_ptr<IBitmap> Bitmap, Vector2 UV) const
{
    double width = (double)(int)Bitmap->getWidth();
    double height = (double)(int)Bitmap->getHeight();
    int u1 = (int)UV.X;
    int u2 = u1 + 1;
    int v1 = (int)UV.Y;
    int v2 = v1 + 1;
    double alphax = UV.X - (double)u1;
    double alphay = UV.Y - (double)v1;
    auto topLeft = this->getSampler()->GetColor(Bitmap, 
                                                Vector2((double)u1, (double)v1));
    auto topRight = this->getSampler()->GetColor(Bitmap, 
                                                 Vector2((double)u2, (double)v1));
    auto bottomLeft = this->getSampler()->GetColor(Bitmap, 
                                                   Vector2((double)u1, (double)v2));
    auto bottomRight = this->getSampler()->GetColor(Bitmap, 
                                                    Vector2((double)u2, (double)v2));
    auto top = topLeft * (1.0 - alphax) + topRight * alphax;
    auto bottom = bottomLeft * (1.0 - alphax) + bottomRight * alphax;
    return top * (1.0 - alphay) + bottom * alphay;
}

/// \brief Gets the linear interpolation sampler's underlying sampler.
std::shared_ptr<ISampler> LinearInterpolationSampler::getSampler() const
{
    return this->Sampler_value;
}

/// \brief Sets the linear interpolation sampler's underlying sampler.
void LinearInterpolationSampler::setSampler(std::shared_ptr<ISampler> value)
{
    this->Sampler_value = value;
}