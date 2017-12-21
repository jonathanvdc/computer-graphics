#pragma once
#include <memory>
#include "IMesh.h"
#include "IProjection.h"
#include "IShape.h"
#include "ITransformation.h"
#include "Polyhedron.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a base class for complex meshes: meshes that are
    /// converted to more primitive meshes (specifically,
    /// polyhedra) before rendering.
    struct ComplexMesh : public virtual IMesh
    {
        ComplexMesh();

        /// \brief "Lowers" this complex mesh into a polyhedron.
        virtual std::shared_ptr<Polyhedron> Lower() const = 0;

        /// \brief Projects the mesh on a two-dimensional canvas based on the
        /// given projection.
        std::shared_ptr<IShape> Project(std::shared_ptr<IProjection> Projection) const override;

        /// \brief Transforms the mesh with the given transformation.
        std::shared_ptr<IMesh> Transform(std::shared_ptr<ITransformation<Vector3>> Value) const override;
    };
}