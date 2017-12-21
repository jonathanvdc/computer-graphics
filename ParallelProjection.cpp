#include "ParallelProjection.h"

#include "IProjection.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new parallel projection.
ParallelProjection::ParallelProjection()
{ }

/// \brief Projects the two-dimensional vector onto a two-dimensional
/// plane.
Vector2 ParallelProjection::Project(Vector3 Value) const
{
    return Value.getXY();
}