/*
 * vector.cc
 * Copyright (C) 2011  Bart Sas
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "vector.hh"

#include <cassert>
#include <cmath>
#include <iomanip>


////////////////////////////////////////////////////////////////////////////////
// The vector class                                                           //
////////////////////////////////////////////////////////////////////////////////

double Vector3D::*const Vector3D::elts[] =
{
	&Vector3D::x,
	&Vector3D::y,
	&Vector3D::z,
};

Vector3D::Vector3D()
	: infty(false)
	, x(0)
	, y(0)
	, z(0)
{
	// Does nothing...
}

Vector3D::Vector3D(const double x_init,
	const double y_init,
	const double z_init,
	const bool   infty_init)
	: infty(infty_init)
	, x(x_init)
	, y(y_init)
	, z(z_init)
{
	// Does nothing...
}

Vector3D::Vector3D(const Vector3D &original,
	const bool      infty_init)
	: infty(infty_init)
	, x(original.x)
	, y(original.y)
	, z(original.z)
{
	// Does nothing...
}

Vector3D::Vector3D(const Vector3D &original)
	: infty(original.infty)
	, x(original.x)
	, y(original.y)
	, z(original.z)
{
	// Does nothing...
}

Vector3D::~Vector3D()
{
	// Does nothing...
}

Vector3D Vector3D::point(const double x,
	const double y,
	const double z)
{
	return Vector3D(x, y, z, false);
}

Vector3D Vector3D::point(const Vector3D &original)
{
	return Vector3D(original, false);
}

Vector3D Vector3D::vector(const double x,
	const double y,
	const double z)
{
	return Vector3D(x, y, z, true);
}

Vector3D Vector3D::vector(const Vector3D &original)
{
	return Vector3D(original, true);
}

bool Vector3D::is_point() const
{
	return !infty;
}

bool Vector3D::is_vector() const
{
	return infty;
}

#define NR_DIMS 3

Vector3D &Vector3D::operator=(const Vector3D &original)
{
	for (int i = 0; i < NR_DIMS; i++)
	{
		this->*elts[i] = original.*elts[i];
	}

	infty = original.infty;
	return *this;
}

Vector3D &Vector3D::operator+=(const Vector3D &rhs)
{
	for (int i = 0; i < NR_DIMS; i++)
	{
		this->*elts[i] += rhs.*elts[i];
	}

	infty = infty && rhs.infty; // The result is only a vector if both operands are vectors themselves.
	return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &rhs)
{
	for (int i = 0; i < NR_DIMS; i++)
	{
		this->*elts[i] -= rhs.*elts[i];
	}

	infty = infty == rhs.infty; // if we're subtracting two points or two vectors the result is a vector, otherwise it's a point
	return *this;
}

Vector3D &Vector3D::operator*=(const double rhs)
{
	for (int i = 0; i < NR_DIMS; i++)
	{
		this->*elts[i] *= rhs;
	}

	return *this;
}

Vector3D &Vector3D::operator*=(const Matrix<NR_DIMS> &rhs)
{
	//In order for the transformation to be valid: this should be true
	assert(rhs(1, 4) == 0);
	assert(rhs(2, 4) == 0);
	assert(rhs(3, 4) == 0);
	assert(rhs(4, 4) == 1);

	double temp[NR_DIMS + 1];

	// Make a copy of the original elements of this vector.
	for (int i = 0; i < NR_DIMS; i++)
	{
		temp[i] = this->*elts[i];
	}

	temp[NR_DIMS] = infty ? 0 : 1;

	for (int i = 0; i < NR_DIMS; i++)
	{
		this->*elts[i] = 0;

		// Multiply the original vector with the i-th column of the matrix.
		for (int j = 0; j <= NR_DIMS; j++)
		{
			this->*elts[i] += temp[j] * rhs.values[j][i];
		}
	}

	return *this;
}

double Vector3D::dot(const Vector3D &rhs) const
{
	double result = 0;

	for (int i = 0; i < NR_DIMS; i++)
	{
		result += this->*elts[i] * rhs.*elts[i];
	}

	return result;
}

Vector3D &Vector3D::cross_equals(const Vector3D &rhs)
{
	double temp[NR_DIMS];

	// Make a copy of the original elements of this vector.
	for (int i = 0; i < NR_DIMS; i++)
	{
		temp[i] = this->*elts[i];
	}

	for (int k = 0; k < NR_DIMS; k++)
	{
		const int i = (k + 1) % NR_DIMS;
		const int j = (k + 2) % NR_DIMS;

		this->*elts[k] = temp[i] * rhs.*elts[j] - temp[j] * rhs.*elts[i];
	}

	infty = true; // The result is always a vector.
	return *this;
}

double Vector3D::length() const
{
	double squared_length = 0;

	for (int i = 0; i < NR_DIMS; ++i)
	{
		squared_length += this->*elts[i] * this->*elts[i];
	}

	return std::sqrt(squared_length);
}

void Vector3D::normalise()
{
	*this /= length();
}

void Vector3D::print(std::ostream &output_stream,
	const int     elt_width) const
{
	output_stream << "(";

	for (int i = 0; i < NR_DIMS; ++i)
	{
		output_stream << std::setw(elt_width) << this->*elts[i] << ", ";
	}

	output_stream << std::setw(elt_width) << (infty ? 0.0 : 1.0) << ")";
}

Vector3D operator+(const Vector3D &arg)
{
	return arg;
}

Vector3D operator-(Vector3D arg)
{
	return arg *= -1;
}

Vector3D operator+(Vector3D        lhs,
	const Vector3D &rhs)
{
	return lhs += rhs;
}

Vector3D operator-(Vector3D        lhs,
	const Vector3D &rhs)
{
	return lhs -= rhs;
}

Vector3D operator*(Vector3D     lhs,
	const double rhs)
{
	return lhs *= rhs;
}

Vector3D operator*(const double lhs,
	Vector3D     rhs)
{
	return rhs * lhs;
}

Vector3D &operator/=(Vector3D    &lhs,
	const double rhs)
{
	return lhs *= 1 / rhs;
}

Vector3D operator/(Vector3D     lhs,
	const double rhs)
{
	return lhs /= rhs;
}

Vector3D operator*(Vector3D      lhs,
	const Matrix<NR_DIMS> &rhs)
{
	return lhs *= rhs;
}

double Vector3D::dot(const Vector3D &lhs,
	const Vector3D &rhs)
{
	return lhs.dot(rhs);
}

Vector3D Vector3D::cross(Vector3D        lhs,
	const Vector3D &rhs)
{
	return lhs.cross_equals(rhs);
}

Vector3D Vector3D::normalise(Vector3D arg)
{
	arg.normalise();
	return arg;
}

std::ostream &operator<<(std::ostream   &output_stream,
	const Vector3D &vector)
{
	vector.print(output_stream);
	return output_stream;
}
