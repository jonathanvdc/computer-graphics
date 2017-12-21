#pragma once
#include "IDepthBuffer.h"
#include "PixelPosition.h"

namespace Engine
{
    /// \brief A depth buffer implementation that always reports a
    /// constant depth. Individual positions cannot have their
    /// depth set.
    /// \remark Constant depth buffers enable the render target to switch
    /// depth buffering on or off. If Z-buffering is not desired, a
    /// simple constant depth buffer is provided.
    /// Otherwise, a full-blown Z-buffer can be used.
    class ConstantDepthBuffer : public virtual IDepthBuffer
    {
    public:
        /// \brief Creates a new constant depth buffer with a positive
        /// infinite depth.
        /// \pre require(Width > 0.0 && Height > 0.0);
        ConstantDepthBuffer(double Width, double Height);
        /// \brief Creates a new constant depth buffer based on the given
        /// depth.
        /// \pre require(Width > 0.0 && Height > 0.0);
        ConstantDepthBuffer(double Width, double Height, double Depth);

        /// \brief Gets the depth buffer's depth.
        double getDepth() const;

        /// \brief Gets the constant depth buffer's height.
        double getHeight() const override;

        /// \brief Gets the constant depth buffer's width.
        double getWidth() const override;

        /// \brief Gets the buffer's depth at the given position.
        double getItem(PixelPosition Position) const override;
        /// \brief Sets the buffer's depth at the given position.
        void setItem(PixelPosition Position, double value) override;
    private:
        /// \brief Sets the depth buffer's depth.
        void setDepth(double value);

        /// \brief Sets the constant depth buffer's height.
        void setHeight(double value);

        /// \brief Sets the constant depth buffer's width.
        void setWidth(double value);

        double Depth_value;
        double Height_value;
        double Width_value;
    };
}