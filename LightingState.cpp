#include "LightingState.h"

#include <memory>
#include "ArraySlice.h"
#include "ILight.h"
#include "Vector4.h"

using namespace Engine;

/// \brief Creates a new lighting state from the given ambient color
/// and array of lights.
LightingState::LightingState(Vector4 AmbientColor, stdx::ArraySlice<std::shared_ptr<ILight>> Lights)
    : AmbientColor(AmbientColor), Lights(Lights)
{ }