#pragma once
#include <algorithm>
#include <memory>
#include "IShape.h"
#include "ITransformation.h"
#include "RectangleBounds.h"
#include "TransformingShapeBase.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief A shape that resizes its contents to fit a rectangle
    /// extending from (0, 0) to a point (x, y), where either x or
    /// y corresponds to a given largest dimension of the
    /// rectangle.
    class NormalizedShape : public TransformingShapeBase
    {
    public:
        /// \brief Creates a new normalized shape from the given arguments.
        NormalizedShape(std::shared_ptr<IShape> Contents, double Size, double Scale);

        /// \brief Gets a scaling factor that is applied to the shape.
        double getScale() const;

        /// \brief Gets the size of the resulting shape's greatest dimension.
        double getSize() const;

        /// \brief Gets the transformation that is to be applied to the
        /// contents.
        std::shared_ptr<ITransformation<Vector2>> GetTransformation() const override;

        /// \brief Gets the transforming shape base's bounds.
        RectangleBounds getBounds() const override;
    private:
        /// \brief Sets a scaling factor that is applied to the shape.
        void setScale(double value);

        /// \brief Sets the size of the resulting shape's greatest dimension.
        void setSize(double value);

        double Scale_value;
        double Size_value;
    };
}