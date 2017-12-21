#include "ZBuffer.h"

#include <limits>
#include <vector>
#include "Contracts.h"
#include "IDepthBuffer.h"
#include "PixelPosition.h"

using namespace Engine;

/// \brief Creates a new Z-buffer from the given width and height.
/// The buffer's data is initialized to +inf.
/// \pre require(Width > 0 && Height > 0);
ZBuffer::ZBuffer(int Width, int Height)
{
    require(Width > 0 && Height > 0);
    this->Clear(Width, Height, 
                std::numeric_limits<double>::infinity());
}

/// \brief Creates a new Z-buffer from the given width and height.
/// The buffer's data is initialized to the given initial
/// value.
/// \pre require(Width > 0 && Height > 0);
ZBuffer::ZBuffer(int Width, int Height, double InitialValue)
{
    require(Width > 0 && Height > 0);
    this->Clear(Width, Height, InitialValue);
}

/// \brief Clears the buffer and sets it data to +inf.
void ZBuffer::Clear()
{
    this->Clear(std::numeric_limits<double>::infinity());
}

/// \brief Clears the buffer and sets its data to the given initial
/// value.
void ZBuffer::Clear(double InitialValue)
{
    this->Clear(this->getPixelWidth(), this->getPixelHeight(), 
                InitialValue);
}

/// \brief Clears the buffer with the given width and height.
/// Its data is set to the given initial value.
/// \pre require(width > 0 && height > 0);
void ZBuffer::Clear(int width, int height, double InitialValue)
{
    require(width > 0 && height > 0);
    this->pixBuf = std::vector<std::vector<double>>(width, 
                                                    std::vector<double>(height, InitialValue));
}

/// \brief Gets the Z-buffer's height as a double-precision
/// floating-point number.
double ZBuffer::getHeight() const
{
    return (double)this->getPixelHeight();
}

/// \brief Gets the buffer's depth at the given position.
/// \pre require(Position.X >= 0 && (double)Position.X < this->getWidth());
/// \pre require(Position.Y >= 0 && (double)Position.Y < this->getHeight());
double ZBuffer::getItem(PixelPosition Position) const
{
    require(Position.X >= 0 && (double)Position.X < this->getWidth());
    require(Position.Y >= 0 && (double)Position.Y < this->getHeight());
    return this->getItem(Position.X, Position.Y);
}

/// \brief Sets the buffer's depth at the given position.
/// \pre require(Position.X >= 0 && (double)Position.X < this->getWidth());
/// \pre require(Position.Y >= 0 && (double)Position.Y < this->getHeight());
void ZBuffer::setItem(PixelPosition Position, double value)
{
    require(Position.X >= 0 && (double)Position.X < this->getWidth());
    require(Position.Y >= 0 && (double)Position.Y < this->getHeight());
    this->setItem(Position.X, Position.Y, value);
}

/// \brief Gets the Z-buffer's depth at the given position, specified
/// as a pair of integer coordinates.
/// \pre require(X >= 0 && (double)X < this->getWidth());
/// \pre require(Y >= 0 && (double)Y < this->getHeight());
double ZBuffer::getItem(int X, int Y) const
{
    require(X >= 0 && (double)X < this->getWidth());
    require(Y >= 0 && (double)Y < this->getHeight());
    return this->pixBuf[X][Y];
}

/// \brief Sets the Z-buffer's depth at the given position, specified
/// as a pair of integer coordinates.
/// \pre require(X >= 0 && (double)X < this->getWidth());
/// \pre require(Y >= 0 && (double)Y < this->getHeight());
void ZBuffer::setItem(int X, int Y, double value)
{
    require(X >= 0 && (double)X < this->getWidth());
    require(Y >= 0 && (double)Y < this->getHeight());
    this->pixBuf[X][Y] = value;
}

/// \brief Gets the number of pixels the Z-buffer has in the
/// Y-dimension.
int ZBuffer::getPixelHeight() const
{
    auto col = this->pixBuf[0];
    return (int)col.size();
}

/// \brief Gets the number of pixels the Z-buffer has in the
/// X-dimension.
int ZBuffer::getPixelWidth() const
{
    return (int)this->pixBuf.size();
}

/// \brief Gets the Z-buffer's width as a double-precision
/// floating-point number.
double ZBuffer::getWidth() const
{
    return (double)this->getPixelWidth();
}