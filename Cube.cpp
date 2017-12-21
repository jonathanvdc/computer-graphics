#include "Cube.h"

#include <initializer_list>
#include <memory>
#include "ArraySlice.h"
#include "ComplexMesh.h"
#include "Face.h"
#include "ISkin.h"
#include "Polyhedron.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new cube mesh with the given skin.
Cube::Cube(std::shared_ptr<ISkin> Skin)
{
    this->setSkin(Skin);
}

/// \brief "Lowers" this complex mesh into a polyhedron.
std::shared_ptr<Polyhedron> Cube::Lower() const
{
    stdx::ArraySlice<Vector3> points({
                                         Vector3(1.0, -1.0, -1.0), Vector3(-1.0, 1.0, -1.0), 
                                         Vector3(1.0, 1.0, 1.0), Vector3(-1.0, -1.0, 1.0), 
                                         Vector3(1.0, 1.0, -1.0), Vector3(-1.0, -1.0, -1.0), 
                                         Vector3(1.0, -1.0, 1.0), Vector3(-1.0, 1.0, 1.0)
                                     });
    stdx::ArraySlice<Face> faces({
                                     Face(stdx::ArraySlice<int>({ 0, 4, 2, 6 })), 
                                     Face(stdx::ArraySlice<int>({ 4, 1, 7, 2 })), 
                                     Face(stdx::ArraySlice<int>({ 1, 5, 3, 7 })), 
                                     Face(stdx::ArraySlice<int>({ 5, 0, 6, 3 })), 
                                     Face(stdx::ArraySlice<int>({ 6, 2, 7, 3 })), 
                                     Face(stdx::ArraySlice<int>({ 0, 5, 1, 4 }))
                                 });
    return std::make_shared<Polyhedron>(points, faces, this->getSkin());
}

/// \brief Sets this mesh's associated skin.
void Cube::setSkin(std::shared_ptr<ISkin> value)
{
    this->Skin_value = value;
}

/// \brief Gets this mesh's associated skin.
std::shared_ptr<ISkin> Cube::getSkin() const
{
    return this->Skin_value;
}