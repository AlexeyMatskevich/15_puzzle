#include "Direction.h"
#include "Random.h"

Direction::Direction(Type type)
    : m_type{ type }
{
}

Direction::Type Direction::getType() const
{
    return m_type;
}

Direction Direction::operator-() const
{
    switch (m_type)
    {
    case Direction::up:
        return{ down };
    case Direction::down:
        return{ up };
    case Direction::left:
        return{ right };
    case Direction::right:
        return{ left };
    }

    assert(0 && "Unsupported direction was passed!");
    return Direction{ up };
}

std::ostream& operator<<(std::ostream& stream, const Direction& dir)
{
    switch (dir.m_type)
    {
    case Direction::up:
        stream << "up";
        break;
    case Direction::down:
        stream << "down";
        break;
    case Direction::left:
        stream << "left";
        break;
    case Direction::right:
        stream << "right";
        break;
    default:
        assert(0 && "Unsupported direction was passed!");
        break;
    }

    return stream;
}

Direction Direction::getRandomDirection()
{
    Type random{ static_cast<Type>(Random::get(0, Type::max_directions - 1)) };

    return Direction{ random };
}
