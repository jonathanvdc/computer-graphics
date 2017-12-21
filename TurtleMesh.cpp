#include "TurtleMesh.h"

#include <cmath>
#include <memory>
#include <vector>
#include "ArraySlice.h"
#include "Face.h"
#include "IMesh.h"
#include "ISkin.h"
#include "TurtleMeshState.h"
#include "Vector3.h"
#include "Wireframe.h"

using namespace Engine;

/// \brief Creates an empty turtle mesh.
TurtleMesh::TurtleMesh()
    : penDown(false), state()
{ }

bool TurtleMesh::AreAlmostEqual(Vector3 First, Vector3 Second) const
{
    auto dirDiff = First - Second;
    return dirDiff.getLengthSquared() < 0.0001;
}

/// \brief "Flushes" the turtle mesh's points into the face points
/// vector, and draws a line between them, provided the current
/// state's position is not equal to the last point in the
/// point list.
void TurtleMesh::FlushPoints()
{
    if (this->IsNewPoint(this->state.Position))
        this->FlushPointsImpl();

}

/// \brief "Flushes" the turtle mesh's points into the face points
/// vector.
void TurtleMesh::FlushPointsImpl()
{
    if ((int)this->points.size() > 1)
        this->flushedPoints.push_back(this->points);

    this->points = std::vector<Vector3>();
}

Vector3 TurtleMesh::GetPreviousDirection() const
{
    auto ultimatePos = this->points.at(this->points.size() - 1);
    auto penultimatePos = this->points.at(this->points.size() - 2);
    auto offset = ultimatePos - penultimatePos;
    return offset.Normalize();
}

/// \brief Checks if the given point is not equal to the last point
/// in the points list.
bool TurtleMesh::IsNewPoint(Vector3 Point) const
{
    return this->points.empty() || !this->AreAlmostEqual(this->points[this->points.size() - 1], 
                                                         Point);
}

bool TurtleMesh::MaintainsDirection() const
{
    return this->AreAlmostEqual(this->GetPreviousDirection(), 
                                this->state.Direction);
}

/// \brief Moves the turtle forward.
void TurtleMesh::MoveForward(double Distance)
{
    auto oldPos = this->state.Position;
    auto newPos = this->state.Position + this->state.Direction;
    this->state = TurtleMeshState(newPos, this->state.Direction, 
                                  this->state.Left, this->state.Up);
    if (this->penDown)
    {
        if ((int)this->points.size() > 1 && this->MaintainsDirection())
            this->points.pop_back();

        this->RecordPosition();
    }
}

/// \brief Pitches the "turtle" down by the given angle.
void TurtleMesh::PitchDown(double Angle)
{
    this->PitchUp(-Angle);
}

/// \brief Pitches the "turtle" up by the given angle.
void TurtleMesh::PitchUp(double Angle)
{
    double cosd = std::cos(Angle);
    double sind = std::sin(Angle);
    this->state = TurtleMeshState(this->state.Position, 
                                  this->state.Direction * cosd + this->state.Up * sind, 
                                  this->state.Left, 
                                  this->state.Up * cosd - this->state.Direction * sind);
}

/// \brief Pops and restores state on the top of the memento stack.
void TurtleMesh::PopState()
{
    this->StopDrawing();
    this->state = this->mementos.at((int)this->mementos.size() - 1);
    this->mementos.pop_back();
}

/// \brief Saves and pushes the current state on the memento stack.
void TurtleMesh::PushState()
{
    this->mementos.push_back(this->state);
}

/// \brief Records the current state's position if it is is not equal
/// to the last point in the point list.
void TurtleMesh::RecordPosition()
{
    if (this->IsNewPoint(this->state.Position))
        this->points.push_back(this->state.Position);

}

/// \brief Reverses the turtle's direction.
void TurtleMesh::ReverseDirection()
{
    this->state = TurtleMeshState(this->state.Position, 
                                  this->state.Direction * -1.0, 
                                  this->state.Left * -1.0, this->state.Up);
}

/// \brief Rolls the "turtle" left by the given angle.
void TurtleMesh::RollLeft(double Angle)
{
    double cosd = std::cos(Angle);
    double sind = std::sin(Angle);
    this->state = TurtleMeshState(this->state.Position, 
                                  this->state.Direction, 
                                  this->state.Left * cosd - this->state.Up * sind, 
                                  this->state.Up * cosd + this->state.Left * sind);
}

/// \brief Rolls the "turtle" right by the given angle.
void TurtleMesh::RollRight(double Angle)
{
    this->RollLeft(-Angle);
}

/// \brief Configures the turtle mesh to draw lines between
/// successive positions.
void TurtleMesh::StartDrawing()
{
    if (!this->penDown)
    {
        this->penDown = true;
        this->UnflushPoints();
        this->FlushPoints();
        this->RecordPosition();
    }
}

/// \brief Configures the turtle mesh to stop drawing lines.
void TurtleMesh::StopDrawing()
{
    if (this->penDown)
        this->penDown = false;

}

/// \brief Gets a mesh representation of this turtle wireframe.
std::shared_ptr<IMesh> TurtleMesh::ToMesh(std::shared_ptr<ISkin> Skin)
{
    auto oldFlushedPoints = this->flushedPoints;
    auto oldPoints = this->points;
    this->FlushPointsImpl();
    std::vector<Face> faces;
    std::vector<Vector3> facePts;
    for (auto& item : this->flushedPoints)
    {
        stdx::ArraySlice<int> indices(item.size());
        for (int i = 0; i < indices.GetLength(); ++i)
        {
            indices[i] = (int)facePts.size();
            facePts.push_back(item.at(i));
        }
        faces.push_back(Face(indices));
    }
    auto pts = (stdx::ArraySlice<Vector3>)facePts;
    auto lines = (stdx::ArraySlice<Face>)faces;
    this->flushedPoints = oldFlushedPoints;
    this->points = oldPoints;
    return Wireframe(pts, lines, Skin).Optimize();
}

/// \brief Turns the "turtle" left by the given angle.
void TurtleMesh::TurnLeft(double Angle)
{
    double cosd = std::cos(Angle);
    double sind = std::sin(Angle);
    this->state = TurtleMeshState(this->state.Position, 
                                  this->state.Direction * cosd + this->state.Left * sind, 
                                  this->state.Left * cosd - this->state.Direction * sind, 
                                  this->state.Up);
}

/// \brief Turns the "turtle" right by the given angle.
void TurtleMesh::TurnRight(double Angle)
{
    this->TurnLeft(-Angle);
}

void TurtleMesh::UnflushPoints()
{
    if (this->points.empty() && !this->flushedPoints.empty())
    {
        this->points = this->flushedPoints.back();
        this->flushedPoints.pop_back();
    }
}