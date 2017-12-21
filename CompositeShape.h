#pragma once
#include <memory>
#include "ArraySlice.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITransformation.h"
#include "RectangleBounds.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Implements a composite shape.
    /// A composite shape is a collection of shapes that renders
    /// and measures itself as a single shape.
    class CompositeShape : public virtual IShape
    {
    public:
        /// \brief Creates a new composite shape from the given array of
        /// shapes.
        CompositeShape(stdx::ArraySlice<std::shared_ptr<IShape>> Shapes);

        /// \brief Gets the composite shape's sub-shapes.
        stdx::ArraySlice<std::shared_ptr<IShape>> getShapes() const;

        /// \brief Creates a render command for this shape.
        std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> Render(std::shared_ptr<IBrush> Brush) const override;

        /// \brief Creates a new shape that corresponds to this shape after
        /// the given transformation has been applied.
        std::shared_ptr<IShape> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;

        /// \brief Gets the composite shape's rectangular bounds.
        RectangleBounds getBounds() const override;
    private:
        /// \brief Sets the composite shape's sub-shapes.
        void setShapes(stdx::ArraySlice<std::shared_ptr<IShape>> value);

        mutable RectangleBounds cachedBounds;
        stdx::ArraySlice<std::shared_ptr<IShape>> Shapes_value;
    };
}