#include "Cone.h"

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

/// \brief Creates a new cone mesh from the given arguments.
Cone::Cone(double Height, int N, std::shared_ptr<ISkin> Skin)
{
    this->setHeight(Height);
    this->setN(N);
    this->setSkin(Skin);
}

/// \brief Creates a single face that encompasses the cone's base.
Face Cone::CreateBaseFace() const
{
    stdx::ArraySlice<int> indices(this->getN());
    for (int i = 0; i < this->getN(); ++i)
        indices[i] = this->getN() - i - 1;
    return Face(indices);
}

/// \brief Creates an array of points for the cone's base.
stdx::ArraySlice<Vector3> Cone::CreateBasePoints(double BaseHeight) const
{
    stdx::ArraySlice<Vector3> points(this->getN());
    for (int i = 0; i < this->getN(); ++i)
        points[i] = Vector3(std::cos((double)i * 6.28318530717959 / (double)this->getN()), 
                            std::sin((double)i * 6.28318530717959 / (double)this->getN()), 
                            BaseHeight);
    return points;
}

/// \brief "Lowers" this complex mesh into a polyhedron.
std::shared_ptr<Polyhedron> Cone::Lower() const
{
    auto basePoints = this->CreateBasePoints(0.0);
    stdx::ArraySlice<Vector3> points(basePoints.GetLength() + 1);
    int i = basePoints.GetLength();
    int j = 0;
    int k = points.GetLength();
    while (j < i && j < k)
    {
        points[j] = basePoints[j];
        ++j;
    }
    points[basePoints.GetLength()] = Vector3(0.0, 0.0, this->getHeight());
    stdx::ArraySlice<Face> faces(this->getN() + 1);
    for (i = 0; i < this->getN(); ++i)
        faces[i] = Face(stdx::ArraySlice<int>({
                                                  i, (i + 1) % this->getN(), this->getN()
                                              }));
    faces[this->getN()] = this->CreateBaseFace();
    return std::make_shared<Polyhedron>(points, faces, this->getSkin());
}

/// \brief Gets the cone's height.
double Cone::getHeight() const
{
    return this->Height_value;
}

/// \brief Sets the cone's height.
void Cone::setHeight(double value)
{
    this->Height_value = value;
}

/// \brief Gets the number of points the base of the cone has.
int Cone::getN() const
{
    return this->N_value;
}

/// \brief Sets the number of points the base of the cone has.
void Cone::setN(int value)
{
    this->N_value = value;
}

/// \brief Gets this mesh's associated skin.
std::shared_ptr<ISkin> Cone::getSkin() const
{
    return this->Skin_value;
}

/// \brief Sets this mesh's associated skin.
void Cone::setSkin(std::shared_ptr<ISkin> value)
{
    this->Skin_value = value;
}