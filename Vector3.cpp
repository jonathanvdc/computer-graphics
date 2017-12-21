#include "Vector3.h"

#include <cmath>
#include <functional>
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a new three-dimensional vector at the origin.
Vector3::Vector3()
    : X(0.0), Y(0.0), Z(0.0)
{ }

/// \brief Creates a new three-dimensional vector, assigning the
/// given value to each component of the vector.
Vector3::Vector3(double Uniform)
    : X(Uniform), Y(Uniform), Z(Uniform)
{ }

/// \brief Creates a new three-dimensional vector from the given
/// two-dimensional vector and the given Z-coordinate.
Vector3::Vector3(Vector2 XY, double Z)
{
    this->setXY(XY);
    this->Z = Z;
}

/// \brief Creates a new three-dimensional vector based on the given
/// coordinates.
Vector3::Vector3(double X, double Y, double Z)
    : X(X), Y(Y), Z(Z)
{ }

/// \brief Calculates the cross product of this vector and the given
/// vector.
Vector3 Vector3::Cross(Vector3 Other) const
{
    return Vector3(this->Y * Other.Z - this->Z * Other.Y, 
                   this->Z * Other.X - this->X * Other.Z, 
                   this->X * Other.Y - this->Y * Other.X);
}

/// \brief Calculates the dot product of this vector and the given
/// vector.
double Vector3::Dot(Vector3 Other) const
{
    return this->X * Other.X + this->Y * Other.Y + this->Z * Other.Z;
}

/// \brief Computes this three-dimensional vector's normalized
/// counterpart.
Vector3 Vector3::Normalize() const
{
    return *this / this->getLength();
}

/// \brief Converts this vector to its representation in polar
/// coordinates, where:  * X = r,  * Y = theta,  * Z = phi
Vector3 Vector3::ToPolar() const
{
    double r = this->getLength();
    double theta = std::atan2(this->Y, this->X);
    double phi = std::acos(this->Z / r);
    return Vector3(r, theta, phi);
}

/// \brief Computes this three-dimensional vector's length.
double Vector3::getLength() const
{
    return std::sqrt(this->getLengthSquared());
}

/// \brief Computes the square of this three-dimensional vector's
/// length.
double Vector3::getLengthSquared() const
{
    return this->X * this->X + this->Y * this->Y + this->Z * this->Z;
}

/// \brief Gets the two-dimensional vector (X, Y).
Vector2 Vector3::getXY() const
{
    return Vector2(this->X, this->Y);
}

/// \brief Sets the two-dimensional vector (X, Y).
void Vector3::setXY(Vector2 value)
{
    this->X = value.X;
    this->Y = value.Y;
}

int Vector3::GetHashCode() const
{
    return (int)(std::hash<double>()(this->X) ^ std::hash<double>()(this->Y) ^ std::hash<double>()(this->Z));
}

/// \brief Computes the sum of two vectors.
Vector3 Vector3::operator+(Vector3 Other) const
{
    return Vector3(this->X + Other.X, this->Y + Other.Y, 
                   this->Z + Other.Z);
}

/// \brief Subtracts the given vector from this vector, and returns
/// the result.
Vector3 Vector3::operator-(Vector3 Other) const
{
    return Vector3(this->X - Other.X, this->Y - Other.Y, 
                   this->Z - Other.Z);
}

/// \brief Scales this vector uniformly by the given factor.
Vector3 Vector3::operator*(double Scale) const
{
    return Vector3(this->X * Scale, this->Y * Scale, this->Z * Scale);
}

/// \brief Divides this vector uniformly by the given factor.
Vector3 Vector3::operator/(double Scale) const
{
    return Vector3(this->X / Scale, this->Y / Scale, this->Z / Scale);
}

/// \brief Checks if this vector is equal to the given vector.
bool Vector3::operator==(Vector3 Other) const
{
    return this->X == Other.X && this->Y == Other.Y && 
           this->Z == Other.Z;
}

/// \brief Checks if this vector is not equal to the given vector.
bool Vector3::operator!=(Vector3 Other) const
{
    return this->X != Other.X || this->Y != Other.Y || 
           this->Z != Other.Z;
}

/// \brief Computes the sum of two vectors.
Vector3& Vector3::operator+=(Vector3 Other)
{
    return *this = *this + Other;
}

/// \brief Scales this vector uniformly by the given factor.
Vector3& Vector3::operator*=(double Scale)
{
    return *this = *this * Scale;
}

/// \brief Subtracts the given vector from this vector, and returns
/// the result.
Vector3& Vector3::operator-=(Vector3 Other)
{
    return *this = *this - Other;
}

/// \brief Divides this vector uniformly by the given factor.
Vector3& Vector3::operator/=(double Scale)
{
    return *this = *this / Scale;
}