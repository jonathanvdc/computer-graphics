#pragma once
#include <memory>
#include "ComplexMesh.h"
#include "ISkin.h"
#include "Polyhedron.h"

namespace Engine
{
    /// \brief Defines a sphere mesh.
    class Sphere : public ComplexMesh
    {
    public:
        /// \brief Creates a new sphere mesh from the number of iterations
        /// and a flag that tells if the sphere is to be filled.
        Sphere(int N, std::shared_ptr<ISkin> Skin);

        /// \brief Gets the number of iterations that are used to approximate
        /// a sphere.
        int getN() const;

        /// \brief Gets this mesh's associated skin.
        std::shared_ptr<ISkin> getSkin() const;

        /// \brief "Lowers" this complex mesh into a polyhedron.
        std::shared_ptr<Polyhedron> Lower() const override;
    private:
        /// \brief Sets the number of iterations that are used to approximate
        /// a sphere.
        void setN(int value);

        /// \brief Sets this mesh's associated skin.
        void setSkin(std::shared_ptr<ISkin> value);

        int N_value;
        std::shared_ptr<ISkin> Skin_value;
    };
}