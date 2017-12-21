#include "TexturedShapeRenderCommand.h"

#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITexture.h"
#include "TexturedShape.h"

using namespace Engine;

TexturedShapeRenderCommand::TexturedShapeRenderCommand(TexturedShape Shape, std::shared_ptr<IBrush> Brush)
    : Shape(Shape), Brush(Brush)
{ }

/// \brief Executes the command on the given target.
void TexturedShapeRenderCommand::Execute(std::shared_ptr<IRenderTarget> Target)
{
    auto brush = this->Shape.getTexture()->ToBrush(Target, this->Brush);
    return this->Shape.getShape()->Render(brush)->Execute(Target);
}