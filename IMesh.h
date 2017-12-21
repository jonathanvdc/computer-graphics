#pragma once
#include <memory>
#include "IProjection.h"
#include "IShape.h"
#include "ITransformation.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Provides a common interface for meshes, that is, three
    /// dimensional objects that can be projected onto a
    /// two-dimensional canvas.
    struct IMesh
    {
        /// \brief Projects the mesh on a two-dimensional canvas based on the
        /// given projection.
        virtual std::shared_ptr<IShape> Project(std::shared_ptr<IProjection> Projection) const = 0;

        /// \brief Transforms the mesh with the given transformation.
        virtual std::shared_ptr<IMesh> Transform(std::shared_ptr<ITransformation<Vector3>> Value) const = 0;
    };
}