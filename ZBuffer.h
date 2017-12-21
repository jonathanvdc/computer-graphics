#pragma once
#include <vector>
#include "Contracts.h"
#include "IDepthBuffer.h"
#include "PixelPosition.h"

namespace Engine
{
    /// \brief The Z-buffer type is a straightforward implementation of
    /// the depth buffer interface. Each pixel can be set and
    /// retrieved individually.
    class ZBuffer : public virtual IDepthBuffer
    {
    public:
        /// \brief Creates a new Z-buffer from the given width and height.
        /// The buffer's data is initialized to +inf.
        /// \pre require(Width > 0 && Height > 0);
        ZBuffer(int Width, int Height);
        /// \brief Creates a new Z-buffer from the given width and height.
        /// The buffer's data is initialized to the given initial
        /// value.
        /// \pre require(Width > 0 && Height > 0);
        ZBuffer(int Width, int Height, double InitialValue);

        /// \brief Clears the buffer and sets it data to +inf.
        void Clear();

        /// \brief Clears the buffer and sets its data to the given initial
        /// value.
        void Clear(double InitialValue);

        /// \brief Gets the Z-buffer's height as a double-precision
        /// floating-point number.
        double getHeight() const override;

        /// \brief Gets the buffer's depth at the given position.
        /// \pre require(Position.X >= 0 && (double)Position.X < this->getWidth());
        /// \pre require(Position.Y >= 0 && (double)Position.Y < this->getHeight());
        double getItem(PixelPosition Position) const override;
        /// \brief Sets the buffer's depth at the given position.
        /// \pre require(Position.X >= 0 && (double)Position.X < this->getWidth());
        /// \pre require(Position.Y >= 0 && (double)Position.Y < this->getHeight());
        void setItem(PixelPosition Position, double value) override;

        /// \brief Gets the Z-buffer's depth at the given position, specified
        /// as a pair of integer coordinates.
        /// \pre require(X >= 0 && (double)X < this->getWidth());
        /// \pre require(Y >= 0 && (double)Y < this->getHeight());
        double getItem(int X, int Y) const;
        /// \brief Sets the Z-buffer's depth at the given position, specified
        /// as a pair of integer coordinates.
        /// \pre require(X >= 0 && (double)X < this->getWidth());
        /// \pre require(Y >= 0 && (double)Y < this->getHeight());
        void setItem(int X, int Y, double value);

        /// \brief Gets the number of pixels the Z-buffer has in the
        /// Y-dimension.
        int getPixelHeight() const;

        /// \brief Gets the number of pixels the Z-buffer has in the
        /// X-dimension.
        int getPixelWidth() const;

        /// \brief Gets the Z-buffer's width as a double-precision
        /// floating-point number.
        double getWidth() const override;
    private:
        /// \brief Clears the buffer with the given width and height.
        /// Its data is set to the given initial value.
        /// \pre require(width > 0 && height > 0);
        void Clear(int width, int height, double InitialValue);

        std::vector<std::vector<double>> pixBuf;
    };
}