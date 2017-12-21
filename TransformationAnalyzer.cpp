#include "TransformationAnalyzer.h"

#include <memory>
#include "CompositeTransformation.h"
#include "EmptyTransformation.h"
#include "ITransformation.h"
#include "Vector2.h"

using namespace Engine;

TransformationAnalyzer::TransformationAnalyzer()
{
    this->setTransformation(std::make_shared<EmptyTransformation<Vector2>>());
    this->setInvertedTransformation(std::make_shared<EmptyTransformation<Vector2>>());
}

TransformationAnalyzer::TransformationAnalyzer(std::shared_ptr<ITransformation<Vector2>> Transformation, std::shared_ptr<ITransformation<Vector2>> InvertedTransformation)
{
    this->setTransformation(Transformation);
    this->setInvertedTransformation(InvertedTransformation);
}

TransformationAnalyzer TransformationAnalyzer::AddTransformation(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    auto totalTrans = std::make_shared<CompositeTransformation<Vector2>>(this->getTransformation(), 
                                                                         Transformation);
    auto totalInvTrans = std::make_shared<CompositeTransformation<Vector2>>(Transformation->Invert(), 
                                                                            this->getInvertedTransformation());
    return TransformationAnalyzer(totalTrans, totalInvTrans);
}

std::shared_ptr<ITransformation<Vector2>> TransformationAnalyzer::getInvertedTransformation() const
{
    return this->InvertedTransformation_value;
}

void TransformationAnalyzer::setInvertedTransformation(std::shared_ptr<ITransformation<Vector2>> value)
{
    this->InvertedTransformation_value = value;
}

std::shared_ptr<ITransformation<Vector2>> TransformationAnalyzer::getTransformation() const
{
    return this->Transformation_value;
}

void TransformationAnalyzer::setTransformation(std::shared_ptr<ITransformation<Vector2>> value)
{
    this->Transformation_value = value;
}