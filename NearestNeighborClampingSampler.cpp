#include "NearestNeighborClampingSampler.h"

#include <algorithm>
#include <memory>
#include "IBitmap.h"
#include "ISampler.h"
#include "ISurface.h"
#include "Vector2.h"
#include "Vector4.h"

using namespace Engine;

NearestNeighborClampingSampler::NearestNeighborClampingSampler()
{ }

/// \brief Gets or approximates the color at the given (u, v)
/// coordinates in the bitmap.
Vector4 NearestNeighborClampingSampler::GetColor(std::shared_ptr<IBitmap> Bitmap, Vector2 UV) const
{
    int u = std::max<int>(std::min<int>((int)UV.X, (int)Bitmap->getWidth() - 1), 
                          0);
    int v = std::max<int>(std::min<int>((int)UV.Y, (int)Bitmap->getHeight() - 1), 
                          0);
    return Bitmap->getItem(u, v);
}

std::shared_ptr<NearestNeighborClampingSampler> NearestNeighborClampingSampler::getInstance()
{
    if (NearestNeighborClampingSampler::NearestNeighborClampingSampler_instance_value == nullptr)
        NearestNeighborClampingSampler::NearestNeighborClampingSampler_instance_value = std::shared_ptr<NearestNeighborClampingSampler>(new NearestNeighborClampingSampler());

    return NearestNeighborClampingSampler::NearestNeighborClampingSampler_instance_value;
}

std::shared_ptr<NearestNeighborClampingSampler> NearestNeighborClampingSampler::NearestNeighborClampingSampler_instance_value = nullptr;