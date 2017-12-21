#pragma once
#include <memory>
#include "IBitmap.h"
#include "ISampler.h"
#include "Vector2.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a sampler that truncates coordinates and then
    /// applies cosine interpolation to the results obtained by
    /// applying another sampler to the bitmap and truncated
    /// neighboring coordinates.
    class CosineInterpolationSampler : public virtual ISampler
    {
    public:
        /// \brief Creates a cosine interpolation sampler based on the given
        /// underlying sampler.
        CosineInterpolationSampler(std::shared_ptr<ISampler> Sampler);

        /// \brief Gets or approximates the color at the given (u, v)
        /// coordinates in the bitmap.
        Vector4 GetColor(std::shared_ptr<IBitmap> Bitmap, Vector2 UV) const override;

        /// \brief Gets the cosine interpolation sampler's underlying sampler.
        std::shared_ptr<ISampler> getSampler() const;
    private:
        /// \brief Applies cosine interpolation to the given double-precision
        /// values.
        static double CosineInterpolate(double Start, double End, double Ratio);

        /// \brief Applies cosine interpolation to the given four-dimensional
        /// vectors.
        static Vector4 CosineInterpolate(Vector4 Start, Vector4 End, double Ratio);

        /// \brief Sets the cosine interpolation sampler's underlying sampler.
        void setSampler(std::shared_ptr<ISampler> value);

        std::shared_ptr<ISampler> Sampler_value;
    };
}