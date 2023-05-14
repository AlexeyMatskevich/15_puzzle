#include "UserInput.h"

namespace UserInput
{
    constexpr std::array<char, 5> valid_commands{ 'w', 'a', 's', 'd', 'q' };

    bool isValidCommand(const char& ch)
    {
        return (std::ranges::find(valid_commands, ch) != valid_commands.end());
    }

    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    char getCharacter()
    {
        char operation{};
        std::cin >> operation;
        return operation;
    }

    char getConnandFromUser()
    {
        char ch{};
        while (!isValidCommand(ch))
            ch = getCharacter();

        return ch;
    }

    Direction charToDirection(char ch)
    {
        switch (ch)
        {
        case 'w': return Direction{ Direction::up };
        case 's': return Direction{ Direction::down };
        case 'a': return Direction{ Direction::left };
        case 'd': return Direction{ Direction::right };
        }

        assert(0 && "Unsupported direction was passed!");
        return Direction{ Direction::up };
    }
}
