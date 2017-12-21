#pragma once

#include "vector.hh"
#include "ITransformation.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
	class MatrixTransformation : public virtual ITransformation<Vector3>
	{
	public:		
		MatrixTransformation()
		{
			this->setTransformation(Matrix<3>());
		}
		MatrixTransformation(Matrix<3> Transformation)
		{
			this->setTransformation(Transformation);
		}

		Matrix<3> getTransformation() const
		{
			return Transformation_value;
		}

		Vector3 Transform(Vector3 Value) const override
		{
			auto input = Vector3D::point(Value.X, Value.Y, Value.Z);
			auto output = input * this->getTransformation();
			return{ output.x, output.y, output.z };
		}

		Vector3 TransformDirection(Vector3 Value) const
		{
			auto input = Vector3D::vector(Value.X, Value.Y, Value.Z);
			auto output = input * this->getTransformation();
			return{ output.x, output.y, output.z };
		}

		std::shared_ptr<ITransformation<Vector3>> Invert() const
		{
			return std::make_shared<MatrixTransformation>(Matrix<3>::inv(this->getTransformation()));
		}

	private:
		void setTransformation(Matrix<3> Value)
		{
			this->Transformation_value = Value;
		}

		Matrix<3> Transformation_value;
	};
}