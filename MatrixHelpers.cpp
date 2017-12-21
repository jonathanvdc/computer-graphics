#include <cmath>
#include "Helpers.h"
#include "MatrixHelpers.h"

namespace Engine
{
	Matrix<3> Translate(Vector3 Offset)
	{
		Matrix<3> result;
		result(4, 1) = Offset.X;
		result(4, 2) = Offset.Y;
		result(4, 3) = Offset.Z;
		return result;
	}

	Matrix<3> RotateX(double Angle)
	{
		Matrix<3> result;
		double sinPhi = std::sin(Angle);
		double cosPhi = std::cos(Angle);
		result(2, 2) = cosPhi;
		result(2, 3) = sinPhi;
		result(3, 2) = -sinPhi;
		result(3, 3) = cosPhi;
		return result;
	}

	Matrix<3> RotateY(double Angle)
	{
		Matrix<3> result;
		double sinPhi = std::sin(Angle);
		double cosPhi = std::cos(Angle);
		result(1, 1) = cosPhi;
		result(1, 3) = -sinPhi;
		result(3, 1) = sinPhi;
		result(3, 3) = cosPhi;
		return result;
	}

	Matrix<3> RotateZ(double Angle)
	{
		Matrix<3> result;
		double sinPhi = std::sin(Angle);
		double cosPhi = std::cos(Angle);
		result(1, 1) = cosPhi;
		result(2, 1) = -sinPhi;
		result(2, 2) = cosPhi;
		result(1, 2) = sinPhi;
		return result;
	}

	Matrix<3> Scale(Vector3 Scale)
	{
		Matrix<3> result;
		result(1, 1) = Scale.X;
		result(2, 2) = Scale.Y;
		result(3, 3) = Scale.Z;
		return result;
	}

	Matrix<3> Scale(double Uniform)
	{
		Matrix<3> result;
		result(1, 1) = Uniform;
		result(2, 2) = Uniform;
		result(3, 3) = Uniform;
		return result;
	}

	Matrix<3> EyePointTransform(Vector3 Eye)
	{
		auto polar = Eye.ToPolar();
		double r = polar.X;
		double theta = polar.Y;
		double phi = polar.Z;

		double sint = std::sin(theta);
		double cost = std::cos(theta);
		double sinp = std::sin(phi);
		double cosp = std::cos(phi);

		Matrix<3> m;

		m(1, 1) = -sint;
		m(1, 2) = -cost * cosp;
		m(1, 3) = cost * sinp;

		m(2, 1) = cost;
		m(2, 2) = -sint * cosp;
		m(2, 3) = sint * sinp;

		m(3, 2) = sinp;
		m(3, 3) = cosp;

		m(4, 3) = -r;

		return m;
	}
}