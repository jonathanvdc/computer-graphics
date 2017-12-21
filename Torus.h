#pragma once
#include <memory>
#include "ComplexMesh.h"
#include "ISkin.h"
#include "Polyhedron.h"

namespace Engine
{
    /// \brief Defines a torus mesh based on a radius, a hole radius,
    class Torus : public ComplexMesh
    {
    public:
        /// \brief Creates a new torus mesh from the given arguments.
        Torus(double Radius, double HoleRadius, int N, int M, std::shared_ptr<ISkin> Skin);

        /// \brief Gets the torus' hole radius.
        double getHoleRadius() const;

        /// \brief Gets the number of vertical segments in the torus mesh.
        int getM() const;

        /// \brief Gets the number of horizontal segments in the torus mesh.
        int getN() const;

        /// \brief Gets the torus' radius.
        double getRadius() const;

        /// \brief Gets this mesh's associated skin.
        std::shared_ptr<ISkin> getSkin() const;

        /// \brief "Lowers" this complex mesh into a polyhedron.
        std::shared_ptr<Polyhedron> Lower() const override;
    private:
        /// \brief Sets the torus' hole radius.
        void setHoleRadius(double value);

        /// \brief Sets the number of vertical segments in the torus mesh.
        void setM(int value);

        /// \brief Sets the number of horizontal segments in the torus mesh.
        void setN(int value);

        /// \brief Sets the torus' radius.
        void setRadius(double value);

        /// \brief Sets this mesh's associated skin.
        void setSkin(std::shared_ptr<ISkin> value);

        double HoleRadius_value;
        int M_value;
        int N_value;
        double Radius_value;
        std::shared_ptr<ISkin> Skin_value;
    };
}