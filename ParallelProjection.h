#pragma once
#include "IProjection.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a parallel projection.
    struct ParallelProjection : public virtual IProjection
    {
        /// \brief Creates a new parallel projection.
        ParallelProjection();

        /// \brief Projects the two-dimensional vector onto a two-dimensional
        /// plane.
        Vector2 Project(Vector3 Value) const override;
    };
}