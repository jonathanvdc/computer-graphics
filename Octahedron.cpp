#include "Octahedron.h"

#include <memory>
#include "ComplexMesh.h"
#include "Cube.h"
#include "ISkin.h"
#include "Polyhedron.h"

using namespace Engine;

/// \brief Creates a new octahedron mesh based on a skin.
Octahedron::Octahedron(std::shared_ptr<ISkin> Skin)
{
    this->setSkin(Skin);
}

/// \brief "Lowers" this complex mesh into a polyhedron.
std::shared_ptr<Polyhedron> Octahedron::Lower() const
{
    return Cube(this->getSkin()).Lower()->MakeDual();
}

/// \brief Gets this mesh's associated skin.
std::shared_ptr<ISkin> Octahedron::getSkin() const
{
    return this->Skin_value;
}

/// \brief Sets this mesh's associated skin.
void Octahedron::setSkin(std::shared_ptr<ISkin> value)
{
    this->Skin_value = value;
}