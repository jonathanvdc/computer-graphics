#pragma once
#include <memory>
#include "ArraySlice.h"
#include "ILight.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Describes a scene's lighting state.
    struct LightingState
    {
        /// \brief Creates a new lighting state from the given ambient color
        /// and array of lights.
        LightingState(Vector4 AmbientColor, stdx::ArraySlice<std::shared_ptr<ILight>> Lights);

        /// \brief The lighting state's ambient color.
        Vector4 AmbientColor;
        /// \brief An array containing the lighting state's lights.
        stdx::ArraySlice<std::shared_ptr<ILight>> Lights;
    };
}