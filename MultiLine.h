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
    /// \brief Defines a multi-line: a sequence of straight lines that
    /// connect an array of two-dimensional points.
    /// \remark A multi-line can also be used as a polygon if it is
    /// configured to be filled on rendering.
    class MultiLine : public virtual IShape
    {
    public:
        /// \brief Creates a new empty multi-line.
        MultiLine();
        /// \brief Creates a multi-line from the given points.
        /// The resulting multi-line will be configured to draw its
        /// outlines.
        MultiLine(stdx::ArraySlice<Vector2> Points);
        /// \brief Creates a multi-line from the given points and a boolean
        /// flag that indicates whether the multi-line is to be filled
        /// as a polygon or merely have its outline drawn.
        MultiLine(stdx::ArraySlice<Vector2> Points, bool FillPath);

        /// \brief Gets a boolean flag that indicates whether the multi-line
        /// is to be filled as a polygon or merely have its outline
        /// drawn.
        bool getFillPath() const;

        /// \brief Gets the array that contains this multi-line's points.
        stdx::ArraySlice<Vector2> getPoints() const;

        /// \brief Creates a render command for this shape.
        virtual std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> Render(std::shared_ptr<IBrush> Brush) const override;

        /// \brief Creates a new shape that corresponds to this shape after
        /// the given transformation has been applied.
        virtual std::shared_ptr<IShape> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;

        /// \brief Gets the shape's rectangular bounds.
        RectangleBounds getBounds() const override;
    protected:
        /// \brief Sets a boolean flag that indicates whether the multi-line
        /// is to be filled as a polygon or merely have its outline
        /// drawn.
        void setFillPath(bool value);

        /// \brief Sets the array that contains this multi-line's points.
        void setPoints(stdx::ArraySlice<Vector2> value);
    private:
        bool FillPath_value;
        stdx::ArraySlice<Vector2> Points_value;
    };
}