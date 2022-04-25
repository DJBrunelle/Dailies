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

    int lineCount = 0;

    int first, second, third = 0;

    bool firstRound = true;

    if (file.is_open())
    {
        string line;
        while (file)
        {
            getline(file,line);

            int lineNum = stoi(line);

            // cout << "run: " << lineCount << endl;

            // cout << first<< endl;
            // cout << second<< endl;
            // cout << third<< endl;

            if (lineCount > 3)
            {
                firstRound = false;
            }

            if (lineCount % 3 == 0)
            {
                if (!firstRound && IsLarger(prev, first))
                {
                    increaseCount++;
                }
                prev = first;
                first = lineNum;
                second += lineNum; third += lineNum;
            }
            if (lineCount % 3 == 1)
            {
                if (!firstRound && IsLarger(prev, second))
                {
                    increaseCount++;
                }
                prev = second;
                second = lineNum;
                first+= lineNum; third += lineNum;

            }
            if (lineCount % 3 == 2)
            {
                if (!firstRound && IsLarger(prev, third))
                {
                    increaseCount++;
                }
                prev = third;
                third = lineNum;
                first += lineNum; second += lineNum;
            }
            lineCount++;
        }
    }

    file.close();

    cout << increaseCount << endl;
    
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