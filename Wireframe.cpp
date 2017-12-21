#include "Wireframe.h"

#include <initializer_list>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "ArraySlice.h"
#include "ComplexMesh.h"
#include "CompositeMesh.h"
#include "CompositeShape.h"
#include "CompositeTransformation.h"
#include "Cylinder.h"
#include "Face.h"
#include "IMesh.h"
#include "IndexedLine.h"
#include "IProjection.h"
#include "IShape.h"
#include "ISkin.h"
#include "ITransformation.h"
#include "MatrixHelpers.h"
#include "MatrixTransformation.h"
#include "ProjectedMultiLine.h"
#include "ScaleTransformation3D.h"
#include "Sphere.h"
#include "TexturedShape.h"
#include "TranslateTransformation3D.h"
#include "vector.hh"
#include "Vector2.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new wireframe mesh from the given points and
/// multi-lines.
Wireframe::Wireframe(stdx::ArraySlice<Vector3> Points, stdx::ArraySlice<Face> Lines, std::shared_ptr<ISkin> Skin)
{
    this->setPoints(Points);
    this->setLines(Lines);
    this->setSkin(Skin);
}

std::shared_ptr<IMesh> Wireframe::MakeThickWireframe(double SphereRadius, int n, int m) const
{
    std::shared_ptr<CompositeTransformation<Vector3>> sphereTransform;
    auto points = this->getPoints();
    auto indexLines = this->getLines();
    std::vector<std::shared_ptr<IMesh>> meshes;
    auto sphereScale = std::make_shared<ScaleTransformation3D>(Vector3(SphereRadius));
    for (auto& item : points)
    {
        auto translation = std::make_shared<TranslateTransformation3D>(item);
        sphereTransform = std::shared_ptr<CompositeTransformation<Vector3>>(new CompositeTransformation<Vector3>(sphereScale, translation));
        meshes.push_back(Sphere(m, this->getSkin()).Transform(sphereTransform));
    }
    for (int i = 0; i < indexLines.GetLength(); ++i)
    {
        auto indices = indexLines[i].Indices;
        for (int j = 1; j < indices.GetLength(); ++j)
        {
            auto prevPt = points[indices[j - 1]];
            auto pt = points[indices[j]];
            auto offset = pt - prevPt;
            auto polar = offset.ToPolar();
            double height = polar.X / SphereRadius;
            auto rotPhi = Engine::RotateY(polar.Z);
            auto rotTheta = Engine::RotateZ(polar.Y);
            auto trans = Engine::Translate(prevPt);
            auto matrixTrans = std::make_shared<MatrixTransformation>(rotPhi * rotTheta * trans);
            sphereTransform = std::shared_ptr<CompositeTransformation<Vector3>>(new CompositeTransformation<Vector3>(sphereScale, matrixTrans));
            meshes.push_back(Cylinder(height, n, this->getSkin(), false).Transform(sphereTransform));
        }
    }
    return std::make_shared<CompositeMesh>((stdx::ArraySlice<std::shared_ptr<IMesh>>)meshes);
}

/// \brief Creates an "optimized" wireframe: a wireframe without
/// duplicate points or lines.
std::shared_ptr<Wireframe> Wireframe::Optimize() const
{
    auto pts = this->getPoints();
    auto fcs = this->getLines();
    std::vector<Vector3> newPts;
    std::unordered_set<Face> uniqueLines;
    std::unordered_map<Vector3, int> dict;
    for (auto& face : fcs)
    {
        auto indices = face.Indices;
        for (int i = 1; i < indices.GetLength(); ++i)
        {
            int prevIndex = indices[i - 1];
            auto prevPt = pts[prevIndex];
            if ((int)dict.count(prevPt) == 0)
            {
                prevIndex = (int)newPts.size();
                dict[prevPt] = prevIndex;
                newPts.push_back(prevPt);
            }
            else
            {
                prevIndex = dict[prevPt];
            }
            int ptIndex = indices[i];
            auto pt = pts[ptIndex];
            if ((int)dict.count(pt) == 0)
            {
                ptIndex = (int)newPts.size();
                dict[pt] = ptIndex;
                newPts.push_back(pt);
            }
            else
            {
                ptIndex = dict[pt];
            }
            Face newFace(stdx::ArraySlice<int>({ prevIndex, ptIndex }));
            uniqueLines.insert(newFace);
        }
    }
    auto newLines = (stdx::ArraySlice<Face>)std::vector<Face>(uniqueLines.begin(), uniqueLines.end());
    return std::make_shared<Wireframe>((stdx::ArraySlice<Vector3>)newPts, 
                                       newLines, this->getSkin());
}

/// \brief Creates an "optimized" wireframe: a wireframe without
/// duplicate lines.
std::shared_ptr<Wireframe> Wireframe::OptimizeLines() const
{
    int i;
    auto fcs = this->getLines();
    std::unordered_set<IndexedLine> uniqueLines;
    for (auto& face : fcs)
    {
        auto indices = face.Indices;
        for (i = 1; i < indices.GetLength(); ++i)
        {
            IndexedLine newFace(indices[i - 1], indices[i]);
            uniqueLines.insert(newFace);
        }
    }
    stdx::ArraySlice<Face> newLines(uniqueLines.size());
    i = 0;
    for (auto& item : uniqueLines)
    {
        newLines[i] = item.ToFace();
        ++i;
    }
    return std::make_shared<Wireframe>(this->getPoints(), newLines, 
                                       this->getSkin());
}

/// \brief Projects the mesh on a two-dimensional canvas based on the
/// given projection.
std::shared_ptr<IShape> Wireframe::Project(std::shared_ptr<IProjection> Projection) const
{
    int i;
    auto oldPoints = this->getPoints();
    stdx::ArraySlice<Vector2> projectedPoints(oldPoints.GetLength());
    for (i = 0; i < projectedPoints.GetLength(); ++i)
        projectedPoints[i] = Projection->Project(oldPoints[i]);
    auto indexLines = this->getLines();
    stdx::ArraySlice<std::shared_ptr<IShape>> lines(indexLines.GetLength());
    for (i = 0; i < lines.GetLength(); ++i)
    {
        auto indices = indexLines[i].Indices;
        stdx::ArraySlice<Vector2> linePts(indices.GetLength());
        stdx::ArraySlice<Vector3> originalPts(indices.GetLength());
        for (int j = 0; j < indices.GetLength(); ++j)
        {
            linePts[j] = projectedPoints[indices[j]];
            originalPts[j] = oldPoints[indices[j]];
        }
        lines[i] = std::shared_ptr<TexturedShape>(new TexturedShape(std::make_shared<ProjectedMultiLine>(linePts, originalPts, 
                                                                                                         false), 
                                                                    this->getSkin()->CreateTexture(originalPts, linePts)));
    }
    return std::make_shared<CompositeShape>(lines);
}

/// \brief Transforms the mesh with the given transformation.
std::shared_ptr<IMesh> Wireframe::Transform(std::shared_ptr<ITransformation<Vector3>> Transformation) const
{
    auto pts = this->getPoints();
    stdx::ArraySlice<Vector3> transformed(pts.GetLength());
    for (int i = 0; i < transformed.GetLength(); ++i)
        transformed[i] = Transformation->Transform(pts[i]);
    return std::make_shared<Wireframe>(transformed, this->getLines(), 
                                       this->getSkin());
}

/// \brief Sets the wireframe's multi-lines, which are stored as
/// faces.
void Wireframe::setLines(stdx::ArraySlice<Face> value)
{
    this->Lines_value = value;
}

/// \brief Gets the wireframe's multi-lines, which are stored as
/// faces.
stdx::ArraySlice<Face> Wireframe::getLines() const
{
    return this->Lines_value;
}

/// \brief Sets the wireframe's points.
void Wireframe::setPoints(stdx::ArraySlice<Vector3> value)
{
    this->Points_value = value;
}

/// \brief Gets the wireframe's points.
stdx::ArraySlice<Vector3> Wireframe::getPoints() const
{
    return this->Points_value;
}

/// \brief Sets the wireframe's skin.
void Wireframe::setSkin(std::shared_ptr<ISkin> value)
{
    this->Skin_value = value;
}

/// \brief Gets the wireframe's skin.
std::shared_ptr<ISkin> Wireframe::getSkin() const
{
    return this->Skin_value;
}