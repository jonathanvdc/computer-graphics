#pragma once
#include "IProjection.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a perspective projection.
    class PerspectiveProjection : public virtual IProjection
    {
    public:
        /// \brief Creates a new perspective projection based on the given
        /// projection distance.
        PerspectiveProjection(double d);

        /// \brief Projects the two-dimensional vector onto a two-dimensional
        /// plane.
        Vector2 Project(Vector3 Value) const override;
    private:
        /// \brief The projection distance.
        double d;
    };
}