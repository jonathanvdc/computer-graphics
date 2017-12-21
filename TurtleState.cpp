#include "TurtleState.h"

#include "Vector2.h"

using namespace Engine;

/// \brief Creates a turtle path state at the origin, with an angle
/// of zero.
TurtleState::TurtleState()
    : Position(), Angle(0.0)
{ }

/// \brief Creates a turtle path state from the given position and
/// angle.
TurtleState::TurtleState(Vector2 Position, double Angle)
    : Position(Position), Angle(Angle)
{ }