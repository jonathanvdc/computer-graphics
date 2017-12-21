#pragma once
#include <memory>
#include "IRenderTarget.h"
#include "VectorPathBase.h"

namespace Engine
{
    /// \brief Defines a render target for vector graphics.
    struct IVectorRenderTarget : public virtual IRenderTarget
    {
        /// \brief Adds a mutable vector path to the render target and
        /// returns it.
        virtual std::shared_ptr<VectorPathBase> AddPath() = 0;
    };
}