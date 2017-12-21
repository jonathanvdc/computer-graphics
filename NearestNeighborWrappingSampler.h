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
    /// truncated coordinates. This sampler has wrap-around
    /// behavior for points that are outside the bitmap.
    class NearestNeighborWrappingSampler : public virtual ISampler
    {
    public:
        /// \brief Gets or approximates the color at the given (u, v)
        /// coordinates in the bitmap.
        Vector4 GetColor(std::shared_ptr<IBitmap> Bitmap, Vector2 UV) const override;

        static std::shared_ptr<NearestNeighborWrappingSampler> getInstance();
    private:
        NearestNeighborWrappingSampler();

        static std::shared_ptr<NearestNeighborWrappingSampler> NearestNeighborWrappingSampler_instance_value;
    };
}