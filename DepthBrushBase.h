#pragma once
#include <memory>
#include "IBrush.h"
#include "IDepthBuffer.h"
#include "PixelPosition.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a base class for depth brushes: brushes that take
    /// depth into account.
    struct DepthBrushBase : public virtual IBrush
    {
        /// \brief Creates an empty depth brush.
        DepthBrushBase();
        /// \brief Creates a depth brush based on the given brush and depth
        /// buffer.
        DepthBrushBase(std::shared_ptr<IBrush> Brush, std::shared_ptr<IDepthBuffer> DepthBuffer);

        /// \brief Gets the brush's color at the given position.
        Vector4 GetColor(PixelPosition Position) override;

        /// \brief Gets the mesh's depth at the given pixel position.
        virtual double GetDepth(PixelPosition Position) const = 0;

        /// \brief The brush the depth brush uses for actual drawing.
        std::shared_ptr<IBrush> Brush;
        /// \brief The depth buffer the depth brush uses.
        std::shared_ptr<IDepthBuffer> DepthBuffer;
    };
}