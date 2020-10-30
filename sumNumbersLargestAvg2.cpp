#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumNumbersLargerAverage(std::vector<int> a)
{
    long long s = 0;
    for (int i = 0; i < a.size(); i++)
        s += a[i];
    long long avg = s / a.size();
    sort(a.begin(), a.end());
    long long sum = 0;
    for (int i = 0; i < a.size(); i++)
        if (a.at(i) > avg)
            sum += a.at(i);
    if (sum != 0)
        return sum;
    return -1;
}
