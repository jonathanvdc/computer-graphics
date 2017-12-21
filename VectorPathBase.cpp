#include "VectorPathBase.h"

#include <memory>
#include "IBrush.h"
#include "IVectorInstructionStream.h"
#include "SolidColorBrush.h"
#include "Vector4.h"

using namespace Engine;

VectorPathBase::VectorPathBase()
{
    this->setFill(std::make_shared<SolidColorBrush>(Vector4(1.0, 1.0, 1.0, 0.0)));
    this->setStroke(std::make_shared<SolidColorBrush>(Vector4(1.0, 1.0, 1.0, 0.0)));
    this->setStrokeThickness(1.0);
}

/// \brief Sets the vector path's fill brush.
void VectorPathBase::setFill(std::shared_ptr<IBrush> value)
{
    this->Fill_value = value;
}

/// \brief Gets the vector path's fill brush.
std::shared_ptr<IBrush> VectorPathBase::getFill() const
{
    return this->Fill_value;
}

/// \brief Sets the vector path's stroke brush.
void VectorPathBase::setStroke(std::shared_ptr<IBrush> value)
{
    this->Stroke_value = value;
}

/// \brief Gets the vector path's stroke brush.
std::shared_ptr<IBrush> VectorPathBase::getStroke() const
{
    return this->Stroke_value;
}

/// \brief Sets the vector path's stroke thickness.
void VectorPathBase::setStrokeThickness(double value)
{
    this->StrokeThickness_value = value;
}

/// \brief Gets the vector path's stroke thickness.
double VectorPathBase::getStrokeThickness() const
{
    return this->StrokeThickness_value;
}