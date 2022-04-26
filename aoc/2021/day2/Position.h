#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class Position
{
    public:
        Position();
        void ExecuteCommands(std::string commands);
        int GetHorizontal(){return horizontal;}
        int GetDepth(){return depth;}
    private:
        int horizontal;
        int depth;
        enum Direction
        {
            Forward,
            Up,
            Down
        };

        void ExecuteSingleCommand(Direction dir, int amt);
};