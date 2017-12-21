#pragma once
#include <memory>
#include "ITransformation.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Provides common functionality for curve segments.
    struct ISegment
    {
        /// \brief Gets the segment's position at the given offset (where
        /// offset is a value between 0.0 and 1.0).
        virtual Vector2 GetPosition(double Offset) const = 0;

        /// \brief Creates a new segment that corresponds to this segment
        /// after the given transformation has been applied.
        virtual std::shared_ptr<ISegment> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const = 0;

        /// \brief Gets the segment's length.
        virtual double getLength() const = 0;
    };
}