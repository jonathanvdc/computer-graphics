#pragma once
#include <memory>
#include "IBitmap.h"
#include "ISampler.h"
#include "Vector2.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a nearest-neighbor sampler, which truncates (u, v)
    /// coordinates and returns the color in the bitmap at said
    /// truncated coordinates. This sampler has clamping behavior
    /// for points that are outside the bitmap: the nearest edge
    /// point is selected.
    class NearestNeighborClampingSampler : public virtual ISampler
    {
    public:
        /// \brief Gets or approximates the color at the given (u, v)
        /// coordinates in the bitmap.
        Vector4 GetColor(std::shared_ptr<IBitmap> Bitmap, Vector2 UV) const override;

        static std::shared_ptr<NearestNeighborClampingSampler> getInstance();
    private:
        NearestNeighborClampingSampler();

        static std::shared_ptr<NearestNeighborClampingSampler> NearestNeighborClampingSampler_instance_value;
    };
}