#pragma once
#include <memory>
#include "ArraySlice.h"
#include "ICommand.h"

namespace Engine
{
    /// \brief Represents a block of commands that are applied to a
    /// single target in sequence.
    template<typename T>
    class CommandBlock : public virtual ICommand<T>
    {
    public:
        /// \brief Creates a new command block from the given commands.
        CommandBlock(stdx::ArraySlice<std::shared_ptr<ICommand<T>>> Commands);

        /// \brief Executes the command on the given target.
        void Execute(T Target) override;

        /// \brief Gets the command block's commands.
        stdx::ArraySlice<std::shared_ptr<ICommand<T>>> getCommands() const;
    private:
        /// \brief Sets the command block's commands.
        void setCommands(stdx::ArraySlice<std::shared_ptr<ICommand<T>>> value);

        stdx::ArraySlice<std::shared_ptr<ICommand<T>>> Commands_value;
    };
}

#include "CommandBlock.hxx"