#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class SlidingWindow 
{
public:
    SlidingWindow(std::string file);

    int GetIncreasingCount(int numsInGroup);

private:
    std::vector<int> nums;

    std::vector<int> GetSumVector(int groupSize);
};