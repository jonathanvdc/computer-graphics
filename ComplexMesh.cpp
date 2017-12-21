#include "ComplexMesh.h"

#include <memory>
#include "IMesh.h"
#include "IProjection.h"
#include "IShape.h"
#include "ITransformation.h"
#include "Polyhedron.h"
#include "Vector3.h"

using namespace Engine;

ComplexMesh::ComplexMesh()
{ }

/// \brief Projects the mesh on a two-dimensional canvas based on the
/// given projection.
std::shared_ptr<IShape> ComplexMesh::Project(std::shared_ptr<IProjection> Projection) const
{
    return this->Lower()->Project(Projection);
}

/// \brief Transforms the mesh with the given transformation.
std::shared_ptr<IMesh> ComplexMesh::Transform(std::shared_ptr<ITransformation<Vector3>> Value) const
{
    return this->Lower()->Transform(Value);
}