#include "ConstantDepthBuffer.h"

#include <limits>
#include "Contracts.h"
#include "IDepthBuffer.h"
#include "PixelPosition.h"

using namespace Engine;

/// \brief Creates a new constant depth buffer with a positive
/// infinite depth.
/// \pre require(Width > 0.0 && Height > 0.0);
ConstantDepthBuffer::ConstantDepthBuffer(double Width, double Height)
{
    require(Width > 0.0 && Height > 0.0);
    this->setWidth(Width);
    this->setHeight(Height);
    this->setDepth(std::numeric_limits<double>::infinity());
}

/// \brief Creates a new constant depth buffer based on the given
/// depth.
/// \pre require(Width > 0.0 && Height > 0.0);
ConstantDepthBuffer::ConstantDepthBuffer(double Width, double Height, double Depth)
{
    require(Width > 0.0 && Height > 0.0);
    this->setWidth(Width);
    this->setHeight(Height);
    this->setDepth(Depth);
}

/// \brief Sets the depth buffer's depth.
void ConstantDepthBuffer::setDepth(double value)
{
    this->Depth_value = value;
}

/// \brief Gets the depth buffer's depth.
double ConstantDepthBuffer::getDepth() const
{
    return this->Depth_value;
}

/// \brief Sets the constant depth buffer's height.
void ConstantDepthBuffer::setHeight(double value)
{
    this->Height_value = value;
}

/// \brief Gets the constant depth buffer's height.
double ConstantDepthBuffer::getHeight() const
{
    return this->Height_value;
}

/// \brief Gets the buffer's depth at the given position.
double ConstantDepthBuffer::getItem(PixelPosition Position) const
{
    return this->getDepth();
}

/// \brief Sets the buffer's depth at the given position.
void ConstantDepthBuffer::setItem(PixelPosition Position, double value)
{ }

/// \brief Sets the constant depth buffer's width.
void ConstantDepthBuffer::setWidth(double value)
{
    this->Width_value = value;
}

/// \brief Gets the constant depth buffer's width.
double ConstantDepthBuffer::getWidth() const
{
    return this->Width_value;
}