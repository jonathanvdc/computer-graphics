#include "Vector4.h"

#include <algorithm>
#include <cmath>
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new four-dimensional vector at the origin.
Vector4::Vector4()
    : X(0.0), Y(0.0), Z(0.0), W(0.0)
{ }

/// \brief Creates a new four-dimensional vector, assigning the given
/// value to each component of the vector.
Vector4::Vector4(double Uniform)
    : X(Uniform), Y(Uniform), Z(Uniform), W(Uniform)
{ }

/// \brief Creates a new four-dimensional vector from the given
/// three-dimensional vector and the given W-coordinate.
Vector4::Vector4(Vector3 XYZ, double W)
{
    this->setXYZ(XYZ);
    this->W = W;
}

/// \brief Creates a new four-dimensional vector based on the given
/// coordinates.
Vector4::Vector4(double X, double Y, double Z, double W)
    : X(X), Y(Y), Z(Z), W(W)
{ }

/// \brief Clamps the vector between the given min and max.
Vector4 Vector4::Clamp(Vector4 Min, Vector4 Max) const
{
    return Vector4(std::min<double>(std::max<double>(this->X, Min.X), Max.X), 
                   std::min<double>(std::max<double>(this->Y, Min.Y), Max.Y), 
                   std::min<double>(std::max<double>(this->Z, Min.Z), Max.Z), 
                   std::min<double>(std::max<double>(this->W, Min.W), Max.W));
}

/// \brief Calculates the dot product of this vector and the given
/// vector.
double Vector4::Dot(Vector4 Other) const
{
    return this->X * Other.X + this->Y * Other.Y + this->Z * Other.Z + 
           this->W * Other.W;
}

/// \brief Computes this four-dimensional vector's normalized
/// counterpart.
Vector4 Vector4::Normalize() const
{
    return *this / this->getLength();
}

/// \brief Applies the "over" alpha blending operator to this color
/// and the given other color.
Vector4 Vector4::Over(Vector4 Other) const
{
    double otherAlpha = Other.W * (1.0 - this->W);
    double ao = this->W + otherAlpha;
    auto rgbo = this->getXYZ() * this->W + Other.getXYZ() * otherAlpha;
    return Vector4(rgbo, ao);
}

/// \brief "Scales" this vector by the other vector by computing
/// their memberwise product.
Vector4 Vector4::Scale(Vector4 Other) const
{
    return Vector4(this->X * Other.X, this->Y * Other.Y, 
                   this->Z * Other.Z, this->W * Other.W);
}

/// \brief Computes this four-dimensional vector's length.
double Vector4::getLength() const
{
    return std::sqrt(this->X * this->X + this->Y * this->Y + this->Z * this->Z + 
                     this->W * this->W);
}

/// \brief Gets the three-dimensional vector (X, Y, Z).
Vector3 Vector4::getXYZ() const
{
    return Vector3(this->X, this->Y, this->Z);
}

/// \brief Sets the three-dimensional vector (X, Y, Z).
void Vector4::setXYZ(Vector3 value)
{
    this->X = value.X;
    this->Y = value.Y;
    this->Z = value.Z;
}

/// \brief Computes the sum of two vectors.
Vector4 Vector4::operator+(Vector4 Other) const
{
    return Vector4(this->X + Other.X, this->Y + Other.Y, 
                   this->Z + Other.Z, this->W + Other.W);
}

/// \brief Subtracts the given vector from this vector, and returns
/// the result.
Vector4 Vector4::operator-(Vector4 Other) const
{
    return Vector4(this->X - Other.X, this->Y - Other.Y, 
                   this->Z - Other.Z, this->W - Other.W);
}

/// \brief Scales this vector uniformly by the given factor.
Vector4 Vector4::operator*(double Scale) const
{
    return Vector4(this->X * Scale, this->Y * Scale, this->Z * Scale, 
                   this->W * Scale);
}

/// \brief Divides this vector uniformly by the given factor.
Vector4 Vector4::operator/(double Scale) const
{
    return Vector4(this->X / Scale, this->Y / Scale, this->Z / Scale, 
                   this->W / Scale);
}

/// \brief Checks if this vector is equal to the given vector.
bool Vector4::operator==(Vector4 Other) const
{
    return this->X == Other.X && this->Y == Other.Y && 
           this->Z == Other.Z && this->W == Other.W;
}

/// \brief Checks if this vector is not equal to the given vector.
bool Vector4::operator!=(Vector4 Other) const
{
    return this->X != Other.X || this->Y != Other.Y || 
           this->Z != Other.Z || this->W != Other.W;
}

/// \brief Scales this vector uniformly by the given factor.
Vector4& Vector4::operator*=(double Scale)
{
    return *this = *this * Scale;
}

/// \brief Computes the sum of two vectors.
Vector4& Vector4::operator+=(Vector4 Other)
{
    return *this = *this + Other;
}

/// \brief Divides this vector uniformly by the given factor.
Vector4& Vector4::operator/=(double Scale)
{
    return *this = *this / Scale;
}

/// \brief Subtracts the given vector from this vector, and returns
/// the result.
Vector4& Vector4::operator-=(Vector4 Other)
{
    return *this = *this - Other;
}