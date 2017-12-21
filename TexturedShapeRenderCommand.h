#pragma once
#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "TexturedShape.h"

namespace Engine
{
    struct TexturedShapeRenderCommand : public virtual ICommand<std::shared_ptr<IRenderTarget>>
    {
        TexturedShapeRenderCommand(TexturedShape Shape, std::shared_ptr<IBrush> Brush);

        /// \brief Executes the command on the given target.
        void Execute(std::shared_ptr<IRenderTarget> Target) override;

        std::shared_ptr<IBrush> Brush;
        TexturedShape Shape;
    };
}