#include "Board.h"

Board::Board()
{
    randomize();
}

bool Board::moveTile(Direction dir)
{
    Point from = m_empty_position.getAdjacentPoint(-dir);
    if (isValidPos(from))
    {
        swapTiles(from, m_empty_position);
        return true;
    }

    return false;
}

void Board::randomize()
{
    for (int count{ 0 }; count < 1000; ++count)
    {
        Direction dir = Direction::getRandomDirection();
        moveTile(dir);
    }
}

bool Board::playerWon()
{
    for (int row{ 0 }; row < SIZE; ++row)
    {
        for (int col{ 0 }; col < SIZE; ++col)
        {
            if (m_tiles[row][col] != solved_tiles()[row][col])
            {
                return false;
            }
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& stream, const Board& board)
{
    for (auto& row : board.m_tiles)
    {
        for (auto& col : row)
        {
            stream << col;
        }
        stream << '\n';
    }
    return stream;
}

std::array<std::array<Tile, Board::SIZE>, Board::SIZE> Board::solved_tiles()
{
    static std::optional<std::array<std::array<Tile, SIZE>, SIZE>> solved_tiles = std::nullopt;

    if (!solved_tiles.has_value())
    {
        solved_tiles.emplace();
        int last_number = SIZE * SIZE;
        for (int row_i{ 0 }; auto & row : *solved_tiles)
        {
            int number_offset = row_i * SIZE;
            for (int col_i{ 1 }; auto & col : row)
            {
                int number = number_offset + col_i;
                if (number != last_number)
                {
                    col = Tile{ number };
                }
                else
                {
                    col = Tile{ 0 };
                }
                ++col_i;
            }
            ++row_i;
        }
    }

    return *solved_tiles;
}

Board Board::solved_board()
{
    Board board{};
    board.m_tiles = solved_tiles();
    return board;
}

bool Board::isValidPos(const Point& point) const
{
    if ((0 <= point.x) && (point.x < SIZE) && (0 <= point.y) && (point.y < SIZE))
    {
        return true;
    }
    return false;
}

void Board::swapTiles(const Point& from, const Point& to)
{
    assert(from != to && "The points must not overlap.");
    Tile& toTile{ m_tiles[to.y][to.x] };
    assert(toTile.isEmpty() && "The Second Tile for swapping should be empty.");
    std::swap(m_tiles[from.y][from.x], toTile);
    m_empty_position = from;
}