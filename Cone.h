#pragma once
#include <memory>
#include "ArraySlice.h"
#include "ComplexMesh.h"
#include "Face.h"
#include "ISkin.h"
#include "Polyhedron.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a cone mesh.
    class Cone : public ComplexMesh
    {
    public:
        /// \brief Creates a new cone mesh from the given arguments.
        Cone(double Height, int N, std::shared_ptr<ISkin> Skin);

        /// \brief Creates a single face that encompasses the cone's base.
        Face CreateBaseFace() const;

        /// \brief Creates an array of points for the cone's base.
        stdx::ArraySlice<Vector3> CreateBasePoints(double BaseHeight) const;

        /// \brief Gets the cone's height.
        double getHeight() const;

        /// \brief Gets the number of points the base of the cone has.
        int getN() const;

        /// \brief Gets this mesh's associated skin.
        std::shared_ptr<ISkin> getSkin() const;

        /// \brief "Lowers" this complex mesh into a polyhedron.
        std::shared_ptr<Polyhedron> Lower() const override;
    private:
        /// \brief Sets the cone's height.
        void setHeight(double value);

        /// \brief Sets the number of points the base of the cone has.
        void setN(int value);

        /// \brief Sets this mesh's associated skin.
        void setSkin(std::shared_ptr<ISkin> value);

        double Height_value;
        int N_value;
        std::shared_ptr<ISkin> Skin_value;
    };
}