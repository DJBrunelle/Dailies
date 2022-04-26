#include "SlidingWindow.h"


SlidingWindow::SlidingWindow(std::string file)
{
    nums = {};
    std::ifstream fStream; 

    fStream.open(file);

    if (fStream.is_open())
    {
        std::string line;
        while (fStream)
        {
            getline(fStream,line);
            int lineNum = stoi(line);

            nums.push_back(lineNum);
        }
    }
}

int SlidingWindow::GetIncreasingCount(int groupsize)
{
    int prev = -1;
    int increaseCount = 0;

    auto numList = nums;

    if (groupsize > 1)
    {
        numList = GetSumVector(groupsize);
    }

    for (int ii = 0; ii < numList.size(); ii++)
    {
        if (prev != -1 && numList.at(ii) > prev)
        {
            increaseCount++;

        }
        prev = numList.at(ii);
    }

    return increaseCount;
}

std::vector<int> SlidingWindow::GetSumVector(int groupSize)
{
    int tempSums[groupSize] = {0}; 

    std::vector<int> newList;

    for (int ii = 0; ii < nums.size(); ii++)
    {
        
        for (int ij = 0; ij < groupSize; ij++)
        {
            if(ii >= groupSize && ii % groupSize == ij)
            {
                newList.push_back(tempSums[ij]);
                tempSums[ij] = 0;
            }
            if (ij <= ii)
            {
                tempSums[ij] += nums[ii];
            }
        }
    }
    return newList;
}