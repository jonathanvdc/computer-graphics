#pragma once
#include <memory>
#include "IBrush.h"
#include "IVectorInstructionStream.h"

namespace Engine
{
    /// \brief Defines a mutable vector path.
    class VectorPathBase
    {
    public:
        VectorPathBase();

        /// \brief Gets the vector path's instruction stream.
        virtual std::shared_ptr<IVectorInstructionStream> GetInstructionStream() = 0;

        /// \brief Sets the vector path's fill brush.
        void setFill(std::shared_ptr<IBrush> value);
        /// \brief Gets the vector path's fill brush.
        std::shared_ptr<IBrush> getFill() const;

        /// \brief Sets the vector path's stroke brush.
        void setStroke(std::shared_ptr<IBrush> value);
        /// \brief Gets the vector path's stroke brush.
        std::shared_ptr<IBrush> getStroke() const;

        /// \brief Sets the vector path's stroke thickness.
        void setStrokeThickness(double value);
        /// \brief Gets the vector path's stroke thickness.
        double getStrokeThickness() const;
    private:
        std::shared_ptr<IBrush> Fill_value;
        std::shared_ptr<IBrush> Stroke_value;
        double StrokeThickness_value;
    };
}