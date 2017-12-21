#include "Face.h"

#include <functional>
#include "ArraySlice.h"
#include "Vector3.h"

using namespace Engine;

/// \brief Creates a new empty face.
Face::Face()
    : Indices(0)
{ }

/// \brief Creates a new face from the given index array.
Face::Face(stdx::ArraySlice<int> Indices)
    : Indices(Indices)
{ }

bool Face::CompareIndices(stdx::ArraySlice<int> First, stdx::ArraySlice<int> Second) const
{
    if (First.GetLength() != Second.GetLength())
        return false;

    for (int i = 0; i < First.GetLength(); ++i)
        if (First[i] != Second[i])
            return false;

    return true;
}

bool Face::Contains(int Index) const
{
    for (auto& item : this->Indices)
        if (item == Index)
            return true;

    return false;
}

Vector3 Face::GetCenter(stdx::ArraySlice<Vector3> Points) const
{
    Vector3 result;
    for (auto& item : this->Indices)
        result += Points[item] / (double)this->Indices.GetLength();
    return result;
}

int Face::GetIntersectionSize(Face Other) const
{
    int result = 0;
    for (auto& item : this->Indices)
        if (Other.Contains(item))
            ++result;

    return result;
}

int Face::GetHashCode() const
{
    int result = 0;
    for (auto& item : this->Indices)
        result ^= item;
    return result;
}

bool Face::operator==(Face Other) const
{
    return this->CompareIndices(this->Indices, Other.Indices);
}

bool Face::operator!=(Face Other) const
{
    return !this->CompareIndices(this->Indices, Other.Indices);
}