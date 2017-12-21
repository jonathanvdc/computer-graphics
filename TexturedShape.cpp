#include "TexturedShape.h"

#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITexture.h"
#include "ITransformation.h"
#include "RectangleBounds.h"
#include "TexturedShapeRenderCommand.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a new textured shape from the given shape and
/// texture.
TexturedShape::TexturedShape(std::shared_ptr<IShape> Shape, std::shared_ptr<ITexture> Texture)
{
    this->setShape(Shape);
    this->setTexture(Texture);
}

/// \brief Creates a render command for this shape.
std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> TexturedShape::Render(std::shared_ptr<IBrush> Brush) const
{
    return std::make_shared<TexturedShapeRenderCommand>(*this, Brush);
}

/// \brief Creates a new shape that corresponds to this shape after
/// the given transformation has been applied.
std::shared_ptr<IShape> TexturedShape::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    return std::make_shared<TexturedShape>(this->getShape()->Transform(Transformation), 
                                           this->getTexture()->Transform(Transformation));
}

/// \brief Gets the shape's rectangular bounds.
RectangleBounds TexturedShape::getBounds() const
{
    return this->getShape()->getBounds();
}

/// \brief Sets the shape to draw.
void TexturedShape::setShape(std::shared_ptr<IShape> value)
{
    this->Shape_value = value;
}

/// \brief Gets the shape to draw.
std::shared_ptr<IShape> TexturedShape::getShape() const
{
    return this->Shape_value;
}

/// \brief Sets the texture to draw the shape with.
void TexturedShape::setTexture(std::shared_ptr<ITexture> value)
{
    this->Texture_value = value;
}

/// \brief Gets the texture to draw the shape with.
std::shared_ptr<ITexture> TexturedShape::getTexture() const
{
    return this->Texture_value;
}