#include "CompositeShape.h"

#include <memory>
#include "ArraySlice.h"
#include "CommandBlock.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITransformation.h"
#include "RectangleBounds.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a new composite shape from the given array of
/// shapes.
CompositeShape::CompositeShape(stdx::ArraySlice<std::shared_ptr<IShape>> Shapes)
{
    this->setShapes(Shapes);
}

/// \brief Creates a render command for this shape.
std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> CompositeShape::Render(std::shared_ptr<IBrush> Brush) const
{
    auto subShapes = this->getShapes();
    stdx::ArraySlice<std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>>> commands(subShapes.GetLength());
    for (int i = 0; i < commands.GetLength(); ++i)
        commands[i] = subShapes[i]->Render(Brush);
    return std::make_shared<CommandBlock<std::shared_ptr<IRenderTarget>>>(commands);
}

/// \brief Creates a new shape that corresponds to this shape after
/// the given transformation has been applied.
std::shared_ptr<IShape> CompositeShape::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    auto oldShapes = this->getShapes();
    stdx::ArraySlice<std::shared_ptr<IShape>> newShapes(oldShapes.GetLength());
    for (int i = 0; i < newShapes.GetLength(); ++i)
        newShapes[i] = oldShapes[i]->Transform(Transformation);
    return std::make_shared<CompositeShape>(newShapes);
}

/// \brief Gets the composite shape's rectangular bounds.
RectangleBounds CompositeShape::getBounds() const
{
    if (this->cachedBounds == RectangleBounds())
    {
        auto result = this->getShapes()[0]->getBounds();
        for (int i = 1; i < this->getShapes().GetLength(); ++i)
            result = result.Union(this->getShapes()[i]->getBounds());
        this->cachedBounds = result;
    }
    return this->cachedBounds;
}

/// \brief Gets the composite shape's sub-shapes.
stdx::ArraySlice<std::shared_ptr<IShape>> CompositeShape::getShapes() const
{
    return this->Shapes_value;
}

/// \brief Sets the composite shape's sub-shapes.
void CompositeShape::setShapes(stdx::ArraySlice<std::shared_ptr<IShape>> value)
{
    this->Shapes_value = value;
}