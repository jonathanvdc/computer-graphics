#pragma once
#include <cmath>
#include <memory>
#include "IBitmap.h"
#include "IBitmapSegment.h"
#include "IBrush.h"
#include "ICommand.h"
#include "ISegment.h"
#include "ITransformation.h"
#include "IVectorInstructionStream.h"
#include "IVectorSegment.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Implements a line segment.
    class LineSegment : public virtual IBitmapSegment, public virtual IVectorSegment
    {
    public:
        LineSegment();
        LineSegment(Vector2 StartPoint, Vector2 EndPoint);

        /// \brief Draws the segment on the target bitmap with the given
        /// brush.
        void Draw(std::shared_ptr<IBitmap> TargetBitmap, std::shared_ptr<IBrush> Brush) override;

        /// \brief Gets the line segment's end position.
        Vector2 getEndPoint() const;

        /// \brief Gets the segment's position at the given offset (where
        /// offset is a value between 0.0 and 1.0).
        Vector2 GetPosition(double Offset) const override;

        /// \brief Gets the line segment's start position.
        Vector2 getStartPoint() const;

        /// \brief Creates a new segment that corresponds to this segment
        /// after the given transformation has been applied.
        std::shared_ptr<ISegment> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;

        /// \brief Gets a command that writes the vector segment's data to a
        /// vector instruction stream.
        std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> Write() override;

        /// \brief Gets the segment's length.
        double getLength() const override;
    private:
        /// \brief Sets the line segment's end position.
        void setEndPoint(Vector2 value);

        /// \brief Sets the line segment's start position.
        void setStartPoint(Vector2 value);

        Vector2 EndPoint_value;
        Vector2 StartPoint_value;
    };
}