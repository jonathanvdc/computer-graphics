#pragma once

namespace Engine
{
    /// \brief Describes an action that can be applied to a target of
    /// type 'T'.
    /// \remark Commands may prove useful because they can remain even
    /// after the object that created them is long gone, and
    /// because they may be applied more than once.
    /// For example, a shape could perform some of its geometry
    /// processing when creating its render command, as said
    /// geometry is immutable within the scope of the command.
    template<typename T>
    struct ICommand
    {
        /// \brief Executes the command on the given target.
        virtual void Execute(T Target) = 0;
    };
}