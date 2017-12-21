#include "Icosahedron.h"

#include <cmath>
#include <initializer_list>
#include <memory>
#include "ArraySlice.h"
#include "ComplexMesh.h"
#include "Face.h"
#include "ISkin.h"
#include "Polyhedron.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new icosahedron mesh based on the given skin.
Icosahedron::Icosahedron(std::shared_ptr<ISkin> Skin)
{
    this->setSkin(Skin);
}

/// \brief Creates an array that contains the icosahedron's faces.
stdx::ArraySlice<Face> Icosahedron::CreateFaces() const
{
    return stdx::ArraySlice<Face>({
                                      Face(stdx::ArraySlice<int>({ 0, 1, 2 })), 
                                      Face(stdx::ArraySlice<int>({ 0, 2, 3 })), 
                                      Face(stdx::ArraySlice<int>({ 0, 3, 4 })), 
                                      Face(stdx::ArraySlice<int>({ 0, 4, 5 })), 
                                      Face(stdx::ArraySlice<int>({ 0, 5, 1 })), 
                                      Face(stdx::ArraySlice<int>({ 1, 6, 2 })), 
                                      Face(stdx::ArraySlice<int>({ 2, 6, 7 })), 
                                      Face(stdx::ArraySlice<int>({ 2, 7, 3 })), 
                                      Face(stdx::ArraySlice<int>({ 3, 7, 8 })), 
                                      Face(stdx::ArraySlice<int>({ 3, 8, 4 })), 
                                      Face(stdx::ArraySlice<int>({ 4, 8, 9 })), 
                                      Face(stdx::ArraySlice<int>({ 4, 9, 5 })), 
                                      Face(stdx::ArraySlice<int>({ 5, 9, 10 })), 
                                      Face(stdx::ArraySlice<int>({ 5, 10, 1 })), 
                                      Face(stdx::ArraySlice<int>({ 1, 10, 6 })), 
                                      Face(stdx::ArraySlice<int>({ 11, 7, 6 })), 
                                      Face(stdx::ArraySlice<int>({ 11, 8, 7 })), 
                                      Face(stdx::ArraySlice<int>({ 11, 9, 8 })), 
                                      Face(stdx::ArraySlice<int>({ 11, 10, 9 })), 
                                      Face(stdx::ArraySlice<int>({ 11, 6, 10 }))
                                  });
}

/// \brief Creates an array containing the icosahedron's points.
stdx::ArraySlice<Vector3> Icosahedron::CreatePoints() const
{
    int i;
    double angle;
    int pointCount = 12;
    stdx::ArraySlice<Vector3> points(pointCount);
    points[0] = Vector3(0.0, 0.0, std::sqrt(5.0) / 2.0);
    for (i = 1; i < 6; ++i)
    {
        angle = (double)(i - 1) * 1.25663706143592;
        points[i] = Vector3(std::cos(angle), std::sin(angle), 0.5);
    }
    for (i = 6; i < 11; ++i)
    {
        angle = 0.628318530717959 + (double)(i - 6) * 1.25663706143592;
        points[i] = Vector3(std::cos(angle), std::sin(angle), -0.5);
    }
    points[11] = Vector3(0.0, 0.0, -std::sqrt(5.0) / 2.0);
    return points;
}

/// \brief "Lowers" this complex mesh into a polyhedron.
std::shared_ptr<Polyhedron> Icosahedron::Lower() const
{
    auto points = this->CreatePoints();
    auto faces = this->CreateFaces();
    return std::make_shared<Polyhedron>(points, faces, this->getSkin());
}

/// \brief Gets this mesh's associated skin.
std::shared_ptr<ISkin> Icosahedron::getSkin() const
{
    return this->Skin_value;
}

/// \brief Sets this mesh's associated skin.
void Icosahedron::setSkin(std::shared_ptr<ISkin> value)
{
    this->Skin_value = value;
}