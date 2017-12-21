#pragma once
#include <memory>
#include "ArraySlice.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IPartialSegment.h"
#include "IRenderTarget.h"
#include "ISegment.h"
#include "IShape.h"
#include "ITransformation.h"
#include "IVectorInstructionStream.h"
#include "LinePathBase.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief Defines a vector line path: a path that renders to a
    /// vector render target by approximating its segments with
    /// line segments.
    class VectorLinePath : public LinePathBase
    {
    public:
        /// \brief Creates a new vector line path from the given array of
        /// path segments.
        VectorLinePath(stdx::ArraySlice<std::shared_ptr<ISegment>> Segments);
        /// \brief Creates a new vector line path from the given segment
        /// array and a boolean that tells whether the path should be
        /// filled or have its outline stroked.
        VectorLinePath(stdx::ArraySlice<std::shared_ptr<ISegment>> Segments, bool FillPath);
        /// \brief Creates a new vector line path from the given partial
        /// segment array and end point.
        VectorLinePath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint);
        /// \brief Creates a new vector line path from the given partial
        /// segment array and end point, as well as a boolean that
        /// tells whether the path should be filled or have its outline
        /// stroked.
        VectorLinePath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint, bool FillPath);

        /// \brief Creates a render command for this shape.
        std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> Render(std::shared_ptr<IBrush> Brush) const override;

        /// \brief Creates a new shape that corresponds to this shape after
        /// the given transformation has been applied.
        std::shared_ptr<IShape> Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const override;
    private:
        /// \brief Creates a command that writes a segment to a vector
        /// instruction stream.
        std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> WriteSegment(std::shared_ptr<ISegment> Segment) const;
    };
}