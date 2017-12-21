#include "Buckyball.h"

#include <memory>
#include "ComplexMesh.h"
#include "Icosahedron.h"
#include "ISkin.h"
#include "Polyhedron.h"

using namespace Engine;

/// \brief Creates a new truncated icosahedron mesh from the given
/// skin.
Buckyball::Buckyball(std::shared_ptr<ISkin> Skin)
{
    this->setSkin(Skin);
}

/// \brief "Lowers" this complex mesh into a polyhedron.
std::shared_ptr<Polyhedron> Buckyball::Lower() const
{
    return Icosahedron(this->getSkin()).Lower()->Truncate(0.333333333333333);
}

/// \brief Gets this mesh's associated skin.
std::shared_ptr<ISkin> Buckyball::getSkin() const
{
    return this->Skin_value;
}

/// \brief Sets this mesh's associated skin.
void Buckyball::setSkin(std::shared_ptr<ISkin> value)
{
    this->Skin_value = value;
}