#pragma once
#include <array>
#include <iostream>
#include <cassert>
#include <optional>
#include "Direction.h"
#include "Tile.h"
#include "Point.h"

class Board
{
public:
    static constexpr int SIZE = 3;

    Board();

    bool moveTile(Direction dir);
    void randomize();
    bool playerWon();

    friend std::ostream& operator<<(std::ostream& stream, const Board& board);

    static std::array<std::array<Tile, SIZE>, SIZE> solved_tiles();
    static Board solved_board();

private:
    std::array<std::array<Tile, Board::SIZE>, Board::SIZE> m_tiles{ Board::solved_tiles() };
    Point m_empty_position{ Point{ SIZE - 1, SIZE - 1 } };

    bool isValidPos(const Point& point) const;
    void swapTiles(const Point& from, const Point& to);
};
