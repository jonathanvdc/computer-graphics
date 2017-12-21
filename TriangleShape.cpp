#include "TriangleShape.h"

#include <memory>
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "IShape.h"
#include "ITransformation.h"
#include "RectangleBounds.h"
#include "RenderTriangleCommand.h"
#include "Triangle.h"
#include "Vector2.h"

using namespace Engine;

TriangleShape::TriangleShape()
{ }

/// \brief Creates a new triangle shape from the given triangle.
TriangleShape::TriangleShape(Triangle<Vector2> Value)
    : Value(Value)
{ }

/// \brief Creates a new triangle shape from the given points.
TriangleShape::TriangleShape(Vector2 A, Vector2 B, Vector2 C)
    : Value(A, B, C)
{ }

/// \brief Creates a render command for this shape.
std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> TriangleShape::Render(std::shared_ptr<IBrush> Brush) const
{
    return std::make_shared<RenderTriangleCommand>(this->Value, Brush);
}

/// \brief Creates a new shape that corresponds to this shape after
/// the given transformation has been applied.
std::shared_ptr<IShape> TriangleShape::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    return std::make_shared<TriangleShape>(this->Value.Transform(Transformation));
}

/// \brief Gets the shape's rectangular bounds.
RectangleBounds TriangleShape::getBounds() const
{
    RectangleBounds result(this->Value.A);
    result = result.Union(RectangleBounds(this->Value.B));
    result = result.Union(RectangleBounds(this->Value.C));
    return result;
}