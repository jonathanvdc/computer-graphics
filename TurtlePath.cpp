#include "TurtlePath.h"

#include <cmath>
#include <memory>
#include <vector>
#include "ArraySlice.h"
#include "CompositeShape.h"
#include "IShape.h"
#include "MultiLine.h"
#include "TurtleState.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a new turtle path instance.
TurtlePath::TurtlePath()
    : penDown(false)
{ }

/// \brief Creates a turtle path from the given starting position and
/// angle.
TurtlePath::TurtlePath(Vector2 Position, double Angle)
    : penDown(false), state(Position, Angle)
{ }

/// \brief "Flushes" the turtle path's points, turning them into
/// shapes.
void TurtlePath::FlushPoints()
{
    if ((int)this->points.size() > 1)
    {
        stdx::ArraySlice<Vector2> vals(this->points.size());
        for (int i = 0; i < vals.GetLength(); ++i)
            vals[i] = this->points.at(i);
        this->shapes.push_back(std::make_shared<MultiLine>(vals));
    }
    this->points = std::vector<Vector2>();
}

/// \brief Moves the "turtle" forward by the given amount.
void TurtlePath::MoveForward(double Distance)
{
    auto newPos = this->state.Position + 
                  Vector2(Distance * std::cos(this->state.Angle), 
                          Distance * std::sin(this->state.Angle));
    this->state = TurtleState(newPos, this->state.Angle);
    if (this->penDown)
        this->points.push_back(newPos);

}

/// \brief Pops and restores the turtle state at the top of the
/// memento stack.
void TurtlePath::PopState()
{
    this->StopDrawing();
    this->state = this->mementos.at((int)this->mementos.size() - 1);
    this->mementos.pop_back();
}

/// \brief Saves the turtle mesh's current state and pushes it onto
/// the memento stack.
void TurtlePath::PushState()
{
    this->mementos.push_back(this->state);
}

/// \brief Configures the turtle path to start drawing lines between
/// successive positions.
void TurtlePath::StartDrawing()
{
    if (!this->penDown)
    {
        this->penDown = true;
        this->points.push_back(this->state.Position);
    }
}

/// \brief Configures the turtle path to stop drawing lines.
void TurtlePath::StopDrawing()
{
    if (this->penDown)
    {
        this->penDown = false;
        this->FlushPoints();
    }
}

/// \brief Converts the turtle path into a drawable shape.
std::shared_ptr<IShape> TurtlePath::ToShape()
{
    auto oldShapes = this->shapes;
    auto oldPoints = this->points;
    this->FlushPoints();
    auto shapeArr = (stdx::ArraySlice<std::shared_ptr<IShape>>)this->shapes;
    this->shapes = oldShapes;
    this->points = oldPoints;
    return std::make_shared<CompositeShape>(shapeArr);
}

/// \brief Turns the "turtle" left by the specified angle.
void TurtlePath::TurnLeft(double Angle)
{
    this->state = TurtleState(this->state.Position, this->state.Angle + Angle);
}

/// \brief Turns the "turtle" right by the given angle.
void TurtlePath::TurnRight(double Angle)
{
    this->TurnLeft(-Angle);
}