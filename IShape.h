#pragma once
#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "ITransformation.h"
#include "RectangleBounds.h"
#include "Vector2.h"

namespace Engine
{
    struct IRenderContext;
    struct IRenderTarget;

    struct IShape
    {
        /// \brief Creates a render command for this shape.
        virtual std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> Render(std::shared_ptr<IBrush> Brush) const = 0;

        /// \brief Creates a new shape that corresponds to this shape after
        /// the given transformation has been applied.
        virtual std::shared_ptr<IShape> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const = 0;

        /// \brief Gets the shape's rectangular bounds.
        virtual RectangleBounds getBounds() const = 0;
    };
}