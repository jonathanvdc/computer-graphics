#include "NearestNeighborWrappingSampler.h"

#include <memory>
#include "IBitmap.h"
#include "ISampler.h"
#include "ISurface.h"
#include "Vector2.h"
#include "Vector4.h"

using namespace Engine;

NearestNeighborWrappingSampler::NearestNeighborWrappingSampler()
{ }

/// \brief Gets or approximates the color at the given (u, v)
/// coordinates in the bitmap.
Vector4 NearestNeighborWrappingSampler::GetColor(std::shared_ptr<IBitmap> Bitmap, Vector2 UV) const
{
    int width = (int)Bitmap->getWidth();
    int height = (int)Bitmap->getHeight();
    int u = (int)UV.X;
    int v = (int)UV.Y;
    while (u < 0)
        u += width;
    while (v < 0)
        v += height;
    return Bitmap->getItem(u % width, v % height);
}

std::shared_ptr<NearestNeighborWrappingSampler> NearestNeighborWrappingSampler::getInstance()
{
    if (NearestNeighborWrappingSampler::NearestNeighborWrappingSampler_instance_value == nullptr)
        NearestNeighborWrappingSampler::NearestNeighborWrappingSampler_instance_value = std::shared_ptr<NearestNeighborWrappingSampler>(new NearestNeighborWrappingSampler());

    return NearestNeighborWrappingSampler::NearestNeighborWrappingSampler_instance_value;
}

std::shared_ptr<NearestNeighborWrappingSampler> NearestNeighborWrappingSampler::NearestNeighborWrappingSampler_instance_value = nullptr;