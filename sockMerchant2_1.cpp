#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

std::vector<int> saleMerchandise(std::vector<int> socks, std::vector<int> sizes)
{
    vector<int> values;
    sort(socks.begin(), socks.end());
    // sort(sizes.begin(), sizes.end());
    for (int i = 0; i < sizes.size(); i++)
        values.at(i) = 0;
    int count = 0, pair = 0, j = 0;
    for (int i = 0; i < socks.size() - 1; i++)
        if (socks.at(i) == sizes.at(j))
        {
            pair++;
            if (pair == 2)
            {
                count++;
                pair = 0;
            }
        }
        else
        {
            values.at(j) = count;
            j++;
        }
    return values;
}

int main()
{
    vector<int> socks = {1, 2, 3, 1, 2, 4};
    vector<int> sizes = {1, 2, 4};
    vector<int> values = saleMerchandise(socks, sizes);
    for (int i = 0; i < values.size(); i++)
        cout << values.at(i) << " ";
    return 0;
}