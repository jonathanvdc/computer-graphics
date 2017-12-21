#pragma once
#include <memory>
#include "IBitmap.h"
#include "IBrush.h"
#include "ISegment.h"

namespace Engine
{
    /// \brief Provides a common interface for segments that can draw
    /// themselves on a bitmap.
    struct IBitmapSegment : public virtual ISegment
    {
        /// \brief Draws the segment on the target bitmap with the given
        /// brush.
        virtual void Draw(std::shared_ptr<IBitmap> Target, std::shared_ptr<IBrush> Brush) = 0;
    };
}