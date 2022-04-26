#include "Position.h"

Position::Position()
{
    horizontal = 0;
    depth = 0;
}

void Position::ExecuteCommands(std::string commands)
{
    std::ifstream file; 

    file.open(commands);

    if (file.is_open())
    {
        while (file)
        {
            std::string line;
            getline(file,line);
            char delim = ' ';
            std::stringstream ss (line); 
            std::string token;

            std::vector<std::string> tokens;

            while(getline(ss, token, delim))
            {
                tokens.push_back(token);
            }
            if (tokens.size() == 2)
            {
                int amt = stoi(tokens.at(1));
                if (tokens.at(0).compare("forward") == 0)
                {
                    ExecuteSingleCommand(Direction::Forward, amt);
                }
                if (tokens.at(0).compare("up") == 0)
                {
                    ExecuteSingleCommand(Direction::Up, amt);
                }
                if (tokens.at(0).compare("down") == 0)
                {
                    ExecuteSingleCommand(Direction::Down, amt);
                }
            }
        }
    }
}

void Position::ExecuteSingleCommand(Direction dir, int amt)
{
    if (dir == Direction::Forward)
    {
        horizontal += amt;
    } else if (dir == Direction::Up)
    {
        depth -= amt;
    } else if (dir == Direction::Down)
    {
        depth += amt;
    }   
}