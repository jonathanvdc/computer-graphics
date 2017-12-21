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
    /// \brief Defines an icosahedron mesh.
    class Icosahedron : public ComplexMesh
    {
    public:
        /// \brief Creates a new icosahedron mesh based on the given skin.
        Icosahedron(std::shared_ptr<ISkin> Skin);

        /// \brief Creates an array that contains the icosahedron's faces.
        stdx::ArraySlice<Face> CreateFaces() const;

        /// \brief Creates an array containing the icosahedron's points.
        stdx::ArraySlice<Vector3> CreatePoints() const;

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