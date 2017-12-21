#pragma once
#include <memory>
#include "ComplexMesh.h"
#include "ISkin.h"
#include "Polyhedron.h"

namespace Engine
{
    /// \brief Defines a tetrahedron mesh.
    class Tetrahedron : public ComplexMesh
    {
    public:
        /// \brief Creates a new tetrahedron based on a skin.
        Tetrahedron(std::shared_ptr<ISkin> Skin);

        /// \brief Gets the skin to apply to the tetrahedron.
        std::shared_ptr<ISkin> getSkin() const;

        /// \brief "Lowers" this complex mesh into a polyhedron.
        std::shared_ptr<Polyhedron> Lower() const override;
    private:
        /// \brief Sets the skin to apply to the tetrahedron.
        void setSkin(std::shared_ptr<ISkin> value);

        std::shared_ptr<ISkin> Skin_value;
    };
}