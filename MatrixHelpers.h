#pragma once
#include "vector.hh"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
	Matrix<3> Translate(Vector3 Translation);
	Matrix<3> RotateX(double Angle);
	Matrix<3> RotateY(double Angle);
	Matrix<3> RotateZ(double Angle);
	Matrix<3> Scale(Vector3 Scale);
	Matrix<3> Scale(double Uniform);

	Matrix<3> EyePointTransform(Vector3 EyePoint);
}

