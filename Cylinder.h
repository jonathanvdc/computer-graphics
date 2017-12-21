#pragma once
#include <memory>
#include "ComplexMesh.h"
#include "ISkin.h"
#include "Polyhedron.h"

namespace Engine
{
    /// \brief Defines a cylinder mesh.
    class Cylinder : public ComplexMesh
    {
    public:
        /// \brief Creates a new cylinder mesh based on a given height, the
        /// number of points at its base and a skin.
        Cylinder(double Height, int N, std::shared_ptr<ISkin> Skin);
        /// \brief Creates a new cylinder mesh based on a given height, the
        /// number of points at its base, a skin and a flag that
        /// indicates whether the cylinder has a top and bottom face.
        Cylinder(double Height, int N, std::shared_ptr<ISkin> Skin, bool HasCaps);

        /// \brief Gets a boolean value that indicates whether the cylinder
        /// has a top and bottom face.
        bool getHasCaps() const;

        /// \brief Gets the cylinder's height.
        double getHeight() const;

        /// \brief Gets the number of points at the cylinder's base.
        int getN() const;

        /// \brief Gets this mesh's associated skin.
        std::shared_ptr<ISkin> getSkin() const;

        /// \brief "Lowers" this complex mesh into a polyhedron.
        std::shared_ptr<Polyhedron> Lower() const override;
    private:
        /// \brief Sets a boolean value that indicates whether the cylinder
        /// has a top and bottom face.
        void setHasCaps(bool value);

        /// \brief Sets the cylinder's height.
        void setHeight(double value);

        /// \brief Sets the number of points at the cylinder's base.
        void setN(int value);

        /// \brief Sets this mesh's associated skin.
        void setSkin(std::shared_ptr<ISkin> value);

        bool HasCaps_value;
        double Height_value;
        int N_value;
        std::shared_ptr<ISkin> Skin_value;
    };
}