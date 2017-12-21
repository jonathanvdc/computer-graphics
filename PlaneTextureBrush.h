#pragma once
#include <memory>
#include "Vector3.h"
#include "IBrush3.h"
#include "IBitmap.h"
#include "ISampler.h"
#include "vector.hh"

namespace Engine
{
	class PlaneTextureBrush : public virtual IBrush3
	{
	public:
		PlaneTextureBrush(Vector3 PlanePosition, Vector3 DimensionU, Vector3 DimensionV, std::shared_ptr<IBitmap> Texture, std::shared_ptr<ISampler> Sampler);
		PlaneTextureBrush(Vector3 PlanePosition, Matrix<2> Transformation, std::shared_ptr<IBitmap> Texture, std::shared_ptr<ISampler> Sampler);

		Vector4 GetColor(Vector3 Position);

	private:
		Vector3 planePos;
		Matrix<2> transformation;
		std::shared_ptr<IBitmap> texture;
		std::shared_ptr<ISampler> sampler;
	};
}
