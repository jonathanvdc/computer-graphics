#pragma once
#include "IBrush.h"
#include "PixelPosition.h"
#include "Vector2.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Describes a radial gradient brush.
    class RadialGradientBrush : public virtual IBrush
    {
    public:
        /// \brief Creates a new radial color brush based on the given
        /// arguments.
        RadialGradientBrush(Vector2 Center, double Radius, Vector4 ColorStart, Vector4 ColorEnd);

        /// \brief Gets the radial gradient's center.
        Vector2 getCenter() const;

        /// \brief Gets the brush's color at the given position.
        Vector4 GetColor(PixelPosition Position) override;

        /// \brief Gets the brush's end color.
        Vector4 getColorEnd() const;

        /// \brief Gets the brush's start color.
        Vector4 getColorStart() const;

        /// \brief Gets the radial gradient's radius.
        double getRadius() const;
    private:
        /// \brief Sets the radial gradient's center.
        void setCenter(Vector2 value);

        /// \brief Sets the brush's end color.
        void setColorEnd(Vector4 value);

        /// \brief Sets the brush's start color.
        void setColorStart(Vector4 value);

        /// \brief Sets the radial gradient's radius.
        void setRadius(double value);

        Vector2 Center_value;
        Vector4 ColorEnd_value;
        Vector4 ColorStart_value;
        double Radius_value;
    };
}