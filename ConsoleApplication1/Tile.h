#include <iostream>
#pragma once
class Tile
{
private:
    int m_value;
public:
    Tile() = default;
    explicit Tile(int value);

    bool isEmpty() const;
    int getNum() const;

    friend bool operator==(const Tile& t1, const Tile& t2);
    friend std::ostream& operator<<(std::ostream& ostream, const Tile& tile);
};
