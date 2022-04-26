#include <iostream>
#include <fstream>
#include <string>

#include "SlidingWindow.h"

bool IsLarger(int,int);

/*
    count the number of times a depth measurement increases from the previous measurement in a given file

    pt 2: group 3 at a time and compare to previous group (sliding window)
*/

int main()
{
    SlidingWindow list = SlidingWindow("depths.txt");

    std::cout << list.GetIncreasingCount(3) << std::endl;
    
    return 0;
}
