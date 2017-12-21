#include "ProjectedLineSegmentRenderCommand.h"

#include <initializer_list>
#include <memory>
#include "ArraySlice.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IPartialSegment.h"
#include "IRenderContext.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "LineDepthBrush.h"
#include "ProjectedLineSegment.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a new projected line segment render command based
/// on the given segment and brush.
ProjectedLineSegmentRenderCommand::ProjectedLineSegmentRenderCommand(ProjectedLineSegment Segment, std::shared_ptr<IBrush> Brush)
    : Segment(Segment), Brush(Brush)
{ }

/// \brief Executes the command on the given target.
void ProjectedLineSegmentRenderCommand::Execute(std::shared_ptr<IRenderTarget> Target)
{
    auto context = Target->getContext();
    auto seg = this->Segment;
    stdx::ArraySlice<std::shared_ptr<IPartialSegment>> segments({
                                                                    context->CreateLineSegment(seg.ProjectedStartPosition)
                                                                });
    auto brush = std::make_shared<LineDepthBrush>(this->Brush, 
                                                  Target->getDepthBuffer(), 
                                                  seg);
    auto sPath = context->StrokePath(segments, seg.ProjectedEndPosition);
    sPath->Render(brush)->Execute(Target);
}