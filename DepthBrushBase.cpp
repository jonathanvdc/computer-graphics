#include "DepthBrushBase.h"

#include <memory>
#include "IBrush.h"
#include "IDepthBuffer.h"
#include "PixelPosition.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates an empty depth brush.
DepthBrushBase::DepthBrushBase()
{ }

/// \brief Creates a depth brush based on the given brush and depth
/// buffer.
DepthBrushBase::DepthBrushBase(std::shared_ptr<IBrush> Brush, std::shared_ptr<IDepthBuffer> DepthBuffer)
    : Brush(Brush), DepthBuffer(DepthBuffer)
{ }

/// \brief Gets the brush's color at the given position.
Vector4 DepthBrushBase::GetColor(PixelPosition Position)
{
    double depth = this->GetDepth(Position);
    if (depth <= this->DepthBuffer->getItem(Position))
    {
        this->DepthBuffer->setItem(Position, depth);
        return this->Brush->GetColor(Position);
    }
    else
    {
        return Vector4(0.0, 0.0, 0.0, 0.0);
    }
}