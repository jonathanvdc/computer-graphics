#pragma once
#include <memory>
#include "ArraySlice.h"
#include "IMesh.h"
#include "IProjection.h"
#include "IShape.h"
#include "ITransformation.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a composite mesh: a collection of meshes grouped
    /// together as a single entity.
    class CompositeMesh : public virtual IMesh
    {
    public:
        /// \brief Creates a new composite mesh from the given array of
        /// meshes.
        CompositeMesh(stdx::ArraySlice<std::shared_ptr<IMesh>> Meshes);

        /// \brief Gets the composite mesh's mesh array.
        stdx::ArraySlice<std::shared_ptr<IMesh>> getMeshes() const;

        /// \brief Projects the mesh on a two-dimensional canvas based on the
        /// given projection.
        std::shared_ptr<IShape> Project(std::shared_ptr<IProjection> Projection) const override;

        /// \brief Transforms the mesh with the given transformation.
        std::shared_ptr<IMesh> Transform(std::shared_ptr<ITransformation<Vector3>> Transform) const override;
    private:
        /// \brief Sets the composite mesh's mesh array.
        void setMeshes(stdx::ArraySlice<std::shared_ptr<IMesh>> value);

        stdx::ArraySlice<std::shared_ptr<IMesh>> Meshes_value;
    };
}