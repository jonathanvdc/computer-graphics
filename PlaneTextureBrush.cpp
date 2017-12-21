#include "PlaneTextureBrush.h"

#include <memory>
#include <algorithm>
#include "Vector3.h"
#include "IBrush3.h"
#include "vector.hh"

using namespace Engine;

PlaneTextureBrush::PlaneTextureBrush(Vector3 PlanePosition, Vector3 DimensionU, Vector3 DimensionV, std::shared_ptr<IBitmap> Texture, std::shared_ptr<ISampler> Sampler)
	: planePos(PlanePosition), texture(Texture), sampler(Sampler)
{
	Vector3 c = DimensionU.Cross(DimensionV);
	Matrix<2> trans;
	trans(1, 1) = DimensionU.X;
	trans(1, 2) = DimensionU.Y;
	trans(1, 3) = DimensionU.Z;
	trans(2, 1) = DimensionV.X;
	trans(2, 2) = DimensionV.Y;
	trans(2, 3) = DimensionV.Z;
	trans(3, 1) = c.X;
	trans(3, 2) = c.Y;
	trans(3, 3) = c.Z;
	trans.inv();
	this->transformation = trans;
}

PlaneTextureBrush::PlaneTextureBrush(Vector3 PlanePosition, Matrix<2> Transformation, std::shared_ptr<IBitmap> Texture, std::shared_ptr<ISampler> Sampler)
	: planePos(PlanePosition), transformation(Transformation), texture(Texture), sampler(Sampler)
{ }

Vector3 operator*(Vector3 lhs, Matrix<2> rhs)
{
	double input[3] = { lhs.X, lhs.Y, lhs.Z };
	double output[3] = { 0.0, 0.0, 0.0 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			output[i] += input[j] * rhs(j + 1, i + 1);
		}
	}

	return Vector3(output[0], output[1], output[2]);
}

Vector4 PlaneTextureBrush::GetColor(Vector3 Position)
{
	auto offset = Position - planePos;
	auto uvw = offset * transformation;

	double width = texture->getWidth();
	double height = texture->getHeight();

	return this->sampler->GetColor(texture, Vector2(uvw.X * width, uvw.Y * height));
}