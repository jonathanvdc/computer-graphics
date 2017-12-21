#pragma once
#include <memory>
#include "ArraySlice.h"
#include "DepthBrushBase.h"
#include "IBrush.h"
#include "IDepthBuffer.h"
#include "PixelPosition.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a depth brush for a projected polygon.
    class PolygonDepthBrush : public DepthBrushBase
    {
    public:
        /// \brief Creates a new polygon depth brush from the given
        /// arguments.
        /// \remark This constructor performs an eager initialization of the
        /// brush object.
        PolygonDepthBrush(std::shared_ptr<IBrush> Brush, std::shared_ptr<IDepthBuffer> DepthBuffer, stdx::ArraySlice<Vector2> ProjectedPoints, stdx::ArraySlice<Vector3> OriginalPoints, double d);

        /// \brief Gets the mesh's depth at the given pixel position.
        double GetDepth(PixelPosition Position) const override;

        /// \brief The triangle's normal vector.
        Vector3 Normal;
        /// \brief The projection distance (d).
        double ProjectionDistance;
    private:
        double dzdx;
        double dzdy;
        double pointZ;
        /// \brief One of the polygon's projected points.
        Vector2 ProjectedPoint;
    };
}