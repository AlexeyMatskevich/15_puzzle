#pragma once
#include <iostream>
#include <cassert>

class Direction
{
public:
    enum Type
    {
        up,
        down,
        left,
        right,
        max_directions
    };

    Direction(Type type);

    Type getType() const;

    Direction operator-() const;
    friend std::ostream& operator<<(std::ostream& stream, const Direction& dir);

    static Direction getRandomDirection();

private:
    Type m_type{};
};
