#include "CommandBlock.h"

#include <memory>
#include "ArraySlice.h"
#include "ICommand.h"

using namespace Engine;

/// \brief Creates a new command block from the given commands.
template<typename T>
CommandBlock<T>::CommandBlock(stdx::ArraySlice<std::shared_ptr<ICommand<T>>> Commands)
{
    this->setCommands(Commands);
}

/// \brief Executes the command on the given target.
template<typename T>
void CommandBlock<T>::Execute(T Target)
{
    for (auto& item : this->getCommands())
        item->Execute(Target);
}

/// \brief Gets the command block's commands.
template<typename T>
stdx::ArraySlice<std::shared_ptr<ICommand<T>>> CommandBlock<T>::getCommands() const
{
    return this->Commands_value;
}

/// \brief Sets the command block's commands.
template<typename T>
void CommandBlock<T>::setCommands(stdx::ArraySlice<std::shared_ptr<ICommand<T>>> value)
{
    this->Commands_value = value;
}