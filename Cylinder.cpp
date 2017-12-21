#include "Cylinder.h"

#include <initializer_list>
#include <memory>
#include "ArraySlice.h"
#include "ComplexMesh.h"
#include "Cone.h"
#include "Face.h"
#include "ISkin.h"
#include "Polyhedron.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new cylinder mesh based on a given height, the
/// number of points at its base and a skin.
Cylinder::Cylinder(double Height, int N, std::shared_ptr<ISkin> Skin)
{
    this->setHeight(Height);
    this->setN(N);
    this->setSkin(Skin);
    this->setHasCaps(true);
}

/// \brief Creates a new cylinder mesh based on a given height, the
/// number of points at its base, a skin and a flag that
/// indicates whether the cylinder has a top and bottom face.
Cylinder::Cylinder(double Height, int N, std::shared_ptr<ISkin> Skin, bool HasCaps)
{
    this->setHeight(Height);
    this->setN(N);
    this->setSkin(Skin);
    this->setHasCaps(HasCaps);
}

/// \brief "Lowers" this complex mesh into a polyhedron.
std::shared_ptr<Polyhedron> Cylinder::Lower() const
{
    int i;
    auto cone = std::make_shared<Cone>(this->getHeight(), this->getN(), 
                                       this->getSkin());
    auto basePts = cone->CreateBasePoints(0.0);
    auto topPts = cone->CreateBasePoints(this->getHeight());
    stdx::ArraySlice<Vector3> points(basePts.GetLength() + topPts.GetLength());
    for (i = 0; i < basePts.GetLength(); ++i)
        points[i] = basePts[i];
    for (i = 0; i < topPts.GetLength(); ++i)
        points[i + basePts.GetLength()] = topPts[i];
    stdx::ArraySlice<Face> faces;
    if (this->getHasCaps())
        faces = stdx::ArraySlice<Face>(this->getN() + 2);
    else
        faces = stdx::ArraySlice<Face>(this->getN());

    for (i = 0; i < this->getN(); ++i)
        faces[i] = Face(stdx::ArraySlice<int>({
                                                  i, (i + 1) % this->getN(), this->getN() + (i + 1) % this->getN(), 
                                                  this->getN() + i
                                              }));
    if (this->getHasCaps())
    {
        faces[this->getN()] = cone->CreateBaseFace();
        stdx::ArraySlice<int> topIndices(faces[this->getN()].Indices.GetLength());
        i = topIndices.GetLength();
        int j = 0;
        auto arr = faces[this->getN()].Indices;
        int k = arr.GetLength();
        while (j < i && j < k)
        {
            topIndices[j] = arr[j] + this->getN();
            ++j;
        }
        faces[this->getN() + 1] = Face(topIndices);
    }
    return std::make_shared<Polyhedron>(points, faces, this->getSkin());
}

/// \brief Sets a boolean value that indicates whether the cylinder
/// has a top and bottom face.
void Cylinder::setHasCaps(bool value)
{
    this->HasCaps_value = value;
}

/// \brief Gets a boolean value that indicates whether the cylinder
/// has a top and bottom face.
bool Cylinder::getHasCaps() const
{
    return this->HasCaps_value;
}

/// \brief Sets the cylinder's height.
void Cylinder::setHeight(double value)
{
    this->Height_value = value;
}

/// \brief Gets the cylinder's height.
double Cylinder::getHeight() const
{
    return this->Height_value;
}

/// \brief Sets the number of points at the cylinder's base.
void Cylinder::setN(int value)
{
    this->N_value = value;
}

/// \brief Gets the number of points at the cylinder's base.
int Cylinder::getN() const
{
    return this->N_value;
}

/// \brief Sets this mesh's associated skin.
void Cylinder::setSkin(std::shared_ptr<ISkin> value)
{
    this->Skin_value = value;
}

/// \brief Gets this mesh's associated skin.
std::shared_ptr<ISkin> Cylinder::getSkin() const
{
    return this->Skin_value;
}