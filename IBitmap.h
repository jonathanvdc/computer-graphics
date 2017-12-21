#pragma once
#include <memory>
#include "IBrush.h"
#include "IRenderTarget.h"
#include "Triangle.h"
#include "Vector2.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Describes a bitmap: a render target that supports setting
    /// individual pixels.
    struct IBitmap : public virtual IRenderTarget
    {
        /// \brief Draws a line from one point to another using a brush.
        virtual void DrawLine(int X0, int Y0, int X1, int Y1, std::shared_ptr<IBrush> Brush) = 0;

        /// \brief Fills the given triangle with the given brush.
        virtual void FillTriangle(Triangle<Vector2> Value, std::shared_ptr<IBrush> Brush) = 0;

        /// \brief Gets the color of the pixel at (X, Y).
        virtual Vector4 getItem(int X, int Y) const = 0;
        /// \brief Sets the color of the pixel at (X, Y).
        virtual void setItem(int X, int Y, Vector4 value) = 0;
    };
}