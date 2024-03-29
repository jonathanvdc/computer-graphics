#pragma once
#include <memory>
#include <vector>
#include "IMesh.h"
#include "ISkin.h"
#include "TurtleMeshState.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Represents a turtle mesh: a wireframe that is procedurally
    /// generated by moving a point ("turtle") around and drawing
    /// lines between successive positions.
    class TurtleMesh
    {
    public:
        /// \brief Creates an empty turtle mesh.
        TurtleMesh();

        /// \brief Moves the turtle forward.
        void MoveForward(double Distance);

        /// \brief Pitches the "turtle" down by the given angle.
        void PitchDown(double Angle);

        /// \brief Pitches the "turtle" up by the given angle.
        void PitchUp(double Angle);

        /// \brief Pops and restores state on the top of the memento stack.
        void PopState();

        /// \brief Saves and pushes the current state on the memento stack.
        void PushState();

        /// \brief Reverses the turtle's direction.
        void ReverseDirection();

        /// \brief Rolls the "turtle" left by the given angle.
        void RollLeft(double Angle);

        /// \brief Rolls the "turtle" right by the given angle.
        void RollRight(double Angle);

        /// \brief Configures the turtle mesh to draw lines between
        /// successive positions.
        void StartDrawing();

        /// \brief Configures the turtle mesh to stop drawing lines.
        void StopDrawing();

        /// \brief Gets a mesh representation of this turtle wireframe.
        std::shared_ptr<IMesh> ToMesh(std::shared_ptr<ISkin> Skin);

        /// \brief Turns the "turtle" left by the given angle.
        void TurnLeft(double Angle);

        /// \brief Turns the "turtle" right by the given angle.
        void TurnRight(double Angle);
    private:
        bool AreAlmostEqual(Vector3 First, Vector3 Second) const;

        /// \brief "Flushes" the turtle mesh's points into the face points
        /// vector, and draws a line between them, provided the current
        /// state's position is not equal to the last point in the
        /// point list.
        void FlushPoints();

        /// \brief "Flushes" the turtle mesh's points into the face points
        /// vector.
        void FlushPointsImpl();

        Vector3 GetPreviousDirection() const;

        /// \brief Checks if the given point is not equal to the last point
        /// in the points list.
        bool IsNewPoint(Vector3 Point) const;

        bool MaintainsDirection() const;

        /// \brief Records the current state's position if it is is not equal
        /// to the last point in the point list.
        void RecordPosition();

        void UnflushPoints();

        std::vector<std::vector<Vector3>> flushedPoints;
        std::vector<TurtleMeshState> mementos;
        bool penDown;
        std::vector<Vector3> points;
        TurtleMeshState state;
    };
}