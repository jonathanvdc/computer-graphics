#pragma once
#include <memory>
#include "IDepthBuffer.h"
#include "ISurface.h"

namespace Engine
{
    struct IRenderContext;
    struct IShape;

    /// \brief Describes a render target, which is a surface that can be
    /// drawn to.
    struct IRenderTarget : public virtual ISurface
    {
        /// \brief Gets the render target's render context, which supports the
        /// creation of shapes to draw on this render target.
        virtual std::shared_ptr<IRenderContext> getContext() const = 0;

        /// \brief Gets the render target's depth buffer.
        virtual std::shared_ptr<IDepthBuffer> getDepthBuffer() const = 0;
    };
}