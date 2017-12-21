#include "LightingBrush.h"

#include <memory>
#include "ArraySlice.h"
#include "DepthBrushBase.h"
#include "IBrush.h"
#include "IBrush3.h"
#include "IDepthBuffer.h"
#include "ILight.h"
#include "ITransformation.h"
#include "LightingState.h"
#include "PixelPosition.h"
#include "PolygonDepthBrush.h"
#include "ReflectionProperties.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new lighting brush from the given arguments.
LightingBrush::LightingBrush(ReflectionProperties Properties, std::shared_ptr<PolygonDepthBrush> DepthBrush, std::shared_ptr<LightingState> State, std::shared_ptr<ITransformation<Vector2>> InvertedTransformation)
    : Properties(Properties), DepthBrush(DepthBrush), State(State), InvertedTransformation(InvertedTransformation)
{ }

/// \brief Gets the brush's color at the given position.
Vector4 LightingBrush::GetColor(PixelPosition Position)
{
    double depth = this->DepthBrush->GetDepth(Position);
    if (depth <= this->DepthBrush->DepthBuffer->getItem(Position))
    {
        this->DepthBrush->DepthBuffer->setItem(Position, depth);
        double zCoord = 1.0 / depth;
        auto xyCoord = this->InvertedTransformation->Transform(Position.getAbsolutePosition()) * -zCoord;
        Vector3 pos(xyCoord, zCoord);
        auto norm = this->DepthBrush->Normal;
        auto result = this->State->AmbientColor.Scale(this->Properties.AmbientReflection->GetColor(pos));
        for (auto& item : this->State->Lights)
            result += item->GetColor(pos, norm, this->Properties);
        return result.Clamp(Vector4(0.0), Vector4(1.0));
    }
    else
    {
        return Vector4(0.0, 0.0, 0.0, 0.0);
    }
}