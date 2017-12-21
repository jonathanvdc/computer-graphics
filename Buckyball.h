#pragma once
#include <memory>
#include "ComplexMesh.h"
#include "ISkin.h"
#include "Polyhedron.h"

namespace Engine
{
    /// \brief Defines a buckyball (truncated icosahedron) mesh.
    class Buckyball : public ComplexMesh
    {
    public:
        /// \brief Creates a new truncated icosahedron mesh from the given
        /// skin.
        Buckyball(std::shared_ptr<ISkin> Skin);

        /// \brief Gets this mesh's associated skin.
        std::shared_ptr<ISkin> getSkin() const;
    protected:
        /// \brief "Lowers" this complex mesh into a polyhedron.
        std::shared_ptr<Polyhedron> Lower() const override;
    private:
        /// \brief Sets this mesh's associated skin.
        void setSkin(std::shared_ptr<ISkin> value);

        std::shared_ptr<ISkin> Skin_value;
    };
}