#include "RenderBitmapSegmentCommand.h"

#include <memory>
#include "IBitmap.h"
#include "IBitmapSegment.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"

using namespace Engine;

/// \brief Creates a new bitmap segment render command from the given
/// segment and brush.
RenderBitmapSegmentCommand::RenderBitmapSegmentCommand(std::shared_ptr<IBitmapSegment> Segment, std::shared_ptr<IBrush> Brush)
{
    this->setSegment(Segment);
    this->setBrush(Brush);
}

/// \brief Executes the command on the given target.
void RenderBitmapSegmentCommand::Execute(std::shared_ptr<IRenderTarget> Target)
{
    this->getSegment()->Draw(std::dynamic_pointer_cast<IBitmap>(Target), 
                             this->getBrush());
}

/// \brief Sets the brush to draw the segment with.
void RenderBitmapSegmentCommand::setBrush(std::shared_ptr<IBrush> value)
{
    this->Brush_value = value;
}

/// \brief Gets the brush to draw the segment with.
std::shared_ptr<IBrush> RenderBitmapSegmentCommand::getBrush() const
{
    return this->Brush_value;
}

/// \brief Sets the bitmap segment to render.
void RenderBitmapSegmentCommand::setSegment(std::shared_ptr<IBitmapSegment> value)
{
    this->Segment_value = value;
}

/// \brief Gets the bitmap segment to render.
std::shared_ptr<IBitmapSegment> RenderBitmapSegmentCommand::getSegment() const
{
    return this->Segment_value;
}