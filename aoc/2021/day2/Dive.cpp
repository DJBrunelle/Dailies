#include <iostream>

#include "Position.h"

int main()
{
    Position position = Position();

    position.ExecuteCommands("commands.txt");

    std::cout <<position.GetHorizontal() << " : " << position.GetDepth() << std::endl;
    std::cout <<position.GetHorizontal() * position.GetDepth() << std::endl;
}