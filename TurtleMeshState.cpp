#include "TurtleMeshState.h"

#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new turtle mesh state from the default settings.
TurtleMeshState::TurtleMeshState()
    : Position(), Direction(1.0, 0.0, 0.0), Left(0.0, 1.0, 0.0), Up(0.0, 0.0, 1.0)
{ }

/// \brief Creates a new turtle mesh state from the given arguments.
TurtleMeshState::TurtleMeshState(Vector3 Position, Vector3 Direction, Vector3 Left, Vector3 Up)
    : Position(Position), Direction(Direction), Left(Left), Up(Up)
{ }