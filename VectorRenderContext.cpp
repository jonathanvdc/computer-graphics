#include "VectorRenderContext.h"

#include <memory>
#include "ArraySlice.h"
#include "IPartialSegment.h"
#include "IRenderContext.h"
#include "IShape.h"
#include "PartialLineSegment.h"
#include "Vector2.h"
#include "VectorLinePath.h"

using namespace Engine;

/// \brief Creates a new vector render context based on the given
/// width and height.
VectorRenderContext::VectorRenderContext(double Width, double Height)
{
    this->setWidth(Width);
    this->setHeight(Height);
}

/// \brief Creates a new partial line segment that starts at the
/// given position.
std::shared_ptr<IPartialSegment> VectorRenderContext::CreateLineSegment(Vector2 Start) const
{
    return std::make_shared<PartialLineSegment>(Start);
}

/// \brief Closes the given path segments with the given end point,
/// returning a shape that represents the filled path.
std::shared_ptr<IShape> VectorRenderContext::FillPath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segments, Vector2 End) const
{
    return std::make_shared<VectorLinePath>(Segments, End, true);
}

/// \brief Closes the given path segments with the given end point,
/// returning a shape that represents the path's outline.
std::shared_ptr<IShape> VectorRenderContext::StrokePath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segments, Vector2 End) const
{
    return std::make_shared<VectorLinePath>(Segments, End);
}

void VectorRenderContext::setHeight(double value)
{
    this->Height_value = value;
}

/// \brief Gets the surface's height.
double VectorRenderContext::getHeight() const
{
    return this->Height_value;
}

void VectorRenderContext::setWidth(double value)
{
    this->Width_value = value;
}

/// \brief Gets the surface's width.
double VectorRenderContext::getWidth() const
{
    return this->Width_value;
}