#include "RenderTriangleCommand.h"

#include <initializer_list>
#include <memory>
#include "ArraySlice.h"
#include "IBitmap.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IPartialSegment.h"
#include "IRenderContext.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "IsInstance.h"
#include "Triangle.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a triangle rendering command from the given value
/// and brush.
RenderTriangleCommand::RenderTriangleCommand(Triangle<Vector2> Value, std::shared_ptr<IBrush> Brush)
    : Value(Value), Brush(Brush)
{ }

/// \brief Executes the command on the given target.
void RenderTriangleCommand::Execute(std::shared_ptr<IRenderTarget> Target)
{
    if (stdx::isinstance<IBitmap>(Target))
    {
        std::dynamic_pointer_cast<IBitmap>(Target)->FillTriangle(this->Value, 
                                                                 this->Brush);
        return;
    }
    auto context = Target->getContext();
    stdx::ArraySlice<std::shared_ptr<IPartialSegment>> segs({
                                                                context->CreateLineSegment(this->Value.A), 
                                                                context->CreateLineSegment(this->Value.B), 
                                                                context->CreateLineSegment(this->Value.C)
                                                            });
    auto shape = context->FillPath(segs, this->Value.A);
    shape->Render(this->Brush)->Execute(Target);
}