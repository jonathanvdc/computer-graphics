#include "Torus.h"

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

/// \brief Creates a new torus mesh from the given arguments.
Torus::Torus(double Radius, double HoleRadius, int N, int M, std::shared_ptr<ISkin> Skin)
{
    this->setRadius(Radius);
    this->setHoleRadius(HoleRadius);
    this->setN(N);
    this->setM(M);
    this->setSkin(Skin);
}

/// \brief "Lowers" this complex mesh into a polyhedron.
std::shared_ptr<Polyhedron> Torus::Lower() const
{
    stdx::ArraySlice<Vector3> points(this->getN() * this->getM());
    stdx::ArraySlice<Face> faces(this->getN() * this->getM());
    for (int i = 0; i < this->getN(); ++i)
        for (int j = 0; j < this->getM(); ++j)
        {
            double u = 6.28318530717959 * (double)i / (double)this->getN();
            double v = 6.28318530717959 * (double)j / (double)this->getM();
            points[i * this->getM() + j] = Vector3((this->getHoleRadius() + this->getRadius() * std::cos(v)) * 
                                                   std::cos(u), 
                                                   (this->getHoleRadius() + this->getRadius() * std::cos(v)) * 
                                                   std::sin(u), 
                                                   this->getRadius() * std::sin(v));
            faces[i * this->getM() + j] = Face(stdx::ArraySlice<int>({
                                                                         i * this->getM() + j, (i + 1) % this->getN() * this->getM() + j, 
                                                                         (i + 1) % this->getN() * this->getM() + 
                                                                         (j + 1) % this->getM(), i * this->getM() + (j + 1) % this->getM()
                                                                     }));
        }
    return std::make_shared<Polyhedron>(points, faces, this->getSkin());
}

/// \brief Gets the torus' hole radius.
double Torus::getHoleRadius() const
{
    return this->HoleRadius_value;
}

/// \brief Sets the torus' hole radius.
void Torus::setHoleRadius(double value)
{
    this->HoleRadius_value = value;
}

/// \brief Gets the number of vertical segments in the torus mesh.
int Torus::getM() const
{
    return this->M_value;
}

/// \brief Sets the number of vertical segments in the torus mesh.
void Torus::setM(int value)
{
    this->M_value = value;
}

/// \brief Gets the number of horizontal segments in the torus mesh.
int Torus::getN() const
{
    return this->N_value;
}

/// \brief Sets the number of horizontal segments in the torus mesh.
void Torus::setN(int value)
{
    this->N_value = value;
}

/// \brief Gets the torus' radius.
double Torus::getRadius() const
{
    return this->Radius_value;
}

/// \brief Sets the torus' radius.
void Torus::setRadius(double value)
{
    this->Radius_value = value;
}

/// \brief Gets this mesh's associated skin.
std::shared_ptr<ISkin> Torus::getSkin() const
{
    return this->Skin_value;
}

/// \brief Sets this mesh's associated skin.
void Torus::setSkin(std::shared_ptr<ISkin> value)
{
    this->Skin_value = value;
}