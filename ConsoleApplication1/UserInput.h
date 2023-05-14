#pragma once
#include <array>
#include <iostream>
#include <cassert>
#include <limits>
#include <algorithm>
#include <ranges>
#include "Direction.h"

namespace UserInput
{
    extern const std::array<char, 5> valid_commands;
    bool isValidCommand(const char& ch);
    void ignoreLine();
    char getCharacter();
    char getConnandFromUser();
    Direction charToDirection(char ch);
}
