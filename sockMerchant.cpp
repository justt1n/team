#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sockMerchant(std::vector<int> sizes)
{
    sort(sizes.begin(), sizes.end());
    int count = 0;
    for (int i = 0; i < sizes.size() - 1; i++)
        if (sizes.at(i) == sizes.at(i + 1))
        {
            count++;
            i++;
        }
    return count;
}