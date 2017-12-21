#include "PerspectiveProjection.h"

#include "IProjection.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new perspective projection based on the given
/// projection distance.
PerspectiveProjection::PerspectiveProjection(double d)
    : d(d)
{ }

/// \brief Projects the two-dimensional vector onto a two-dimensional
/// plane.
Vector2 PerspectiveProjection::Project(Vector3 Value) const
{
    double scale = -this->d / Value.Z;
    return Vector2(Value.X * scale, Value.Y * scale);
}