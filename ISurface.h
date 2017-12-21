#pragma once

namespace Engine
{
    /// \brief Describes a surface: a two-dimensional object that
    /// specifies its own dimensions.
    struct ISurface
    {
        /// \brief Gets the surface's height.
        virtual double getHeight() const = 0;

        /// \brief Gets the surface's width.
        virtual double getWidth() const = 0;
    };
}