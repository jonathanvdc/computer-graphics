#pragma once
#include "IBrush.h"
#include "PixelPosition.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Describes a solid color brush: a brush that applied the
    /// exact same color to any point of a shape.
    class SolidColorBrush : public virtual IBrush
    {
    public:
        /// \brief Creates a new solid color brush that is fully transparent.
        SolidColorBrush();
        /// \brief Creates a new solid color brush based on the given color.
        SolidColorBrush(Vector4 Color);

        /// \brief Gets the brush's color.
        Vector4 getColor() const;

        /// \brief Gets the brush's color at the given position.
        Vector4 GetColor(PixelPosition Position) override;
    private:
        /// \brief Sets the brush's color.
        void setColor(Vector4 value);

        Vector4 Color_value;
    };
}