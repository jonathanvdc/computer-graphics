#pragma once
#include "Vector2.h"

namespace Engine
{
    /// \brief Describes a two-dimensional bounding rectangle.
    struct RectangleBounds
    {
        /// \brief Creates rectangular bounds from the point at the origin.
        RectangleBounds();
        /// \brief Creates rectangular bounds from a single point.
        RectangleBounds(Vector2 Point);
        /// \brief Creates rectangular bounds from the given arguments.
        /// \pre require(MinX <= MaxX);
        /// \pre require(MinY <= MaxY);
        RectangleBounds(double MinX, double MinY, double MaxX, double MaxY);

        /// \brief Creates a bounding rectangle that covers the union of this
        /// rectangle and the given rectangle.
        RectangleBounds Union(RectangleBounds Other) const;

        /// \brief Gets the bounding rectangle's center.
        Vector2 getCenter() const;

        /// \brief Gets the bounding rectangle's height.
        double getHeight() const;

        /// \brief Gets the bounding rectangle's width.
        double getWidth() const;

        /// \brief Checks if this bounding rectangle equals the given other
        /// rectangle.
        bool operator==(RectangleBounds Bounds) const;

        /// \brief Checks if this bounding rectangle is not equal to the
        /// given other rectangle.
        bool operator!=(RectangleBounds Bounds) const;

        /// \brief The bounding rectangle's greatest X-coordinate.
        double MaxX;
        /// \brief The bounding rectangle's greatest Y-coordinate.
        double MaxY;
        /// \brief The bounding rectangle's smallest X-coordinate.
        double MinX;
        /// \brief The bounding rectangle's smallest Y-coordinate.
        double MinY;
    };
}