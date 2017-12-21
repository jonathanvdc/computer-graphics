#include "LineDepthBrush.h"

#include <memory>
#include "DepthBrushBase.h"
#include "IBrush.h"
#include "IDepthBuffer.h"
#include "PixelPosition.h"
#include "ProjectedLineSegment.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new line depth brush from the given brush, depth
/// buffer and projected line segment.
LineDepthBrush::LineDepthBrush(std::shared_ptr<IBrush> Brush, std::shared_ptr<IDepthBuffer> DepthBuffer, ProjectedLineSegment Segment)
{
    this->Brush = Brush;
    this->DepthBuffer = DepthBuffer;
    this->Segment = Segment;
}

/// \brief Gets the mesh's depth at the given pixel position.
double LineDepthBrush::GetDepth(PixelPosition Position) const
{
    auto offset1 = Position.getAbsolutePosition() - 
                   this->Segment.ProjectedStartPosition;
    auto offset2 = this->Segment.ProjectedStartPosition - 
                   this->Segment.ProjectedEndPosition;
    double p = offset1.getLength() / offset2.getLength();
    return (1.0 - p) / this->Segment.StartPosition.Z + 
           p / this->Segment.EndPosition.Z;
}