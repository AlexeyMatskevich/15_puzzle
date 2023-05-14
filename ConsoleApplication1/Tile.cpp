#include "Tile.h"
#include <format>

Tile::Tile(int value): m_value{ value }{}

bool Tile::isEmpty() const
{ 
    return (m_value == 0);
}

int Tile::getNum() const
{
    return m_value;
}

bool operator==(const Tile& t1, const Tile& t2)
{
    return t1.m_value == t2.m_value;
}

std::ostream& operator<<(std::ostream& ostream, const Tile& tile)
{
    ostream << ' ' << ((tile.m_value == 0) ? ("   ") : (std::format("{:^3}", tile.m_value)));
    return ostream;
}