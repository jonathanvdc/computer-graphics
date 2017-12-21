#pragma once
#include <memory>
#include "ITransformation.h"

namespace Engine
{
    /// \brief Defines a triangle as a set of three points.
    template<typename T>
    struct Triangle
    {
        /// \brief Creates a new empty triangle at the origin.
        Triangle();
        /// \brief Creates a triangle from the given points.
        Triangle(T A, T B, T C);

        /// \brief Computes the transformation of this triangle, using the
        /// given transform.
        Triangle<T> Transform(std::shared_ptr<ITransformation<T>> Transform) const;

        /// \brief The triangle's first point.
        T A;
        /// \brief The triangle's second point.
        T B;
        /// \brief The triangle's third point.
        T C;
    };
}

#include "Triangle.hxx"