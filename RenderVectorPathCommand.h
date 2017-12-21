#pragma once
#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IVectorInstructionStream.h"

namespace Engine
{
    /// \brief Defines a command that renders a vector path.
    class RenderVectorPathCommand : public virtual ICommand<std::shared_ptr<IRenderTarget>>
    {
    public:
        /// \brief Creates a new vector segment from the given arguments.
        RenderVectorPathCommand(std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> Instructions, std::shared_ptr<IBrush> Brush, bool FillPath);
        /// \brief Creates a new vector segment from the given arguments.
        RenderVectorPathCommand(std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> Instructions, std::shared_ptr<IBrush> Stroke, double StrokeThickness);
        /// \brief Creates a new vector segment from the given arguments.
        RenderVectorPathCommand(std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> Instructions, std::shared_ptr<IBrush> Fill, std::shared_ptr<IBrush> Stroke);
        /// \brief Creates a new vector segment from the given arguments.
        RenderVectorPathCommand(std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> Instructions, std::shared_ptr<IBrush> Fill, std::shared_ptr<IBrush> Stroke, double StrokeThickness);

        /// \brief Executes the command on the given target.
        void Execute(std::shared_ptr<IRenderTarget> Target) override;

        /// \brief Gets the brush to fill the vector path with.
        std::shared_ptr<IBrush> getFill() const;

        /// \brief Gets a command that represents the instructions that are to
        /// be written to the vector instruction stream.
        std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> getInstructions() const;

        /// \brief Gets the brush to draw the vector path's outline with.
        std::shared_ptr<IBrush> getStroke() const;

        /// \brief Gets the vector path's stroke thickness.
        double getStrokeThickness() const;
    private:
        /// \brief Sets the brush to fill the vector path with.
        void setFill(std::shared_ptr<IBrush> value);

        /// \brief Sets a command that represents the instructions that are to
        /// be written to the vector instruction stream.
        void setInstructions(std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> value);

        /// \brief Sets the brush to draw the vector path's outline with.
        void setStroke(std::shared_ptr<IBrush> value);

        /// \brief Sets the vector path's stroke thickness.
        void setStrokeThickness(double value);

        std::shared_ptr<IBrush> Fill_value;
        std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> Instructions_value;
        std::shared_ptr<IBrush> Stroke_value;
        double StrokeThickness_value;
    };
}