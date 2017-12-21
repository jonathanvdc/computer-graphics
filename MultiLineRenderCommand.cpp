#include "MultiLineRenderCommand.h"

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
#include "TriangleShape.h"
#include "Vector2.h"

using namespace Engine;

MultiLineRenderCommand::MultiLineRenderCommand()
{ }

MultiLineRenderCommand::MultiLineRenderCommand(stdx::ArraySlice<Vector2> Points, std::shared_ptr<IBrush> Brush, bool FillPath)
{
    this->setPoints(Points);
    this->setBrush(Brush);
    this->setFillPath(FillPath);
}

/// \brief Executes the command on the given target.
void MultiLineRenderCommand::Execute(std::shared_ptr<IRenderTarget> Target)
{
    int i;
    stdx::ArraySlice<std::shared_ptr<IPartialSegment>> segments(this->getPoints().GetLength() - 1);
    auto context = Target->getContext();
    for (i = 0; i < segments.GetLength(); ++i)
        segments[i] = context->CreateLineSegment(this->getPoints()[i]);
    std::shared_ptr<IShape> sPath;
    if (!this->getFillPath())
    {
        sPath = context->StrokePath(segments, 
                                    this->getPoints()[this->getPoints().GetLength() - 1]);
        sPath->Render(this->getBrush())->Execute(Target);
    }
    else if (stdx::isinstance<IBitmap>(Target))
        for (i = 1; i < this->getPoints().GetLength() - 2; ++i)
        {
            Triangle<Vector2> triangle(this->getPoints()[0], 
                                       this->getPoints()[i], 
                                       this->getPoints()[i + 1]);
            TriangleShape(triangle).Render(this->getBrush())->Execute(Target);
        }
    else
    {
        sPath = context->FillPath(segments, 
                                  this->getPoints()[this->getPoints().GetLength() - 1]);
        sPath->Render(this->getBrush())->Execute(Target);
    }

}

/// \brief Sets the brush to render the multi-line with.
void MultiLineRenderCommand::setBrush(std::shared_ptr<IBrush> value)
{
    this->Brush_value = value;
}

/// \brief Gets the brush to render the multi-line with.
std::shared_ptr<IBrush> MultiLineRenderCommand::getBrush() const
{
    return this->Brush_value;
}

/// \brief Sets a boolean flag that indicates whether the multi-line
/// is to be filled as a polygon or merely have its outline
/// drawn.
void MultiLineRenderCommand::setFillPath(bool value)
{
    this->FillPath_value = value;
}

/// \brief Gets a boolean flag that indicates whether the multi-line
/// is to be filled as a polygon or merely have its outline
/// drawn.
bool MultiLineRenderCommand::getFillPath() const
{
    return this->FillPath_value;
}

/// \brief Sets the multi-line's points.
void MultiLineRenderCommand::setPoints(stdx::ArraySlice<Vector2> value)
{
    this->Points_value = value;
}

/// \brief Gets the multi-line's points.
stdx::ArraySlice<Vector2> MultiLineRenderCommand::getPoints() const
{
    return this->Points_value;
}