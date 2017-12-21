#pragma once
#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "Triangle.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Defines a triangle rendering command.
    struct RenderTriangleCommand : public virtual ICommand<std::shared_ptr<IRenderTarget>>
    {
        /// \brief Creates a triangle rendering command from the given value
        /// and brush.
        RenderTriangleCommand(Triangle<Vector2> Value, std::shared_ptr<IBrush> Brush);

        /// \brief Executes the command on the given target.
        void Execute(std::shared_ptr<IRenderTarget> Target) override;

        /// \brief The triangle rendering command's brush.
        std::shared_ptr<IBrush> Brush;
        /// \brief The trianle rendering command's triangle.
        Triangle<Vector2> Value;
    };
}