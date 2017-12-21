#pragma once
#include <cmath>
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a four-dimensional vector.
    struct Vector4
    {
        /// \brief Creates a new four-dimensional vector at the origin.
        Vector4();
        /// \brief Creates a new four-dimensional vector, assigning the given
        /// value to each component of the vector.
        Vector4(double Uniform);
        /// \brief Creates a new four-dimensional vector from the given
        /// three-dimensional vector and the given W-coordinate.
        Vector4(Vector3 XYZ, double W);
        /// \brief Creates a new four-dimensional vector based on the given
        /// coordinates.
        Vector4(double X, double Y, double Z, double W);

        /// \brief Clamps the vector between the given min and max.
        Vector4 Clamp(Vector4 Min, Vector4 Max) const;

        /// \brief Calculates the dot product of this vector and the given
        /// vector.
        double Dot(Vector4 Other) const;

        /// \brief Computes this four-dimensional vector's normalized
        /// counterpart.
        Vector4 Normalize() const;

        /// \brief Applies the "over" alpha blending operator to this color
        /// and the given other color.
        Vector4 Over(Vector4 Other) const;

        /// \brief "Scales" this vector by the other vector by computing
        /// their memberwise product.
        Vector4 Scale(Vector4 Other) const;

        /// \brief Computes this four-dimensional vector's length.
        double getLength() const;

        /// \brief Gets the three-dimensional vector (X, Y, Z).
        Vector3 getXYZ() const;
        /// \brief Sets the three-dimensional vector (X, Y, Z).
        void setXYZ(Vector3 value);

        /// \brief Computes the sum of two vectors.
        Vector4 operator+(Vector4 Other) const;

        /// \brief Subtracts the given vector from this vector, and returns
        /// the result.
        Vector4 operator-(Vector4 Other) const;

        /// \brief Scales this vector uniformly by the given factor.
        Vector4 operator*(double Scale) const;

        /// \brief Divides this vector uniformly by the given factor.
        Vector4 operator/(double Scale) const;

        /// \brief Checks if this vector is equal to the given vector.
        bool operator==(Vector4 Other) const;

        /// \brief Checks if this vector is not equal to the given vector.
        bool operator!=(Vector4 Other) const;

        /// \brief Scales this vector uniformly by the given factor.
        Vector4& operator*=(double Scale);

        /// \brief Computes the sum of two vectors.
        Vector4& operator+=(Vector4 Other);

        /// \brief Divides this vector uniformly by the given factor.
        Vector4& operator/=(double Scale);

        /// \brief Subtracts the given vector from this vector, and returns
        /// the result.
        Vector4& operator-=(Vector4 Other);

        /// \brief The vector's W-coordinate.
        double W;
        /// \brief The vector's X-coordinate.
        double X;
        /// \brief The vector's Y-coordinate.
        double Y;
        /// \brief The vector's Z-coordinate.
        double Z;
    };
}