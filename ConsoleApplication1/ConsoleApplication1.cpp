#include "Random.h"
#include "Direction.h"
#include "Tile.h"
#include "Point.h"
#include "Board.h"
#include "UserInput.h"

int main()
{
    Board board{};

    std::cout << "Your board: \n" << board << "\n\n";
    std::cout << "To win, you have to assemble such a board: \n" << board.solved_board() << "\n\n";
    std::cout << "Valid commands to move tile: \n";

    for (int i{ 1 }; auto & command : UserInput::valid_commands)
    {
        std::cout << i << ' ' << command << "\n";
        ++i;
    }

    std::cout << "\nUse q to quit from game. \n\n";

    while (true)
    {
        char ch{ UserInput::getConnandFromUser() };

        if (ch == 'q')
        {
            std::cout << "\n\nBye!\n\n";
            return 0;
        }
        else
        {
            Direction dir{ UserInput::charToDirection(ch) };

            board.moveTile(dir);
        }
        
        if (board.playerWon())
        {
            std::cout << "\n\nYou won!\n\n";
            return 0;
        }
        else
        {
            std::cout << board;
        }
    }
    return 0;
}