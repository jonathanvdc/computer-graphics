#pragma once
#include <memory>
#include "ITransformation.h"
#include "Vector2.h"

namespace Engine
{
    class TransformationAnalyzer
    {
    public:
        TransformationAnalyzer();
        TransformationAnalyzer(std::shared_ptr<ITransformation<Vector2>> Transformation, std::shared_ptr<ITransformation<Vector2>> InvertedTransformation);

        TransformationAnalyzer AddTransformation(std::shared_ptr<ITransformation<Vector2>> Transformation) const;

        std::shared_ptr<ITransformation<Vector2>> getInvertedTransformation() const;

        std::shared_ptr<ITransformation<Vector2>> getTransformation() const;
    private:
        void setInvertedTransformation(std::shared_ptr<ITransformation<Vector2>> value);

        void setTransformation(std::shared_ptr<ITransformation<Vector2>> value);

        std::shared_ptr<ITransformation<Vector2>> InvertedTransformation_value;
        std::shared_ptr<ITransformation<Vector2>> Transformation_value;
    };
}