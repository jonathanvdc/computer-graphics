#pragma once
#include <memory>
#include "ArraySlice.h"
#include "Face.h"
#include "IMesh.h"
#include "IProjection.h"
#include "IShape.h"
#include "ISkin.h"
#include "ITransformation.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Defines a wireframe mesh: a mesh that is closely related
    /// to a polyhedron. It consists of an array of points and an
    /// array of "faces", although these faces are actually
    /// multi-lines.
    /// \remark The major difference between the Polyhedron type and a
    /// Wireframe is that the former "closes" its faces when
    /// projecting, whereas the latter renders them as a
    /// multi-line. A wireframe is also only intended to have its
    /// outline drawn. A polyhedron, on the other hand, can be
    /// filled. TL;DR: A wireframe is the 3D equivalent of a
    /// multi-line array, a polyhedron the equivalent of a polygon
    /// array.
    class Wireframe : public virtual IMesh
    {
    public:
        /// \brief Creates a new wireframe mesh from the given points and
        /// multi-lines.
        Wireframe(stdx::ArraySlice<Vector3> Points, stdx::ArraySlice<Face> Lines, std::shared_ptr<ISkin> Skin);

        /// \brief Gets the wireframe's multi-lines, which are stored as
        /// faces.
        stdx::ArraySlice<Face> getLines() const;

        /// \brief Gets the wireframe's points.
        stdx::ArraySlice<Vector3> getPoints() const;

        /// \brief Gets the wireframe's skin.
        std::shared_ptr<ISkin> getSkin() const;

        std::shared_ptr<IMesh> MakeThickWireframe(double SphereRadius, int n, int m) const;

        /// \brief Creates an "optimized" wireframe: a wireframe without
        /// duplicate points or lines.
        std::shared_ptr<Wireframe> Optimize() const;

        /// \brief Creates an "optimized" wireframe: a wireframe without
        /// duplicate lines.
        std::shared_ptr<Wireframe> OptimizeLines() const;

        /// \brief Projects the mesh on a two-dimensional canvas based on the
        /// given projection.
        std::shared_ptr<IShape> Project(std::shared_ptr<IProjection> Projection) const override;

        /// \brief Transforms the mesh with the given transformation.
        std::shared_ptr<IMesh> Transform(std::shared_ptr<ITransformation<Vector3>> Transformation) const override;
    private:
        /// \brief Sets the wireframe's multi-lines, which are stored as
        /// faces.
        void setLines(stdx::ArraySlice<Face> value);

        /// \brief Sets the wireframe's points.
        void setPoints(stdx::ArraySlice<Vector3> value);

        /// \brief Sets the wireframe's skin.
        void setSkin(std::shared_ptr<ISkin> value);

        stdx::ArraySlice<Face> Lines_value;
        stdx::ArraySlice<Vector3> Points_value;
        std::shared_ptr<ISkin> Skin_value;
    };
}