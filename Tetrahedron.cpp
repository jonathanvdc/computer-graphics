#include "Tetrahedron.h"

#include <initializer_list>
#include <memory>
#include "ArraySlice.h"
#include "ComplexMesh.h"
#include "Face.h"
#include "ISkin.h"
#include "Polyhedron.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new tetrahedron based on a skin.
Tetrahedron::Tetrahedron(std::shared_ptr<ISkin> Skin)
{
    this->setSkin(Skin);
}

/// \brief "Lowers" this complex mesh into a polyhedron.
std::shared_ptr<Polyhedron> Tetrahedron::Lower() const
{
    stdx::ArraySlice<Vector3> points({
                                         Vector3(1.0, -1.0, -1.0), Vector3(-1.0, 1.0, -1.0), 
                                         Vector3(1.0, 1.0, 1.0), Vector3(-1.0, -1.0, 1.0)
                                     });
    stdx::ArraySlice<Face> faces({
                                     Face(stdx::ArraySlice<int>({ 0, 1, 2 })), 
                                     Face(stdx::ArraySlice<int>({ 1, 3, 2 })), 
                                     Face(stdx::ArraySlice<int>({ 0, 1, 3 })), 
                                     Face(stdx::ArraySlice<int>({ 0, 2, 3 }))
                                 });
    return std::make_shared<Polyhedron>(points, faces, this->getSkin());
}

/// \brief Gets the skin to apply to the tetrahedron.
std::shared_ptr<ISkin> Tetrahedron::getSkin() const
{
    return this->Skin_value;
}

/// \brief Sets the skin to apply to the tetrahedron.
void Tetrahedron::setSkin(std::shared_ptr<ISkin> value)
{
    this->Skin_value = value;
}