#pragma once
#include <memory>
#include "IBitmap.h"
#include "ISampler.h"
#include "Vector2.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a sampler that truncates coordinates and then
    /// linearly interpolates the results obtained by applying
    /// another sampler to the bitmap and truncated neighboring
    /// coordinates.
    class LinearInterpolationSampler : public virtual ISampler
    {
    public:
        /// \brief Creates a linear interpolation sampler based on the given
        /// underlying sampler.
        LinearInterpolationSampler(std::shared_ptr<ISampler> Sampler);

        /// \brief Gets or approximates the color at the given (u, v)
        /// coordinates in the bitmap.
        Vector4 GetColor(std::shared_ptr<IBitmap> Bitmap, Vector2 UV) const override;

        /// \brief Gets the linear interpolation sampler's underlying sampler.
        std::shared_ptr<ISampler> getSampler() const;
    private:
        /// \brief Sets the linear interpolation sampler's underlying sampler.
        void setSampler(std::shared_ptr<ISampler> value);

        std::shared_ptr<ISampler> Sampler_value;
    };
}