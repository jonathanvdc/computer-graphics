#pragma once
#include <memory>
#include "IBitmap.h"
#include "ISampler.h"
#include "Vector2.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a sampler that truncates coordinates and then
    /// applies cubic interpolation to the results obtained by
    /// applying another sampler to the bitmap and truncated
    /// neighboring coordinates.
    class CubicInterpolationSampler : public virtual ISampler
    {
    public:
        /// \brief Creates a cubic interpolation sampler based on the given
        /// underlying sampler.
        CubicInterpolationSampler(std::shared_ptr<ISampler> Sampler);

        /// \brief Gets or approximates the color at the given (u, v)
        /// coordinates in the bitmap.
        Vector4 GetColor(std::shared_ptr<IBitmap> Bitmap, Vector2 UV) const override;

        /// \brief Gets the cubic interpolation sampler's underlying sampler.
        std::shared_ptr<ISampler> getSampler() const;
    private:
        /// \brief Applies cubic interpolation to the given double-precision
        /// values.
        static double CubicInterpolate(double x0, double x1, double x2, double x3, double Ratio);

        /// \brief Applies cubic interpolation to the given four-dimensional
        /// vectors.
        static Vector4 CubicInterpolate(Vector4 p0, Vector4 p1, Vector4 p2, Vector4 p3, double Ratio);

        /// \brief Sets the cubic interpolation sampler's underlying sampler.
        void setSampler(std::shared_ptr<ISampler> value);

        std::shared_ptr<ISampler> Sampler_value;
    };
}