#pragma once
#include <cmath>
#include <functional>
#include "Vector2.h"

namespace Engine
{
    /// \brief Defines a three-dimensional vector.
    struct Vector3
    {
        /// \brief Creates a new three-dimensional vector at the origin.
        Vector3();
        /// \brief Creates a new three-dimensional vector, assigning the
        /// given value to each component of the vector.
        Vector3(double Uniform);
        /// \brief Creates a new three-dimensional vector from the given
        /// two-dimensional vector and the given Z-coordinate.
        Vector3(Vector2 XY, double Z);
        /// \brief Creates a new three-dimensional vector based on the given
        /// coordinates.
        Vector3(double X, double Y, double Z);

        /// \brief Calculates the cross product of this vector and the given
        /// vector.
        Vector3 Cross(Vector3 Other) const;

        /// \brief Calculates the dot product of this vector and the given
        /// vector.
        double Dot(Vector3 Other) const;

        /// \brief Computes this three-dimensional vector's normalized
        /// counterpart.
        Vector3 Normalize() const;

        /// \brief Converts this vector to its representation in polar
        /// coordinates, where:  * X = r,  * Y = theta,  * Z = phi
        Vector3 ToPolar() const;

        /// \brief Computes this three-dimensional vector's length.
        double getLength() const;

        /// \brief Computes the square of this three-dimensional vector's
        /// length.
        double getLengthSquared() const;

        /// \brief Gets the two-dimensional vector (X, Y).
        Vector2 getXY() const;
        /// \brief Sets the two-dimensional vector (X, Y).
        void setXY(Vector2 value);

        int GetHashCode() const;

        /// \brief Computes the sum of two vectors.
        Vector3 operator+(Vector3 Other) const;

        /// \brief Subtracts the given vector from this vector, and returns
        /// the result.
        Vector3 operator-(Vector3 Other) const;

        /// \brief Scales this vector uniformly by the given factor.
        Vector3 operator*(double Scale) const;

        /// \brief Divides this vector uniformly by the given factor.
        Vector3 operator/(double Scale) const;

        /// \brief Checks if this vector is equal to the given vector.
        bool operator==(Vector3 Other) const;

        /// \brief Checks if this vector is not equal to the given vector.
        bool operator!=(Vector3 Other) const;

        /// \brief Computes the sum of two vectors.
        Vector3& operator+=(Vector3 Other);

        /// \brief Scales this vector uniformly by the given factor.
        Vector3& operator*=(double Scale);

        /// \brief Subtracts the given vector from this vector, and returns
        /// the result.
        Vector3& operator-=(Vector3 Other);

        /// \brief Divides this vector uniformly by the given factor.
        Vector3& operator/=(double Scale);

        /// \brief The vector's X-coordinate.
        double X;
        /// \brief The vector's Y-coordinate.
        double Y;
        /// \brief The vector's Z-coordinate.
        double Z;
    };
}
namespace std
{
    template<>
    struct hash<Engine::Vector3>
    {
        std::size_t operator()(const Engine::Vector3& Arg) const
        {
            return Arg.GetHashCode();
        }
    };
}