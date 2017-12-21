#include "Dodecahedron.h"

#include <memory>
#include "ComplexMesh.h"
#include "Icosahedron.h"
#include "ISkin.h"
#include "Polyhedron.h"

using namespace Engine;

/// \brief Creates a new dodecahedron mesh based on the given skin.
Dodecahedron::Dodecahedron(std::shared_ptr<ISkin> Skin)
{
    this->setSkin(Skin);
}

/// \brief "Lowers" this complex mesh into a polyhedron.
std::shared_ptr<Polyhedron> Dodecahedron::Lower() const
{
    return Icosahedron(this->getSkin()).Lower()->MakeDual();
}

/// \brief Gets this mesh's associated skin.
std::shared_ptr<ISkin> Dodecahedron::getSkin() const
{
    return this->Skin_value;
}

/// \brief Sets this mesh's associated skin.
void Dodecahedron::setSkin(std::shared_ptr<ISkin> value)
{
    this->Skin_value = value;
}