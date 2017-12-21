#include "IndexedLine.h"

#include <functional>
#include <initializer_list>
#include "ArraySlice.h"
#include "Face.h"

using namespace Engine;

IndexedLine::IndexedLine(int Point1, int Point2)
{
    if (Point1 > Point2)
    {
        this->StartPoint = Point1;
        this->EndPoint = Point2;
    }
    else
    {
        this->StartPoint = Point2;
        this->EndPoint = Point1;
    }
}

Face IndexedLine::ToFace() const
{
    return Face(stdx::ArraySlice<int>({ this->StartPoint, this->EndPoint }));
}

int IndexedLine::GetHashCode() const
{
    return this->EndPoint << 16 | this->StartPoint;
}

bool IndexedLine::operator==(IndexedLine Other) const
{
    return this->StartPoint == Other.StartPoint && 
           this->EndPoint == Other.EndPoint;
}

bool IndexedLine::operator!=(IndexedLine Other) const
{
    return this->StartPoint != Other.StartPoint || 
           this->EndPoint != Other.EndPoint;
}