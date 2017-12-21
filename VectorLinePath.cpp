#include "VectorLinePath.h"

#include <memory>
#include "ArraySlice.h"
#include "CommandBlock.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IPartialSegment.h"
#include "IRenderTarget.h"
#include "ISegment.h"
#include "IShape.h"
#include "IsInstance.h"
#include "ITransformation.h"
#include "IVectorInstructionStream.h"
#include "IVectorSegment.h"
#include "LinePathBase.h"
#include "LineSegment.h"
#include "RenderVectorPathCommand.h"
#include "Vector2.h"

using namespace Engine;

/// \brief Creates a new vector line path from the given array of
/// path segments.
VectorLinePath::VectorLinePath(stdx::ArraySlice<std::shared_ptr<ISegment>> Segments)
{
    this->setSegments(Segments);
}

/// \brief Creates a new vector line path from the given segment
/// array and a boolean that tells whether the path should be
/// filled or have its outline stroked.
VectorLinePath::VectorLinePath(stdx::ArraySlice<std::shared_ptr<ISegment>> Segments, bool FillPath)
{
    this->setSegments(Segments);
    this->setFillPath(FillPath);
}

/// \brief Creates a new vector line path from the given partial
/// segment array and end point.
VectorLinePath::VectorLinePath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint)
{
    this->setSegments(this->CloseSegments(Segs, EndPoint));
}

/// \brief Creates a new vector line path from the given partial
/// segment array and end point, as well as a boolean that
/// tells whether the path should be filled or have its outline
/// stroked.
VectorLinePath::VectorLinePath(stdx::ArraySlice<std::shared_ptr<IPartialSegment>> Segs, Vector2 EndPoint, bool FillPath)
{
    this->setFillPath(FillPath);
    this->setSegments(this->CloseSegments(Segs, EndPoint));
}

/// \brief Creates a render command for this shape.
std::shared_ptr<ICommand<std::shared_ptr<IRenderTarget>>> VectorLinePath::Render(std::shared_ptr<IBrush> Brush) const
{
    stdx::ArraySlice<std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>>> results(this->getSegments().GetLength());
    for (int i = 0; i < results.GetLength(); ++i)
        results[i] = this->WriteSegment(this->getSegments()[i]);
    auto instrs = std::make_shared<CommandBlock<std::shared_ptr<IVectorInstructionStream>>>(results);
    return std::shared_ptr<RenderVectorPathCommand>(new RenderVectorPathCommand(instrs, Brush, this->getFillPath()));
}

/// \brief Creates a new shape that corresponds to this shape after
/// the given transformation has been applied.
std::shared_ptr<IShape> VectorLinePath::Transform(std::shared_ptr<ITransformation<Vector2>> Transformation) const
{
    auto segs = this->getSegments();
    stdx::ArraySlice<std::shared_ptr<ISegment>> transformedSegs(segs.GetLength());
    for (int i = 0; i < transformedSegs.GetLength(); ++i)
        transformedSegs[i] = segs[i]->Transform(Transformation);
    return std::make_shared<VectorLinePath>(transformedSegs);
}

/// \brief Creates a command that writes a segment to a vector
/// instruction stream.
std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>> VectorLinePath::WriteSegment(std::shared_ptr<ISegment> Segment) const
{
    if (stdx::isinstance<IVectorSegment>(Segment))
        return std::dynamic_pointer_cast<IVectorSegment>(Segment)->Write();

    auto segs = this->ToLineSegments(Segment);
    stdx::ArraySlice<std::shared_ptr<ICommand<std::shared_ptr<IVectorInstructionStream>>>> commands(segs.GetLength());
    for (int i = 0; i < segs.GetLength(); ++i)
        commands[i] = segs[i].Write();
    return std::make_shared<CommandBlock<std::shared_ptr<IVectorInstructionStream>>>(commands);
}