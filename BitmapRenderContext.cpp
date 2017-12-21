#include "BitmapRenderContext.h"

#include <memory>
#include "ArraySlice.h"
#include "BitmapLinePath.h"
#include "IPartialSegment.h"
#include "IRenderContext.h"
#include "IShape.h"
#include "PartialLineSegment.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a new bitmap render context with the given
/// dimensions.
BitmapRenderContext::BitmapRenderContext(double Width, double Height)
{
    this->setWidth(Width);
    this->setHeight(Height);
}

/// \brief Creates a new partial line segment that starts at the
/// given position.
std::shared_ptr<IPartialSegment> BitmapRenderContext::CreateLineSegment(Vector2 Start) const
{
    return std::make_shared<PartialLineSegment>(Start);
}

/// \brief Closes the given path segments with the given end point,
/// returning a shape that represents the filled path.
std::shared_ptr<IShape> BitmapRenderContext::FillPath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segments, Vector2 End) const
{
    return std::make_shared<BitmapLinePath>(Segments, End, true);
}

/// \brief Closes the given path segments with the given end point,
/// returning a shape that represents the path's outline.
std::shared_ptr<IShape> BitmapRenderContext::StrokePath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segments, Vector2 End) const
{
    return std::make_shared<BitmapLinePath>(Segments, End);
}

void BitmapRenderContext::setHeight(double value)
{
    this->Height_value = value;
}

/// \brief Gets the surface's height.
double BitmapRenderContext::getHeight() const
{
    return this->Height_value;
}

void BitmapRenderContext::setWidth(double value)
{
    this->Width_value = value;
}

/// \brief Gets the surface's width.
double BitmapRenderContext::getWidth() const
{
    return this->Width_value;
}