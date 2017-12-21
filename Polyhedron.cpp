#include "Polyhedron.h"

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <unordered_map>
#include <vector>
#include "ArraySlice.h"
#include "CompositeMesh.h"
#include "CompositeShape.h"
#include "CompositeTransformation.h"
#include "Face.h"
#include "IMesh.h"
#include "IProjection.h"
#include "IShape.h"
#include "ISkin.h"
#include "ITransformation.h"
#include "MultiLine.h"
#include "ScaleTransformation3D.h"
#include "TexturedShape.h"
#include "TranslateTransformation3D.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Wireframe.h"

using namespace Engine;

Polyhedron::Polyhedron(stdx::ArraySlice<stdx::ArraySlice<Vector3>> Faces, std::shared_ptr<ISkin> Skin)
{
    this->setSkin(Skin);
    std::vector<Vector3> pts;
    stdx::ArraySlice<Face> fcs(Faces.GetLength());
    int i = Faces.GetLength();
    int j = 0;
    int k = fcs.GetLength();
    while (j < i && j < k)
    {
        stdx::ArraySlice<int> indices(Faces[j].GetLength());
        int num = Faces[j].GetLength();
        int num0 = 0;
        int num1 = indices.GetLength();
        while (num0 < num && num0 < num1)
        {
            indices[num0] = (int)pts.size();
            pts.push_back(Faces[j][num0]);
            ++num0;
        }
        fcs[j] = Face(indices);
        ++j;
    }
    this->setFaces(fcs);
    this->setPoints((stdx::ArraySlice<Vector3>)pts);
}

/// \brief Creates a new polyhedron from an array of points and an
/// array of faces. This polyhedron will have its outline
/// stroked, rather than being filled completely.
Polyhedron::Polyhedron(stdx::ArraySlice<Vector3> Points, stdx::ArraySlice<Face> Faces, std::shared_ptr<ISkin> Skin)
{
    this->setPoints(Points);
    this->setFaces(Faces);
    this->setSkin(Skin);
}

bool Polyhedron::Contains(std::vector<Face> Faces, Face Value) const
{
    for (auto& item : Faces)
        if (item.GetIntersectionSize(Value) == Value.Indices.GetLength())
            return true;

    return false;
}

stdx::ArraySlice<Vector3> Polyhedron::CreateDualFace(int PointIndex, Vector3 Center) const
{
    auto pts = this->getPoints();
    auto adjFaces = this->GetAdjacentFaces(PointIndex);
    std::vector<Vector3> results;
    for (auto& face : adjFaces)
        results.push_back(face.GetCenter(pts));
    return this->Reorient(results, Center);
}

Face Polyhedron::GetAdjacentFace(int PointIndex) const
{
    for (auto& item : this->getFaces())
        if (item.Contains(PointIndex))
            return item;

    return Face();
}

std::vector<Face> Polyhedron::GetAdjacentFaces(int PointIndex) const
{
    std::vector<Face> results;
    auto face = this->GetAdjacentFace(PointIndex);
    results.push_back(face);
    bool changed;
    do
    {
        changed = false;
        for (auto& item : this->getFaces())
            if (item.Contains(PointIndex) && !this->Contains(results, item))
            {
                if (item.GetIntersectionSize(face) > 1)
                {
                    changed = true;
                    face = item;
                    results.push_back(face);
                }
            }
    } while (changed);
    return results;
}

std::vector<int> Polyhedron::GetSharedEdgePoints(int PointIndex, Face Current, Face Previous) const
{
    std::vector<int> results;
    for (int i = 0; i < Current.Indices.GetLength(); ++i)
        if (PointIndex == Current.Indices[i])
        {
            int index = Current.Indices[(i + 1) % Current.Indices.GetLength()];
            if (!Previous.Contains(index))
                results.push_back(Current.Indices[(i + 1) % Current.Indices.GetLength()]);

        }
    return results;
}

std::shared_ptr<Polyhedron> Polyhedron::MakeDual() const
{
    auto pts = this->getPoints();
    auto center = this->getCenter();
    stdx::ArraySlice<stdx::ArraySlice<Vector3>> dualFaces(pts.GetLength());
    for (int i = 0; i < pts.GetLength(); ++i)
        dualFaces[i] = this->CreateDualFace(i, center);
    return Polyhedron(dualFaces, this->getSkin()).Optimize();
}

std::shared_ptr<IMesh> Polyhedron::MakeFractal(double ScaleFactor, int IterationCount) const
{
    auto fracs = this->MakeFractalMeshes(stdx::ArraySlice<std::shared_ptr<IMesh>>({
                                                                                      std::make_shared<Polyhedron>(this->getPoints(), 
                                                                                                                   this->getFaces(), 
                                                                                                                   this->getSkin())
                                                                                  }), 
                                         this->getPoints().GetLength(), 
                                         ScaleFactor, IterationCount);
    return std::make_shared<CompositeMesh>(fracs);
}

stdx::ArraySlice<std::shared_ptr<IMesh>> Polyhedron::MakeFractalMeshes(double ScaleFactor) const
{
    auto center = this->getCenter();
    auto pts = this->getPoints();
    stdx::ArraySlice<std::shared_ptr<IMesh>> meshes(pts.GetLength());
    auto scaleTransform = std::make_shared<ScaleTransformation3D>(Vector3(1.0 / ScaleFactor));
    for (int i = 0; i < meshes.GetLength(); ++i)
    {
        auto offset = pts[i] - scaleTransform->Transform(pts[i]);
        auto translTransform = std::make_shared<TranslateTransformation3D>(offset);
        auto fullTransform = std::shared_ptr<CompositeTransformation<Vector3>>(new CompositeTransformation<Vector3>(scaleTransform, 
                                                                                                                    translTransform));
        meshes[i] = this->Transform(fullTransform);
    }
    return meshes;
}

stdx::ArraySlice<std::shared_ptr<IMesh>> Polyhedron::MakeFractalMeshes(stdx::ArraySlice<std::shared_ptr<IMesh>> Meshes, int PointCount, double ScaleFactor) const
{
    stdx::ArraySlice<std::shared_ptr<IMesh>> results(Meshes.GetLength() * PointCount);
    for (int i = 0; i < Meshes.GetLength(); ++i)
    {
        auto fractals = std::dynamic_pointer_cast<Polyhedron>(Meshes[i])->MakeFractalMeshes(ScaleFactor);
        for (int j = 0; j < PointCount; ++j)
            results[i * PointCount + j] = fractals[j];
    }
    return results;
}

stdx::ArraySlice<std::shared_ptr<IMesh>> Polyhedron::MakeFractalMeshes(stdx::ArraySlice<std::shared_ptr<IMesh>> Meshes, int PointCount, double ScaleFactor, int IterationCount) const
{
    if (IterationCount <= 0)
        return Meshes;
    else
        return this->MakeFractalMeshes(this->MakeFractalMeshes(Meshes, PointCount, ScaleFactor), 
                                       PointCount, ScaleFactor, 
                                       IterationCount - 1);

}

/// \brief Creates an "optimized" polyhedron: a polyhedron without
/// duplicate points.
std::shared_ptr<Polyhedron> Polyhedron::Optimize() const
{
    auto pts = this->getPoints();
    auto fcs = this->getFaces();
    std::vector<Vector3> newPts;
    stdx::ArraySlice<Face> newFcs(fcs.GetLength());
    std::unordered_map<Vector3, int> dict;
    int i = fcs.GetLength();
    int j = 0;
    int k = newFcs.GetLength();
    while (j < i && j < k)
    {
        stdx::ArraySlice<int> newIndices(fcs[j].Indices.GetLength());
        auto arr = fcs[j].Indices;
        int num = arr.GetLength();
        int num0 = 0;
        int num1 = newIndices.GetLength();
        while (num0 < num && num0 < num1)
        {
            auto pt = pts[arr[num0]];
            if ((int)dict.count(pt) == 0)
            {
                dict[pt] = (int)newPts.size();
                newPts.push_back(pt);
            }
            newIndices[num0] = dict[pt];
            ++num0;
        }
        newFcs[j] = Face(newIndices);
        ++j;
    }
    return std::make_shared<Polyhedron>((stdx::ArraySlice<Vector3>)newPts, 
                                        newFcs, this->getSkin());
}

/// \brief Projects the mesh on a two-dimensional canvas based on the
/// given projection.
std::shared_ptr<IShape> Polyhedron::Project(std::shared_ptr<IProjection> Projection) const
{
    int i;
    auto oldPoints = this->getPoints();
    stdx::ArraySlice<Vector2> projectedPoints(oldPoints.GetLength());
    for (i = 0; i < projectedPoints.GetLength(); ++i)
        projectedPoints[i] = Projection->Project(oldPoints[i]);
    auto polyFaces = this->getFaces();
    stdx::ArraySlice<std::shared_ptr<IShape>> polygons(polyFaces.GetLength());
    for (i = 0; i < polyFaces.GetLength(); ++i)
    {
        auto indices = polyFaces[i].Indices;
        stdx::ArraySlice<Vector2> polyPts(indices.GetLength() + 1);
        stdx::ArraySlice<Vector3> originalPts(indices.GetLength() + 1);
        for (int j = 0; j < indices.GetLength(); ++j)
        {
            polyPts[j] = projectedPoints[indices[j]];
            originalPts[j] = oldPoints[indices[j]];
        }
        polyPts[indices.GetLength()] = polyPts[0];
        polygons[i] = std::shared_ptr<TexturedShape>(new TexturedShape(std::make_shared<MultiLine>(polyPts, true), 
                                                                       this->getSkin()->CreateTexture(originalPts, polyPts)));
    }
    return std::make_shared<CompositeShape>(polygons);
}

stdx::ArraySlice<Vector3> Polyhedron::Reorient(std::vector<Vector3> FacePoints, Vector3 Center) const
{
    if (FacePoints.size() > 1)
    {
        auto firstPt = FacePoints[0];
        auto secondPt = FacePoints[1];
        auto offset = firstPt - Center;
        auto normal = firstPt.Cross(secondPt);
        if (normal.Dot(offset) < 0.0)
            std::reverse(FacePoints.begin(), FacePoints.end());

    }
    return (stdx::ArraySlice<Vector3>)FacePoints;
}

/// \brief Converts this polyhedron to an equivalent wireframe.
std::shared_ptr<Wireframe> Polyhedron::ToWireframe() const
{
    auto pts = this->getPoints();
    auto polyFaces = this->getFaces();
    stdx::ArraySlice<Face> wireframeFaces(polyFaces.GetLength());
    for (int i = 0; i < polyFaces.GetLength(); ++i)
    {
        auto indices = polyFaces[i].Indices;
        stdx::ArraySlice<int> wireframeIndices(indices.GetLength() + 1);
        for (int j = 0; j < indices.GetLength(); ++j)
            wireframeIndices[j] = indices[j];
        wireframeIndices[indices.GetLength()] = indices[0];
        wireframeFaces[i] = Face(wireframeIndices);
    }
    return Wireframe(pts, wireframeFaces, this->getSkin()).OptimizeLines();
}

/// \brief Transforms the mesh with the given transformation.
std::shared_ptr<IMesh> Polyhedron::Transform(std::shared_ptr<ITransformation<Vector3>> Transformation) const
{
    auto pts = this->getPoints();
    stdx::ArraySlice<Vector3> transformed(pts.GetLength());
    for (int i = 0; i < transformed.GetLength(); ++i)
        transformed[i] = Transformation->Transform(pts[i]);
    return std::make_shared<Polyhedron>(transformed, this->getFaces(), 
                                        this->getSkin());
}

std::shared_ptr<Polyhedron> Polyhedron::Truncate(double SubdivisionFactor) const
{
    auto fcs = this->getFaces();
    std::vector<stdx::ArraySlice<Vector3>> newFcs;
    auto center = this->getCenter();
    for (auto& item : fcs)
        newFcs.push_back(this->TruncateFace(item, SubdivisionFactor));
    for (int i = 0; i < this->getPoints().GetLength(); ++i)
        newFcs.push_back(this->Reorient(this->TruncatePoint(i, SubdivisionFactor), 
                                        center));
    return Polyhedron((stdx::ArraySlice<stdx::ArraySlice<Vector3>>)newFcs, 
                      this->getSkin()).Optimize();
}

stdx::ArraySlice<Vector3> Polyhedron::TruncateFace(Face Value, double SubdivisionFactor) const
{
    auto pts = this->getPoints();
    stdx::ArraySlice<Vector3> results(Value.Indices.GetLength() * 2);
    for (int i = 0; i < Value.Indices.GetLength(); ++i)
    {
        auto firstPt = pts[Value.Indices[i]];
        auto secondPt = pts[Value.Indices[(i + 1) % Value.Indices.GetLength()]];
        results[i * 2] = firstPt * (1.0 - SubdivisionFactor) + 
                         secondPt * SubdivisionFactor;
        results[i * 2 + 1] = firstPt * SubdivisionFactor + 
                             secondPt * (1.0 - SubdivisionFactor);
    }
    return results;
}

std::vector<Vector3> Polyhedron::TruncatePoint(int PointIndex, double SubdivisionFactor) const
{
    auto pts = this->getPoints();
    auto adjFaces = this->GetAdjacentFaces(PointIndex);
    std::vector<Vector3> results;
    Face previousFace(stdx::ArraySlice<int>(0));
    for (auto& item : adjFaces)
        for (auto& pt : this->GetSharedEdgePoints(PointIndex, item, previousFace))
            results.push_back(pts[PointIndex] * (1.0 - SubdivisionFactor) + 
                              pts[pt] * SubdivisionFactor);
    return results;
}

/// \brief Gets the polyhedron's center.
Vector3 Polyhedron::getCenter() const
{
    Vector3 result;
    auto pts = this->getPoints();
    for (auto& item : pts)
        result += item / (double)pts.GetLength();
    return result;
}

/// \brief Sets the polyhedron's faces.
void Polyhedron::setFaces(stdx::ArraySlice<Face> value)
{
    this->Faces_value = value;
}

/// \brief Gets the polyhedron's faces.
stdx::ArraySlice<Face> Polyhedron::getFaces() const
{
    return this->Faces_value;
}

/// \brief Gets all points in the polyhedron.
stdx::ArraySlice<Vector3> Polyhedron::getPoints() const
{
    return this->Points_value;
}

/// \brief Sets all points in the polyhedron.
void Polyhedron::setPoints(stdx::ArraySlice<Vector3> value)
{
    this->Points_value = value;
}

/// \brief Sets the polyhedron's skin.
void Polyhedron::setSkin(std::shared_ptr<ISkin> value)
{
    this->Skin_value = value;
}

/// \brief Gets the polyhedron's skin.
std::shared_ptr<ISkin> Polyhedron::getSkin() const
{
    return this->Skin_value;
}