#include "Mengersponge.h"

#include <memory>
#include <vector>
#include "ArraySlice.h"
#include "CompositeMesh.h"
#include "CompositeTransformation.h"
#include "Cube.h"
#include "IMesh.h"
#include "IProjection.h"
#include "IShape.h"
#include "ISkin.h"
#include "ITransformation.h"
#include "ScaleTransformation3D.h"
#include "TranslateTransformation3D.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new mengersponge mesh from the given number of
/// iterations and skin.
Mengersponge::Mengersponge(int IterationCount, std::shared_ptr<ISkin> Skin)
{
    this->setIterationCount(IterationCount);
    this->setSkin(Skin);
}

std::shared_ptr<IMesh> Mengersponge::Lower() const
{
    if (this->getIterationCount() <= 0)
        return std::make_shared<Cube>(this->getSkin());
    else
    {
        std::vector<std::shared_ptr<IMesh>> subSponges;
        for (int x = 0; x < 3; ++x)
            for (int y = 0; y < 3; ++y)
                for (int z = 0; z < 3; ++z)
                    if (!(x == 1 && y == 1 || y == 1 && z == 1 || z == 1 && x == 1))
                    {
                        auto child = std::make_shared<Mengersponge>(this->getIterationCount() - 1, 
                                                                    this->getSkin());
                        auto scale = std::make_shared<ScaleTransformation3D>(Vector3(0.333333333333333));
                        auto offset = std::make_shared<TranslateTransformation3D>(Vector3(2.0 * (1.0 - (double)x), 2.0 * (1.0 - (double)y), 
                                                                                          2.0 * (1.0 - (double)z)));
                        auto trans = std::shared_ptr<CompositeTransformation<Vector3>>(new CompositeTransformation<Vector3>(offset, scale));
                        subSponges.push_back(child->Transform(trans));
                    }
        return std::make_shared<CompositeMesh>((stdx::ArraySlice<std::shared_ptr<IMesh>>)subSponges);
    }

}

/// \brief Projects the mesh on a two-dimensional canvas based on the
/// given projection.
std::shared_ptr<IShape> Mengersponge::Project(std::shared_ptr<IProjection> Projection) const
{
    return this->Lower()->Project(Projection);
}

/// \brief Transforms the mesh with the given transformation.
std::shared_ptr<IMesh> Mengersponge::Transform(std::shared_ptr<ITransformation<Vector3>> Transformation) const
{
    return this->Lower()->Transform(Transformation);
}

/// \brief Gets the mengersponge's number of iterations.
int Mengersponge::getIterationCount() const
{
    return this->IterationCount_value;
}

/// \brief Sets the mengersponge's number of iterations.
void Mengersponge::setIterationCount(int value)
{
    this->IterationCount_value = value;
}

/// \brief Gets the mengersponge's skin.
std::shared_ptr<ISkin> Mengersponge::getSkin() const
{
    return this->Skin_value;
}

/// \brief Sets the mengersponge's skin.
void Mengersponge::setSkin(std::shared_ptr<ISkin> value)
{
    this->Skin_value = value;
}