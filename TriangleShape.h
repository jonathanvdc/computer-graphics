#pragma once
#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITransformation.h"
#include "RectangleBounds.h"
#include "Triangle.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief A filled triangle shape.
    class TriangleShape : public virtual IShape
    {
    public:
        /// \brief Creates a new triangle shape from the given triangle.
        TriangleShape(Triangle<Vector2> Value);
        /// \brief Creates a new triangle shape from the given points.
        TriangleShape(Vector2 A, Vector2 B, Vector2 C);

        /// \brief Creates a render command for this shape.
        virtual std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> Render(std::shared_ptr<IBrush> Brush) const override;

        /// \brief Creates a new shape that corresponds to this shape after
        /// the given transformation has been applied.
        virtual std::shared_ptr<IShape> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;

        /// \brief Gets the shape's rectangular bounds.
        RectangleBounds getBounds() const override;

        /// \brief The triangle's geometry.
        Triangle<Vector2> Value;
    protected:
        TriangleShape();
    };
}