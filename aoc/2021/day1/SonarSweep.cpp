#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsLarger(int,int);

/*
    count the number of times a depth measurement increases from the previous measurement in a given file
*/

int main()
{
    ifstream file;
    file.open("depths.txt");

    int prev = -1;

    int increaseCount = 0;

    if (file.is_open())
    {
        string line;
        while (file)
        {
            getline(file,line);

            int next = stoi(line);

            if (IsLarger(prev, next))
            {
                increaseCount++;
            }

            prev = next;
        }
    }

    file.close();

    cout << increaseCount;
    
    return 0;
}

bool IsLarger(int prev, int next)
{
    if (next > prev && prev != -1)
    {
        return true;
    }
    return false;
}