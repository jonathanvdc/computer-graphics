#pragma once
#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITexture.h"
#include "ITransformation.h"
#include "RectangleBounds.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Defines a textured shape: a shape that uses a texture.
    class TexturedShape : public virtual IShape
    {
    public:
        /// \brief Creates a new textured shape from the given shape and
        /// texture.
        TexturedShape(std::shared_ptr<IShape> Shape, std::shared_ptr<ITexture> Texture);

        /// \brief Gets the shape to draw.
        std::shared_ptr<IShape> getShape() const;

        /// \brief Gets the texture to draw the shape with.
        std::shared_ptr<ITexture> getTexture() const;

        /// \brief Creates a render command for this shape.
        std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> Render(std::shared_ptr<IBrush> Brush) const override;

        /// \brief Creates a new shape that corresponds to this shape after
        /// the given transformation has been applied.
        std::shared_ptr<IShape> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;

        /// \brief Gets the shape's rectangular bounds.
        RectangleBounds getBounds() const override;
    private:
        /// \brief Sets the shape to draw.
        void setShape(std::shared_ptr<IShape> value);

        /// \brief Sets the texture to draw the shape with.
        void setTexture(std::shared_ptr<ITexture> value);

        std::shared_ptr<IShape> Shape_value;
        std::shared_ptr<ITexture> Texture_value;
    };
}