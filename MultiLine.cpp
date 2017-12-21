#include "MultiLine.h"

#include <memory>
#include "ArraySlice.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITransformation.h"
#include "MultiLineRenderCommand.h"
#include "RectangleBounds.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a new empty multi-line.
MultiLine::MultiLine()
{ }

/// \brief Creates a multi-line from the given points.
/// The resulting multi-line will be configured to draw its
/// outlines.
MultiLine::MultiLine(stdx::ArraySlice<Vector2> Points)
{
    this->setPoints(Points);
    this->setFillPath(false);
}

/// \brief Creates a multi-line from the given points and a boolean
/// flag that indicates whether the multi-line is to be filled
/// as a polygon or merely have its outline drawn.
MultiLine::MultiLine(stdx::ArraySlice<Vector2> Points, bool FillPath)
{
    this->setPoints(Points);
    this->setFillPath(FillPath);
}

/// \brief Creates a render command for this shape.
std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> MultiLine::Render(std::shared_ptr<IBrush> Brush) const
{
    return std::make_shared<MultiLineRenderCommand>(this->getPoints(), 
                                                    Brush, 
                                                    this->getFillPath());
}

/// \brief Creates a new shape that corresponds to this shape after
/// the given transformation has been applied.
std::shared_ptr<IShape> MultiLine::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    auto oldPoints = this->getPoints();
    stdx::ArraySlice<Vector2> newPoints(oldPoints.GetLength());
    for (int i = 0; i < newPoints.GetLength(); ++i)
        newPoints[i] = Transformation->Transform(oldPoints[i]);
    return std::make_shared<MultiLine>(newPoints, this->getFillPath());
}

/// \brief Gets the shape's rectangular bounds.
RectangleBounds MultiLine::getBounds() const
{
    RectangleBounds result(this->getPoints()[0]);
    for (int i = 1; i < this->getPoints().GetLength(); ++i)
        result = result.Union(RectangleBounds(this->getPoints()[i]));
    return result;
}

/// \brief Sets a boolean flag that indicates whether the multi-line
/// is to be filled as a polygon or merely have its outline
/// drawn.
void MultiLine::setFillPath(bool value)
{
    this->FillPath_value = value;
}

/// \brief Gets a boolean flag that indicates whether the multi-line
/// is to be filled as a polygon or merely have its outline
/// drawn.
bool MultiLine::getFillPath() const
{
    return this->FillPath_value;
}

/// \brief Gets the array that contains this multi-line's points.
stdx::ArraySlice<Vector2> MultiLine::getPoints() const
{
    return this->Points_value;
}

/// \brief Sets the array that contains this multi-line's points.
void MultiLine::setPoints(stdx::ArraySlice<Vector2> value)
{
    this->Points_value = value;
}