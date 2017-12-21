#include "ProjectedLineSegment.h"

#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITransformation.h"
#include "ProjectedLineSegmentRenderCommand.h"
#include "RectangleBounds.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new projected line segment of length zero at the
/// origin.
ProjectedLineSegment::ProjectedLineSegment()
    : StartPosition(), EndPosition(), ProjectedStartPosition(), ProjectedEndPosition()
{ }

/// \brief Creates a new projected line segment from the given
/// arguments.
ProjectedLineSegment::ProjectedLineSegment(Vector3 StartPosition, Vector3 EndPosition, Vector2 ProjectedStartPosition, Vector2 ProjectedEndPosition)
    : StartPosition(StartPosition), EndPosition(EndPosition), ProjectedStartPosition(ProjectedStartPosition), ProjectedEndPosition(ProjectedEndPosition)
{ }

/// \brief Creates a render command for this shape.
std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> ProjectedLineSegment::Render(std::shared_ptr<IBrush> Brush) const
{
    return std::make_shared<ProjectedLineSegmentRenderCommand>(*this, 
                                                               Brush);
}

/// \brief Creates a new shape that corresponds to this shape after
/// the given transformation has been applied.
std::shared_ptr<IShape> ProjectedLineSegment::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    return std::make_shared<ProjectedLineSegment>(this->StartPosition, 
                                                  this->EndPosition, 
                                                  Transformation->Transform(this->ProjectedStartPosition), 
                                                  Transformation->Transform(this->ProjectedEndPosition));
}

/// \brief Gets the projected line segment's rectangular bounds.
RectangleBounds ProjectedLineSegment::getBounds() const
{
    RectangleBounds start(this->ProjectedStartPosition);
    RectangleBounds end(this->ProjectedEndPosition);
    return start.Union(end);
}