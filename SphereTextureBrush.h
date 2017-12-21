#pragma once
#include <memory>
#include "IBitmap.h"
#include "IBrush3.h"
#include "ISampler.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a brush that uses a spherical projection to apply
    /// an image to a mesh.
    class SphereTextureBrush : public virtual IBrush3
    {
    public:
        /// \brief Creates a new spherical texture brush from the given
        /// center of the sphere, texture map and sampler.
        SphereTextureBrush(Vector3 center, std::shared_ptr<IBitmap> texture, std::shared_ptr<ISampler> sampler);

        /// \brief Gets the brush's color at the given position, encoded as a
        /// three-dimensional double-precision vector.
        Vector4 GetColor(Vector3 Position) override;
    private:
        /// \brief The center of the sphere texture's sphere.
        Vector3 center;
        /// \brief The spherical texture brush's sampler.
        std::shared_ptr<ISampler> sampler;
        /// \brief The texture map this spherical texture brush is based on.
        std::shared_ptr<IBitmap> texture;
    };
}