#include "NormalizedShape.h"

#include <algorithm>
#include <memory>
#include "CompositeTransformation.h"
#include "IShape.h"
#include "ITransformation.h"
#include "RectangleBounds.h"
#include "ScaleTransformation.h"
#include "TransformingShapeBase.h"
#include "TranslateTransformation.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a new normalized shape from the given arguments.
NormalizedShape::NormalizedShape(std::shared_ptr<IShape> Contents, double Size, double Scale)
{
    this->setContents(Contents);
    this->setSize(Size);
    this->setScale(Scale);
}

/// \brief Gets the transformation that is to be applied to the
/// contents.
std::shared_ptr<ITransformation<Vector2>> NormalizedShape::GetTransformation() const
{
    auto contentBounds = this->getContents()->getBounds();
    double contentMaxSize = std::max<double>(contentBounds.getWidth(), 
                                             contentBounds.getHeight());
    double imageX = this->getSize() * contentBounds.getWidth() / contentMaxSize;
    double imageY = this->getSize() * contentBounds.getHeight() / contentMaxSize;
    double d = this->getScale() * this->getSize() / contentMaxSize;
    auto scaleTransform = std::make_shared<ScaleTransformation>(Vector2(d, d));
    double dx = imageX / 2.0 - d * contentBounds.getCenter().X;
    double dy = imageY / 2.0 - d * contentBounds.getCenter().Y;
    auto translateTransform = std::make_shared<TranslateTransformation>(Vector2(dx, dy));
    return std::shared_ptr<CompositeTransformation<Vector2>>(new CompositeTransformation<Vector2>(scaleTransform, 
                                                                                                  translateTransform));
}

/// \brief Gets the transforming shape base's bounds.
RectangleBounds NormalizedShape::getBounds() const
{
    auto contentBounds = this->getContents()->getBounds();
    double contentMaxSize = std::max<double>(contentBounds.getWidth(), 
                                             contentBounds.getHeight());
    double imageX = this->getSize() * contentBounds.getWidth() / contentMaxSize;
    double imageY = this->getSize() * contentBounds.getHeight() / contentMaxSize;
    return RectangleBounds(0.0, 0.0, imageX, imageY);
}

/// \brief Gets a scaling factor that is applied to the shape.
double NormalizedShape::getScale() const
{
    return this->Scale_value;
}

/// \brief Sets a scaling factor that is applied to the shape.
void NormalizedShape::setScale(double value)
{
    this->Scale_value = value;
}

/// \brief Gets the size of the resulting shape's greatest dimension.
double NormalizedShape::getSize() const
{
    return this->Size_value;
}

/// \brief Sets the size of the resulting shape's greatest dimension.
void NormalizedShape::setSize(double value)
{
    this->Size_value = value;
}