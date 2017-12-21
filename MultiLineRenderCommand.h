#pragma once
#include <memory>
#include "ArraySlice.h"
#include "IBrush.h"
#include "ICommand.h"
#include "IRenderTarget.h"
#include "Vector2.h"

namespace Engine
{
    /// \brief A render command for a multi-line.
    class MultiLineRenderCommand : public virtual ICommand<std::shared_ptr<IRenderTarget>>
    {
    public:
        MultiLineRenderCommand(stdx::ArraySlice<Vector2> Points, std::shared_ptr<IBrush> Brush, bool FillPath);

        /// \brief Executes the command on the given target.
        virtual void Execute(std::shared_ptr<IRenderTarget> Target) override;

        /// \brief Gets the brush to render the multi-line with.
        std::shared_ptr<IBrush> getBrush() const;

        /// \brief Gets a boolean flag that indicates whether the multi-line
        /// is to be filled as a polygon or merely have its outline
        /// drawn.
        bool getFillPath() const;

        /// \brief Gets the multi-line's points.
        stdx::ArraySlice<Vector2> getPoints() const;
    protected:
        MultiLineRenderCommand();

        /// \brief Sets the brush to render the multi-line with.
        void setBrush(std::shared_ptr<IBrush> value);

        /// \brief Sets a boolean flag that indicates whether the multi-line
        /// is to be filled as a polygon or merely have its outline
        /// drawn.
        void setFillPath(bool value);

        /// \brief Sets the multi-line's points.
        void setPoints(stdx::ArraySlice<Vector2> value);
    private:
        std::shared_ptr<IBrush> Brush_value;
        bool FillPath_value;
        stdx::ArraySlice<Vector2> Points_value;
    };
}