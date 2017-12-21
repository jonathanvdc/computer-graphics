#include "CosineInterpolationSampler.h"

#include <cmath>
#include <memory>
#include "IBitmap.h"
#include "ISampler.h"
#include "ISurface.h"
#include "Vector2.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a cosine interpolation sampler based on the given
/// underlying sampler.
CosineInterpolationSampler::CosineInterpolationSampler(std::shared_ptr<ISampler> Sampler)
{
    this->setSampler(Sampler);
}

/// \brief Applies cosine interpolation to the given double-precision
/// values.
double CosineInterpolationSampler::CosineInterpolate(double Start, double End, double Ratio)
{
    double r2 = (1.0 - std::cos(Ratio * 3.14159265358979)) / 2.0;
    return Start * (1.0 - r2) + End * r2;
}

/// \brief Applies cosine interpolation to the given four-dimensional
/// vectors.
Vector4 CosineInterpolationSampler::CosineInterpolate(Vector4 Start, Vector4 End, double Ratio)
{
    return Vector4(CosineInterpolationSampler::CosineInterpolate(Start.X, 
                                                                 End.X, Ratio), 
                   CosineInterpolationSampler::CosineInterpolate(Start.Y, 
                                                                 End.Y, Ratio), 
                   CosineInterpolationSampler::CosineInterpolate(Start.Z, 
                                                                 End.Z, Ratio), 
                   CosineInterpolationSampler::CosineInterpolate(Start.W, 
                                                                 End.W, Ratio));
}

/// \brief Gets or approximates the color at the given (u, v)
/// coordinates in the bitmap.
Vector4 CosineInterpolationSampler::GetColor(std::shared_ptr<IBitmap> Bitmap, Vector2 UV) const
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
    auto top = CosineInterpolationSampler::CosineInterpolate(topLeft, 
                                                             topRight, 
                                                             alphax);
    auto bottom = CosineInterpolationSampler::CosineInterpolate(bottomLeft, 
                                                                bottomRight, 
                                                                alphax);
    return CosineInterpolationSampler::CosineInterpolate(top, bottom, 
                                                         alphay);
}

/// \brief Gets the cosine interpolation sampler's underlying sampler.
std::shared_ptr<ISampler> CosineInterpolationSampler::getSampler() const
{
    return this->Sampler_value;
}

/// \brief Sets the cosine interpolation sampler's underlying sampler.
void CosineInterpolationSampler::setSampler(std::shared_ptr<ISampler> value)
{
    this->Sampler_value = value;
}