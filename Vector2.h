#pragma once
#include <cmath>

namespace Engine
{
    /// \brief Defines a two-dimensional vector.
    struct Vector2
    {
        /// \brief Creates a new two-dimensional vector at the origin.
        Vector2();
        /// \brief Creates a new two-dimensional vector, assigning the given
        /// value to each component of the vector.
        Vector2(double Uniform);
        /// \brief Creates a new two-dimensional vector from the given
        /// coordinates.
        Vector2(double X, double Y);

        /// \brief Calculates the dot product of this vector and the given
        /// vector.
        double Dot(Vector2 Other) const;

        /// \brief Computes this two-dimensional vector's normalized
        /// counterpart.
        Vector2 Normalize() const;

        /// \brief Computes this two-dimensional vector's length.
        double getLength() const;

        /// \brief Computes the sum of two vectors.
        Vector2 operator+(Vector2 Other) const;

        /// \brief Subtracts the given vector from this vector, and returns
        /// the result.
        Vector2 operator-(Vector2 Other) const;

        /// \brief Scales this vector uniformly by the given factor.
        Vector2 operator*(double Scale) const;

        /// \brief Divides this vector uniformly by the given factor.
        Vector2 operator/(double Scale) const;

        /// \brief Checks if this vector is equal to the given vector.
        bool operator==(Vector2 Other) const;

        /// \brief Checks if this vector is not equal to the given  vector.
        bool operator!=(Vector2 Other) const;

        /// \brief Computes the sum of two vectors.
        Vector2& operator+=(Vector2 Other);

        /// \brief Scales this vector uniformly by the given factor.
        Vector2& operator*=(double Scale);

        /// \brief Subtracts the given vector from this vector, and returns
        /// the result.
        Vector2& operator-=(Vector2 Other);

        /// \brief Divides this vector uniformly by the given factor.
        Vector2& operator/=(double Scale);

        /// \brief The vector's X-coordinate.
        double X;
        /// \brief The vector's Y-coordinate.
        double Y;
    };
}