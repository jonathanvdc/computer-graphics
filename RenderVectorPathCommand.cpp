#include "RenderVectorPathCommand.h"

#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IVectorInstructionStream.h"
#include "IVectorRenderTarget.h"
#include "SolidColorBrush.h"
#include "Vector4.h"
#include "VectorPathBase.h"

using namespace Engine;

/// \brief Creates a new vector segment from the given arguments.
RenderVectorPathCommand::RenderVectorPathCommand(std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> Instructions, std::shared_ptr<IBrush> Brush, bool FillPath)
{
    this->setInstructions(Instructions);
    if (FillPath)
    {
        this->setFill(Brush);
        this->setStroke(std::make_shared<SolidColorBrush>(Vector4(1.0, 1.0, 1.0, 0.0)));
    }
    else
    {
        this->setStroke(Brush);
        this->setFill(std::make_shared<SolidColorBrush>(Vector4(1.0, 1.0, 1.0, 0.0)));
    }
    this->setStrokeThickness(1.0);
}

/// \brief Creates a new vector segment from the given arguments.
RenderVectorPathCommand::RenderVectorPathCommand(std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> Instructions, std::shared_ptr<IBrush> Stroke, double StrokeThickness)
{
    this->setInstructions(Instructions);
    this->setStroke(Stroke);
    this->setStrokeThickness(StrokeThickness);
}

/// \brief Creates a new vector segment from the given arguments.
RenderVectorPathCommand::RenderVectorPathCommand(std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> Instructions, std::shared_ptr<IBrush> Fill, std::shared_ptr<IBrush> Stroke)
{
    this->setInstructions(Instructions);
    this->setFill(Fill);
    this->setStroke(Stroke);
    this->setStrokeThickness(1.0);
}

/// \brief Creates a new vector segment from the given arguments.
RenderVectorPathCommand::RenderVectorPathCommand(std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> Instructions, std::shared_ptr<IBrush> Fill, std::shared_ptr<IBrush> Stroke, double StrokeThickness)
{
    this->setInstructions(Instructions);
    this->setFill(Fill);
    this->setStroke(Stroke);
    this->setStrokeThickness(StrokeThickness);
}

/// \brief Executes the command on the given target.
void RenderVectorPathCommand::Execute(std::shared_ptr<IRenderTarget> Target)
{
    auto vectorTarget = std::dynamic_pointer_cast<IVectorRenderTarget>(Target);
    auto path = vectorTarget->AddPath();
    path->setStroke(this->getStroke());
    path->setFill(this->getFill());
    path->setStrokeThickness(this->getStrokeThickness());
    this->getInstructions()->Execute(path->GetInstructionStream());
}

/// \brief Sets the brush to fill the vector path with.
void RenderVectorPathCommand::setFill(std::shared_ptr<IBrush> value)
{
    this->Fill_value = value;
}

/// \brief Gets the brush to fill the vector path with.
std::shared_ptr<IBrush> RenderVectorPathCommand::getFill() const
{
    return this->Fill_value;
}

/// \brief Sets a command that represents the instructions that are to
/// be written to the vector instruction stream.
void RenderVectorPathCommand::setInstructions(std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> value)
{
    this->Instructions_value = value;
}

/// \brief Gets a command that represents the instructions that are to
/// be written to the vector instruction stream.
std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> RenderVectorPathCommand::getInstructions() const
{
    return this->Instructions_value;
}

/// \brief Sets the brush to draw the vector path's outline with.
void RenderVectorPathCommand::setStroke(std::shared_ptr<IBrush> value)
{
    this->Stroke_value = value;
}

/// \brief Gets the brush to draw the vector path's outline with.
std::shared_ptr<IBrush> RenderVectorPathCommand::getStroke() const
{
    return this->Stroke_value;
}

/// \brief Sets the vector path's stroke thickness.
void RenderVectorPathCommand::setStrokeThickness(double value)
{
    this->StrokeThickness_value = value;
}

/// \brief Gets the vector path's stroke thickness.
double RenderVectorPathCommand::getStrokeThickness() const
{
    return this->StrokeThickness_value;
}