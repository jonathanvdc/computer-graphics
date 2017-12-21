#include "CubicInterpolationSampler.h"

#include <initializer_list>
#include <memory>
#include "ArraySlice.h"
#include "IBitmap.h"
#include "ISampler.h"
#include "ISurface.h"
#include "Vector2.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a cubic interpolation sampler based on the given
/// underlying sampler.
CubicInterpolationSampler::CubicInterpolationSampler(std::shared_ptr<ISampler> Sampler)
{
    this->setSampler(Sampler);
}

/// \brief Applies cubic interpolation to the given double-precision
/// values.
double CubicInterpolationSampler::CubicInterpolate(double x0, double x1, double x2, double x3, double Ratio)
{
    double a = x3 - x2 - x0 + x1;
    double b = x0 - x1 - a;
    double c = x2 - x0;
    double d = x1;
    return a * Ratio * Ratio * Ratio + b * Ratio * Ratio + c * Ratio + 
           d;
}

/// \brief Applies cubic interpolation to the given four-dimensional
/// vectors.
Vector4 CubicInterpolationSampler::CubicInterpolate(Vector4 p0, Vector4 p1, Vector4 p2, Vector4 p3, double Ratio)
{
    return Vector4(CubicInterpolationSampler::CubicInterpolate(p0.X, p1.X, 
                                                               p2.X, p3.X, 
                                                               Ratio), 
                   CubicInterpolationSampler::CubicInterpolate(p0.Y, p1.Y, 
                                                               p2.Y, p3.Y, 
                                                               Ratio), 
                   CubicInterpolationSampler::CubicInterpolate(p0.Z, p1.Z, 
                                                               p2.Z, p3.Z, 
                                                               Ratio), 
                   CubicInterpolationSampler::CubicInterpolate(p0.W, p1.W, 
                                                               p2.W, p3.W, 
                                                               Ratio));
}

/// \brief Gets or approximates the color at the given (u, v)
/// coordinates in the bitmap.
Vector4 CubicInterpolationSampler::GetColor(std::shared_ptr<IBitmap> Bitmap, Vector2 UV) const
{
    double width = (double)(int)Bitmap->getWidth();
    double height = (double)(int)Bitmap->getHeight();
    int u1 = (int)UV.X;
    int v1 = (int)UV.Y;
    stdx::ArraySlice<int> us({ u1 - 1, u1, u1 + 1, u1 + 2 });
    stdx::ArraySlice<int> vs({ v1 - 1, v1, v1 + 1, v1 + 2 });
    double alphax = UV.X - (double)u1;
    double alphay = UV.Y - (double)v1;
    stdx::ArraySlice<Vector4> verticals(vs.GetLength());
    for (int i = 0; i < 4; ++i)
    {
        auto pt0 = this->getSampler()->GetColor(Bitmap, 
                                                Vector2((double)us[0], (double)vs[i]));
        auto pt1 = this->getSampler()->GetColor(Bitmap, 
                                                Vector2((double)us[1], (double)vs[i]));
        auto pt2 = this->getSampler()->GetColor(Bitmap, 
                                                Vector2((double)us[2], (double)vs[i]));
        auto pt3 = this->getSampler()->GetColor(Bitmap, 
                                                Vector2((double)us[3], (double)vs[i]));
        verticals[i] = CubicInterpolationSampler::CubicInterpolate(pt0, pt1, pt2, 
                                                                   pt3, alphax);
    }
    return CubicInterpolationSampler::CubicInterpolate(verticals[0], 
                                                       verticals[1], 
                                                       verticals[2], 
                                                       verticals[3], 
                                                       alphay);
}

/// \brief Gets the cubic interpolation sampler's underlying sampler.
std::shared_ptr<ISampler> CubicInterpolationSampler::getSampler() const
{
    return this->Sampler_value;
}

/// \brief Sets the cubic interpolation sampler's underlying sampler.
void CubicInterpolationSampler::setSampler(std::shared_ptr<ISampler> value)
{
    this->Sampler_value = value;
}