#include "Sphere.h"

#include <initializer_list>
#include <memory>
#include <vector>
#include "ArraySlice.h"
#include "ComplexMesh.h"
#include "Face.h"
#include "Icosahedron.h"
#include "ISkin.h"
#include "Polyhedron.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new sphere mesh from the number of iterations
/// and a flag that tells if the sphere is to be filled.
Sphere::Sphere(int N, std::shared_ptr<ISkin> Skin)
{
    this->setN(N);
    this->setSkin(Skin);
}

/// \brief "Lowers" this complex mesh into a polyhedron.
std::shared_ptr<Polyhedron> Sphere::Lower() const
{
    int j;
    Vector3 ptA;
    int i;
    auto ico = std::make_shared<Icosahedron>(this->getSkin());
    auto icoPoints = ico->CreatePoints();
    auto icoFaces = ico->CreateFaces();
    std::vector<Vector3> ptsVector;
    auto faces = icoFaces;
    for (i = 0; i < icoPoints.GetLength(); ++i)
        ptsVector.push_back(icoPoints[i]);
    for (i = 0; i < this->getN(); ++i)
    {
        stdx::ArraySlice<Face> newFaces(faces.GetLength() * 4);
        for (j = 0; j < faces.GetLength(); ++j)
        {
            auto indices = faces[j].Indices;
            ptA = ptsVector.at(indices[0]);
            auto ptB = ptsVector.at(indices[1]);
            auto ptC = ptsVector.at(indices[2]);
            ptsVector.push_back((ptA + ptB) / 2.0);
            ptsVector.push_back((ptA + ptC) / 2.0);
            ptsVector.push_back((ptB + ptC) / 2.0);
            newFaces[j * 4] = Face(stdx::ArraySlice<int>({
                                                             indices[0], (int)ptsVector.size() - 3, 
                                                             (int)ptsVector.size() - 2
                                                         }));
            newFaces[j * 4 + 1] = Face(stdx::ArraySlice<int>({
                                                                 indices[1], (int)ptsVector.size() - 1, 
                                                                 (int)ptsVector.size() - 3
                                                             }));
            newFaces[j * 4 + 2] = Face(stdx::ArraySlice<int>({
                                                                 indices[2], (int)ptsVector.size() - 2, 
                                                                 (int)ptsVector.size() - 1
                                                             }));
            newFaces[j * 4 + 3] = Face(stdx::ArraySlice<int>({
                                                                 (int)ptsVector.size() - 3, (int)ptsVector.size() - 2, 
                                                                 (int)ptsVector.size() - 1
                                                             }));
        }
        faces = newFaces;
    }
    stdx::ArraySlice<Vector3> points(ptsVector.size());
    for (j = 0; j < points.GetLength(); ++j)
    {
        ptA = ptsVector.at(j);
        points[j] = ptA.Normalize();
    }
    return Polyhedron(points, faces, this->getSkin()).Optimize();
}

/// \brief Sets the number of iterations that are used to approximate
/// a sphere.
void Sphere::setN(int value)
{
    this->N_value = value;
}

/// \brief Gets the number of iterations that are used to approximate
/// a sphere.
int Sphere::getN() const
{
    return this->N_value;
}

/// \brief Sets this mesh's associated skin.
void Sphere::setSkin(std::shared_ptr<ISkin> value)
{
    this->Skin_value = value;
}

/// \brief Gets this mesh's associated skin.
std::shared_ptr<ISkin> Sphere::getSkin() const
{
    return this->Skin_value;
}