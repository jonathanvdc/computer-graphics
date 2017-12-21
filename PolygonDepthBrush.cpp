#include "PolygonDepthBrush.h"

#include <memory>
#include "ArraySlice.h"
#include "DepthBrushBase.h"
#include "IBrush.h"
#include "IDepthBuffer.h"
#include "PixelPosition.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new polygon depth brush from the given
/// arguments.
/// \remark This constructor performs an eager initialization of the
/// brush object.
PolygonDepthBrush::PolygonDepthBrush(std::shared_ptr<IBrush> Brush, std::shared_ptr<IDepthBuffer> DepthBuffer, stdx::ArraySlice<Vector2> ProjectedPoints, stdx::ArraySlice<Vector3> OriginalPoints, double d)
{
    this->Brush = Brush;
    this->DepthBuffer = DepthBuffer;
    auto ab = OriginalPoints[1] - OriginalPoints[0];
    auto ac = OriginalPoints[2] - OriginalPoints[0];
    auto cross = ab.Cross(ac);
    double k = cross.Dot(OriginalPoints[0]);
    auto norm = cross / -k;
    this->Normal = norm.Normalize();
    this->pointZ = 1.0 / OriginalPoints[0].Z;
    this->ProjectedPoint = ProjectedPoints[0];
    this->dzdx = norm.X / d;
    this->dzdy = norm.Y / d;
    this->ProjectionDistance = d;
}

/// \brief Gets the mesh's depth at the given pixel position.
double PolygonDepthBrush::GetDepth(PixelPosition Position) const
{
    auto offset = Position.getAbsolutePosition() - this->ProjectedPoint;
    return this->pointZ + offset.X * this->dzdx + offset.Y * this->dzdy;
}