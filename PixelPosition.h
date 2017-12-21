#pragma once
#include "Vector2.h"

namespace Engine
{
    /// \brief A simple data structure that encapsulates the absolute and
    /// relative position of a pixel on a surface.
    struct PixelPosition
    {
        /// \brief Creates a pixel position at the origin.
        PixelPosition();
        /// \brief Creates a new pixel position from the given arguments.
        PixelPosition(int X, int Y);
        /// \brief Creates a new pixel position from the given arguments.
        /// \pre require(RelativePosition.X >= 0.0 && RelativePosition.X <= 1.0);
        /// \pre require(RelativePosition.Y >= 0.0 && RelativePosition.Y <= 1.0);
        PixelPosition(int X, int Y, Vector2 RelativePosition);

        /// \brief Gets the pixel position's absolute position.
        Vector2 getAbsolutePosition() const;

        /// \brief The pixel position's relative position, which ranges from
        /// (0.0, 0.0) to (1.0, 1.0).
        Vector2 RelativePosition;
        /// \brief The absolute X-coordinate of the position.
        int X;
        /// \brief The absolute Y-coordinate of the position.
        int Y;
    };
}