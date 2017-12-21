#pragma once
#include <memory>
#include "IBrush.h"
#include "IMesh.h"
#include "IProjection.h"
#include "IRenderTarget.h"
#include "ITransformation.h"
#include "NormalizedShape.h"
#include "RectangleBounds.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Describes a three-dimensional scene.
    /// Scene objects encapsulate the rendering pipeline of a
    /// mesh.
    class Scene
    {
    public:
        /// \brief Creates a new scene based on the given arguments.
        Scene(std::shared_ptr<IMesh> Contents, std::shared_ptr<ITransformation<Vector3>> GlobalTransformation, std::shared_ptr<IProjection> Projection, std::shared_ptr<IBrush> Brush, double Size, double Scale);

        /// \brief Gets the scene's contents brush.
        std::shared_ptr<IBrush> getBrush() const;

        /// \brief Gets the scene's contents.
        std::shared_ptr<IMesh> getContents() const;

        /// \brief Gets the scene's global transformation.
        std::shared_ptr<ITransformation<Vector3>> getGlobalTransformation() const;

        /// \brief Gets the scene's projection.
        std::shared_ptr<IProjection> getProjection() const;

        /// \brief Gets a scaling factor that is applied to the scene.
        double getScale() const;

        /// \brief Gets the size of the scene's greatest dimension.
        double getSize() const;

        /// \brief Renders the scene to the given render target.
        void Render(std::shared_ptr<IRenderTarget> Target);

        /// \brief Gets the scene's bounds.
        RectangleBounds getBounds() const;

        /// \brief Gets the scene's height.
        double getHeight() const;

        std::shared_ptr<NormalizedShape> getProjectedShape() const;

        /// \brief Gets the scene's width.
        double getWidth() const;
    private:
        /// \brief Sets the scene's contents brush.
        void setBrush(std::shared_ptr<IBrush> value);

        /// \brief Sets the scene's contents.
        void setContents(std::shared_ptr<IMesh> value);

        /// \brief Sets the scene's global transformation.
        void setGlobalTransformation(std::shared_ptr<ITransformation<Vector3>> value);

        /// \brief Sets the scene's projection.
        void setProjection(std::shared_ptr<IProjection> value);

        /// \brief Sets a scaling factor that is applied to the scene.
        void setScale(double value);

        /// \brief Sets the size of the scene's greatest dimension.
        void setSize(double value);

        std::shared_ptr<IBrush> Brush_value;
        mutable std::shared_ptr<NormalizedShape> cachedShape;
        std::shared_ptr<IMesh> Contents_value;
        std::shared_ptr<ITransformation<Vector3>> GlobalTransformation_value;
        std::shared_ptr<IProjection> Projection_value;
        double Scale_value;
        double Size_value;
    };
}