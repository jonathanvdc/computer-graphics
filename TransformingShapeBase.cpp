#include "TransformingShapeBase.h"

#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITransformation.h"
#include "RectangleBounds.h"
#include "Vector2.h"

using namespace Engine;

TransformingShapeBase::TransformingShapeBase()
{ }

/// \brief Creates a render command for this shape.
std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> TransformingShapeBase::Render(std::shared_ptr<IBrush> Brush) const
{
    return this->getContents()->Transform(this->GetTransformation())->Render(Brush);
}

/// \brief Creates a new shape that corresponds to this shape after
/// the given transformation has been applied.
std::shared_ptr<IShape> TransformingShapeBase::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    return this->getContents()->Transform(this->GetTransformation())->Transform(Transformation);
}

/// \brief Gets the shape that is to be transformed.
std::shared_ptr<IShape> TransformingShapeBase::getContents() const
{
    return this->Contents_value;
}

/// \brief Sets the shape that is to be transformed.
void TransformingShapeBase::setContents(std::shared_ptr<IShape> value)
{
    this->Contents_value = value;
}