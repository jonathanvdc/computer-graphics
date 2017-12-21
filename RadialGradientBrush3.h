#pragma once
#include <memory>
#include "IBrush3.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Describes a three-dimensional radial gradient brush.
    class RadialGradientBrush3 : public virtual IBrush3
    {
    public:
        /// \brief Creates a new radial color brush based on the given
        /// arguments.
        RadialGradientBrush3(Vector3 Center, double Radius, std::shared_ptr<IBrush3> StartBrush, std::shared_ptr<IBrush3> EndBrush);

        /// \brief Gets the radial gradient's center.
        Vector3 getCenter() const;

        /// \brief Gets the brush's color at the given position.
        Vector4 GetColor(Vector3 Position) override;

        /// \brief Gets the radial gradient's end brush.
        std::shared_ptr<IBrush3> getEndBrush() const;

        /// \brief Gets the radial gradient's radius.
        double getRadius() const;

        /// \brief Gets the radial gradient's start brush.
        std::shared_ptr<IBrush3> getStartBrush() const;
    private:
        /// \brief Sets the radial gradient's center.
        void setCenter(Vector3 value);

        /// \brief Sets the radial gradient's end brush.
        void setEndBrush(std::shared_ptr<IBrush3> value);

        /// \brief Sets the radial gradient's radius.
        void setRadius(double value);

        /// \brief Sets the radial gradient's start brush.
        void setStartBrush(std::shared_ptr<IBrush3> value);

        Vector3 Center_value;
        std::shared_ptr<IBrush3> EndBrush_value;
        double Radius_value;
        std::shared_ptr<IBrush3> StartBrush_value;
    };
}