#pragma once
#include <memory>
#include "ISegment.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Describes a partial segment: a segment that has not been
    /// closed yet.
    struct IPartialSegment
    {
        /// \brief Closes the partial segment to form a curve segment.
        virtual std::shared_ptr<ISegment> Close(Vector2 EndPoint) const = 0;

        /// \brief Gets the partial segment's start point.
        virtual Vector2 getStartPoint() const = 0;
    };
}