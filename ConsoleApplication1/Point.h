#pragma once
#include "Direction.h"

class Point
{
public:
    Point(int x, int y);

    Point getAdjacentPoint(const Direction& dir) const;

    friend bool operator==(const Point& p1, const Point& p2);
    friend bool operator!=(const Point& p1, const Point& p2);
    
    friend class Board;
private:
    int x;
    int y;
};
