#pragma once
#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITransformation.h"
#include "RectangleBounds.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief A base class for shapes that represent a transformation of
    /// another shape.
    class TransformingShapeBase : public virtual IShape
    {
    public:
        TransformingShapeBase();

        /// \brief Gets the shape that is to be transformed.
        std::shared_ptr<IShape> getContents() const;

        /// \brief Gets the transformation that is to be applied to the
        /// contents.
        virtual std::shared_ptr<ITransformation<Vector2>> GetTransformation() const = 0;

        /// \brief Creates a render command for this shape.
        std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> Render(std::shared_ptr<IBrush> Brush) const override;

        /// \brief Creates a new shape that corresponds to this shape after
        /// the given transformation has been applied.
        std::shared_ptr<IShape> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;

        /// \brief Gets the transforming shape base's bounds.
        virtual RectangleBounds getBounds() const override = 0;
    protected:
        /// \brief Sets the shape that is to be transformed.
        void setContents(std::shared_ptr<IShape> value);
    private:
        std::shared_ptr<IShape> Contents_value;
    };
}