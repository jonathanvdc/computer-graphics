#pragma once
#include <memory>
#include "IDepthBuffer.h"
#include "ILight.h"
#include "ILightComponent.h"
#include "IProjection.h"
#include "ITransformation.h"
#include "ReflectionProperties.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Engine
{
    /// \brief Defines a point light that casts shadows.
    /// \remark A shadow point light's position has already been
    /// transformed by the scene's global transformation.
    /// The light's "global transformation" thus performs a
    /// transformation of an already transformed point (to
    /// accomodate the camera), making it face the shadow point
    /// light instead.
    class ShadowPointLight : public virtual ILight
    {
    public:
        /// \brief Creates a shadow point light from the given arguments.
        ShadowPointLight(Vector3 Position, std::shared_ptr<ILightComponent> Component, std::shared_ptr<IDepthBuffer> Mask, std::shared_ptr<ITransformation<Vector3>> GlobalTransformation, std::shared_ptr<IProjection> Projection, std::shared_ptr<ITransformation<Vector2>> ShapeTransformation);

        /// \brief Gets the light's color for the given point, normal and
        /// reflection properties.
        Vector4 GetColor(Vector3 Point, Vector3 Normal, ReflectionProperties Properties) const override;

        /// \brief Determines whether the given point is shadowed by another
        /// point.
        bool IsShadowed(Vector3 Point) const;

        /// \brief The shadow point light's component.
        std::shared_ptr<ILightComponent> Component;
        /// \brief The shadow point light's global transformation, which
        /// makes already projected points face the shadow point light
        /// instead of the camera.
        std::shared_ptr<ITransformation<Vector3>> GlobalTransformation;
        /// \brief The shadow point light's depth mask.
        std::shared_ptr<IDepthBuffer> Mask;
        /// \brief The shadow point light's position.
        Vector3 Position;
        /// \brief The shadow point light's projection.
        std::shared_ptr<IProjection> Projection;
        /// \brief The shadow point light's two-dimensional shape
        /// transformation.
        std::shared_ptr<ITransformation<Vector2>> ShapeTransformation;
    private:
        /// \brief Clamps the given integer between the given values.
        int Clamp(int Value, int Min, int Max) const;
    };
}