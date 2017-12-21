#pragma once
#include <memory>
#include "IBitmapSegment.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"

namespace Engine
{
    /// \brief Defines a command that renders a bitmap segment.
    class RenderBitmapSegmentCommand : public virtual ICommand<std::shared_ptr<IRenderTarget>>
    {
    public:
        /// \brief Creates a new bitmap segment render command from the given
        /// segment and brush.
        RenderBitmapSegmentCommand(std::shared_ptr<IBitmapSegment> Segment, std::shared_ptr<IBrush> Brush);

        /// \brief Executes the command on the given target.
        void Execute(std::shared_ptr<IRenderTarget> Target) override;

        /// \brief Gets the brush to draw the segment with.
        std::shared_ptr<IBrush> getBrush() const;

        /// \brief Gets the bitmap segment to render.
        std::shared_ptr<IBitmapSegment> getSegment() const;
    private:
        /// \brief Sets the brush to draw the segment with.
        void setBrush(std::shared_ptr<IBrush> value);

        /// \brief Sets the bitmap segment to render.
        void setSegment(std::shared_ptr<IBitmapSegment> value);

        std::shared_ptr<IBrush> Brush_value;
        std::shared_ptr<IBitmapSegment> Segment_value;
    };
}