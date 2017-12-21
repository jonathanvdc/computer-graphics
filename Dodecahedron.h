#pragma once
#include <memory>
#include "ComplexMesh.h"
#include "ISkin.h"
#include "Polyhedron.h"

namespace Engine
{
    /// \brief Defines a dodecahedron mesh.
    class Dodecahedron : public ComplexMesh
    {
    public:
        /// \brief Creates a new dodecahedron mesh based on the given skin.
        Dodecahedron(std::shared_ptr<ISkin> Skin);

        /// \brief Gets this mesh's associated skin.
        std::shared_ptr<ISkin> getSkin() const;

        /// \brief "Lowers" this complex mesh into a polyhedron.
        std::shared_ptr<Polyhedron> Lower() const override;
    private:
        /// \brief Sets this mesh's associated skin.
        void setSkin(std::shared_ptr<ISkin> value);

        std::shared_ptr<ISkin> Skin_value;
    };
}