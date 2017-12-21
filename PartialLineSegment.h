#pragma once
#include <memory>
#include "IPartialSegment.h"
#include "ISegment.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Implements a partial line segment.
    class PartialLineSegment : public virtual IPartialSegment
    {
    public:
        PartialLineSegment();
        PartialLineSegment(Vector2 StartPoint);

        /// \brief Closes the partial segment to form a curve segment.
        std::shared_ptr<ISegment> Close(Vector2 EndPoint) const override;

        /// \brief Gets the line segment's start position.
        Vector2 getStartPoint() const override;
    private:
        /// \brief Sets the line segment's start position.
        void setStartPoint(Vector2 value);

        Vector2 StartPoint_value;
    };
}