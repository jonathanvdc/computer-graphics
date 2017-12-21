#pragma once
#include <memory>
#include <vector>
#include "ArraySlice.h"
#include "Face.h"
#include "IMesh.h"
#include "IProjection.h"
#include "IShape.h"
#include "ISkin.h"
#include "ITransformation.h"
#include "Vector3.h"
#include "Wireframe.h"

namespace Engine
{
    /// \brief Defines a polyhedron: a generic mesh that contains a
    /// collection of faces and points and whose projection results
    /// in an array of polygons.
    class Polyhedron : public virtual IMesh
    {
    public:
        Polyhedron(stdx::ArraySlice<stdx::ArraySlice<Vector3>> Faces, std::shared_ptr<ISkin> Skin);
        /// \brief Creates a new polyhedron from an array of points and an
        /// array of faces. This polyhedron will have its outline
        /// stroked, rather than being filled completely.
        Polyhedron(stdx::ArraySlice<Vector3> Points, stdx::ArraySlice<Face> Faces, std::shared_ptr<ISkin> Skin);

        /// \brief Gets the polyhedron's faces.
        stdx::ArraySlice<Face> getFaces() const;

        /// \brief Gets all points in the polyhedron.
        stdx::ArraySlice<Vector3> getPoints() const;

        /// \brief Gets the polyhedron's skin.
        std::shared_ptr<ISkin> getSkin() const;

        std::shared_ptr<Polyhedron> MakeDual() const;

        std::shared_ptr<IMesh> MakeFractal(double ScaleFactor, int IterationCount) const;

        /// \brief Creates an "optimized" polyhedron: a polyhedron without
        /// duplicate points.
        std::shared_ptr<Polyhedron> Optimize() const;

        /// \brief Projects the mesh on a two-dimensional canvas based on the
        /// given projection.
        std::shared_ptr<IShape> Project(std::shared_ptr<IProjection> Projection) const override;

        /// \brief Converts this polyhedron to an equivalent wireframe.
        std::shared_ptr<Wireframe> ToWireframe() const;

        /// \brief Transforms the mesh with the given transformation.
        std::shared_ptr<IMesh> Transform(std::shared_ptr<ITransformation<Vector3>> Transformation) const override;

        std::shared_ptr<Polyhedron> Truncate(double SubdivisionFactor) const;

        /// \brief Gets the polyhedron's center.
        Vector3 getCenter() const;
    private:
        bool Contains(std::vector<Face> Faces, Face Value) const;

        stdx::ArraySlice<Vector3> CreateDualFace(int PointIndex, Vector3 Center) const;

        Face GetAdjacentFace(int PointIndex) const;

        std::vector<Face> GetAdjacentFaces(int PointIndex) const;

        std::vector<int> GetSharedEdgePoints(int PointIndex, Face Current, Face Previous) const;

        stdx::ArraySlice<std::shared_ptr<IMesh>> MakeFractalMeshes(double ScaleFactor) const;

        stdx::ArraySlice<std::shared_ptr<IMesh>> MakeFractalMeshes(stdx::ArraySlice<std::shared_ptr<IMesh>> Meshes, int PointCount, double ScaleFactor) const;

        stdx::ArraySlice<std::shared_ptr<IMesh>> MakeFractalMeshes(stdx::ArraySlice<std::shared_ptr<IMesh>> Meshes, int PointCount, double ScaleFactor, int IterationCount) const;

        stdx::ArraySlice<Vector3> Reorient(std::vector<Vector3> FacePoints, Vector3 Center) const;

        /// \brief Sets the polyhedron's faces.
        void setFaces(stdx::ArraySlice<Face> value);

        /// \brief Sets all points in the polyhedron.
        void setPoints(stdx::ArraySlice<Vector3> value);

        /// \brief Sets the polyhedron's skin.
        void setSkin(std::shared_ptr<ISkin> value);

        stdx::ArraySlice<Vector3> TruncateFace(Face Value, double SubdivisionFactor) const;

        std::vector<Vector3> TruncatePoint(int PointIndex, double SubdivisionFactor) const;

        stdx::ArraySlice<Face> Faces_value;
        stdx::ArraySlice<Vector3> Points_value;
        std::shared_ptr<ISkin> Skin_value;
    };
}