#pragma once
#include "ISurface.h"
#include "PixelPosition.h"

namespace Engine
{
    /// \brief Provides a common interface for depth buffers.
    struct IDepthBuffer : public virtual ISurface
    {
        /// \brief Gets the buffer's depth at the given position.
        virtual double getItem(PixelPosition Position) const = 0;
        /// \brief Sets the buffer's depth at the given position.
        virtual void setItem(PixelPosition Position, double value) = 0;
    };
}