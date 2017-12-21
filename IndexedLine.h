#pragma once
#include <functional>
#include "Face.h"

namespace Engine
{
    struct IndexedLine
    {
        IndexedLine(int Point1, int Point2);

        Face ToFace() const;

        int GetHashCode() const;

        bool operator==(IndexedLine Other) const;

        bool operator!=(IndexedLine Other) const;

        int EndPoint;
        int StartPoint;
    };
}
namespace std
{
    template<>
    struct hash<Engine::IndexedLine>
    {
        std::size_t operator()(const Engine::IndexedLine& Arg) const
        {
            return Arg.GetHashCode();
        }
    };
}