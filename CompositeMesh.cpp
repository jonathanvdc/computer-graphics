#include "CompositeMesh.h"

#include <memory>
#include "ArraySlice.h"
#include "CompositeShape.h"
#include "IMesh.h"
#include "IProjection.h"
#include "IShape.h"
#include "ITransformation.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new composite mesh from the given array of
/// meshes.
CompositeMesh::CompositeMesh(stdx::ArraySlice<std::shared_ptr<IMesh>> Meshes)
{
    this->setMeshes(Meshes);
}

/// \brief Projects the mesh on a two-dimensional canvas based on the
/// given projection.
std::shared_ptr<IShape> CompositeMesh::Project(std::shared_ptr<IProjection> Projection) const
{
    auto meshes = this->getMeshes();
    stdx::ArraySlice<std::shared_ptr<IShape>> shapes(meshes.GetLength());
    for (int i = 0; i < shapes.GetLength(); ++i)
        shapes[i] = meshes[i]->Project(Projection);
    return std::make_shared<CompositeShape>(shapes);
}

/// \brief Transforms the mesh with the given transformation.
std::shared_ptr<IMesh> CompositeMesh::Transform(std::shared_ptr<ITransformation<Vector3>> Transform) const
{
    auto meshes = this->getMeshes();
    stdx::ArraySlice<std::shared_ptr<IMesh>> results(meshes.GetLength());
    for (int i = 0; i < results.GetLength(); ++i)
        results[i] = meshes[i]->Transform(Transform);
    return std::make_shared<CompositeMesh>(results);
}

/// \brief Sets the composite mesh's mesh array.
void CompositeMesh::setMeshes(stdx::ArraySlice<std::shared_ptr<IMesh>> value)
{
    this->Meshes_value = value;
}

/// \brief Gets the composite mesh's mesh array.
stdx::ArraySlice<std::shared_ptr<IMesh>> CompositeMesh::getMeshes() const
{
    return this->Meshes_value;
}