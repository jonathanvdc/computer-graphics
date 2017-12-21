#pragma once
#include <functional>
#include "ArraySlice.h"
#include "Vector3.h"

namespace Engine
{
    /// \brief Declares a face in a polyhedron.
    class Face
    {
    public:
        /// \brief Creates a new empty face.
        Face();
        /// \brief Creates a new face from the given index array.
        Face(stdx::ArraySlice<int> Indices);

        bool Contains(int Index) const;

        Vector3 GetCenter(stdx::ArraySlice<Vector3> Points) const;

        int GetIntersectionSize(Face Other) const;

        int GetHashCode() const;

        bool operator==(Face Other) const;

        bool operator!=(Face Other) const;

        /// \brief The face's indices, stored as a dynamic integer array.
        stdx::ArraySlice<int> Indices;
    private:
        bool CompareIndices(stdx::ArraySlice<int> First, stdx::ArraySlice<int> Second) const;
    };
}
namespace std
{
    template<>
    struct hash<Engine::Face>
    {
        std::size_t operator()(const Engine::Face& Arg) const
        {
            return Arg.GetHashCode();
        }
    };
}