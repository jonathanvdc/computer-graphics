#include "Scene.h"

#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IMesh.h"
#include "IProjection.h"
#include "IRenderTarget.h"
#include "ITransformation.h"
#include "NormalizedShape.h"
#include "RectangleBounds.h"
#include "TransformingShapeBase.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new scene based on the given arguments.
Scene::Scene(std::shared_ptr<IMesh> Contents, std::shared_ptr<ITransformation<Vector3>> GlobalTransformation, std::shared_ptr<IProjection> Projection, std::shared_ptr<IBrush> Brush, double Size, double Scale)
{
    this->setContents(Contents);
    this->setGlobalTransformation(GlobalTransformation);
    this->setProjection(Projection);
    this->setBrush(Brush);
    this->setSize(Size);
    this->setScale(Scale);
}

/// \brief Renders the scene to the given render target.
void Scene::Render(std::shared_ptr<IRenderTarget> Target)
{
    auto renderCommand = this->getProjectedShape()->Render(this->getBrush());
    renderCommand->Execute(Target);
}

/// \brief Gets the scene's bounds.
RectangleBounds Scene::getBounds() const
{
    return this->getProjectedShape()->getBounds();
}

/// \brief Gets the scene's contents brush.
std::shared_ptr<IBrush> Scene::getBrush() const
{
    return this->Brush_value;
}

/// \brief Sets the scene's contents brush.
void Scene::setBrush(std::shared_ptr<IBrush> value)
{
    this->Brush_value = value;
}

/// \brief Gets the scene's contents.
std::shared_ptr<IMesh> Scene::getContents() const
{
    return this->Contents_value;
}

/// \brief Sets the scene's contents.
void Scene::setContents(std::shared_ptr<IMesh> value)
{
    this->Contents_value = value;
}

/// \brief Gets the scene's global transformation.
std::shared_ptr<ITransformation<Vector3>> Scene::getGlobalTransformation() const
{
    return this->GlobalTransformation_value;
}

/// \brief Sets the scene's global transformation.
void Scene::setGlobalTransformation(std::shared_ptr<ITransformation<Vector3>> value)
{
    this->GlobalTransformation_value = value;
}

/// \brief Gets the scene's height.
double Scene::getHeight() const
{
    auto bounds = this->getBounds();
    return bounds.getHeight();
}

std::shared_ptr<NormalizedShape> Scene::getProjectedShape() const
{
    if (this->cachedShape == nullptr)
        this->cachedShape = std::make_shared<NormalizedShape>(this->getContents()->Transform(this->getGlobalTransformation())->Project(this->getProjection()), 
                                                              this->getSize(), 
                                                              this->getScale());

    return this->cachedShape;
}

/// \brief Gets the scene's projection.
std::shared_ptr<IProjection> Scene::getProjection() const
{
    return this->Projection_value;
}

/// \brief Sets the scene's projection.
void Scene::setProjection(std::shared_ptr<IProjection> value)
{
    this->Projection_value = value;
}

/// \brief Gets a scaling factor that is applied to the scene.
double Scene::getScale() const
{
    return this->Scale_value;
}

/// \brief Sets a scaling factor that is applied to the scene.
void Scene::setScale(double value)
{
    this->Scale_value = value;
}

/// \brief Gets the size of the scene's greatest dimension.
double Scene::getSize() const
{
    return this->Size_value;
}

/// \brief Sets the size of the scene's greatest dimension.
void Scene::setSize(double value)
{
    this->Size_value = value;
}

/// \brief Gets the scene's width.
double Scene::getWidth() const
{
    auto bounds = this->getBounds();
    return bounds.getWidth();
}