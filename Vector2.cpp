#include "Vector2.h"

#include <cmath>

using namespace Engine;

/// \brief Creates a new two-dimensional vector at the origin.
Vector2::Vector2()
    : X(0.0), Y(0.0)
{ }

/// \brief Creates a new two-dimensional vector, assigning the given
/// value to each component of the vector.
Vector2::Vector2(double Uniform)
    : X(Uniform), Y(Uniform)
{ }

/// \brief Creates a new two-dimensional vector from the given
/// coordinates.
Vector2::Vector2(double X, double Y)
    : X(X), Y(Y)
{ }

/// \brief Calculates the dot product of this vector and the given
/// vector.
double Vector2::Dot(Vector2 Other) const
{
    return this->X * Other.X + this->Y * Other.Y;
}

/// \brief Computes this two-dimensional vector's normalized
/// counterpart.
Vector2 Vector2::Normalize() const
{
    return *this / this->getLength();
}

/// \brief Computes this two-dimensional vector's length.
double Vector2::getLength() const
{
    return std::hypot(this->X, this->Y);
}

/// \brief Computes the sum of two vectors.
Vector2 Vector2::operator+(Vector2 Other) const
{
    return Vector2(this->X + Other.X, this->Y + Other.Y);
}

/// \brief Subtracts the given vector from this vector, and returns
/// the result.
Vector2 Vector2::operator-(Vector2 Other) const
{
    return Vector2(this->X - Other.X, this->Y - Other.Y);
}

/// \brief Scales this vector uniformly by the given factor.
Vector2 Vector2::operator*(double Scale) const
{
    return Vector2(this->X * Scale, this->Y * Scale);
}

/// \brief Divides this vector uniformly by the given factor.
Vector2 Vector2::operator/(double Scale) const
{
    return Vector2(this->X / Scale, this->Y / Scale);
}

/// \brief Checks if this vector is equal to the given vector.
bool Vector2::operator==(Vector2 Other) const
{
    return this->X == Other.X && this->Y == Other.Y;
}

/// \brief Checks if this vector is not equal to the given  vector.
bool Vector2::operator!=(Vector2 Other) const
{
    return this->X != Other.X || this->Y != Other.Y;
}

/// \brief Computes the sum of two vectors.
Vector2& Vector2::operator+=(Vector2 Other)
{
    return *this = *this + Other;
}

/// \brief Scales this vector uniformly by the given factor.
Vector2& Vector2::operator*=(double Scale)
{
    return *this = *this * Scale;
}

/// \brief Subtracts the given vector from this vector, and returns
/// the result.
Vector2& Vector2::operator-=(Vector2 Other)
{
    return *this = *this - Other;
}

/// \brief Divides this vector uniformly by the given factor.
Vector2& Vector2::operator/=(double Scale)
{
    return *this = *this / Scale;
}