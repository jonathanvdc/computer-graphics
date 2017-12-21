#pragma once
#include <memory>
#include "IMesh.h"
#include "IProjection.h"
#include "IShape.h"
#include "ISkin.h"
#include "ITransformation.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a mengersponge mesh.
    class Mengersponge : public virtual IMesh
    {
    public:
        /// \brief Creates a new mengersponge mesh from the given number of
        /// iterations and skin.
        Mengersponge(int IterationCount, std::shared_ptr<ISkin> Skin);

        /// \brief Gets the mengersponge's number of iterations.
        int getIterationCount() const;

        /// \brief Gets the mengersponge's skin.
        std::shared_ptr<ISkin> getSkin() const;

        std::shared_ptr<IMesh> Lower() const;

        /// \brief Projects the mesh on a two-dimensional canvas based on the
        /// given projection.
        std::shared_ptr<IShape> Project(std::shared_ptr<IProjection> Projection) const override;

        /// \brief Transforms the mesh with the given transformation.
        std::shared_ptr<IMesh> Transform(std::shared_ptr<ITransformation<Vector3>> Transformation) const override;
    private:
        /// \brief Sets the mengersponge's number of iterations.
        void setIterationCount(int value);

        /// \brief Sets the mengersponge's skin.
        void setSkin(std::shared_ptr<ISkin> value);

        int IterationCount_value;
        std::shared_ptr<ISkin> Skin_value;
    };
}