#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMax(vector<int> a, int start, int end)
{
    int max = 0;
    for (int i = start - 1; i <= end - 1; i++)
    {
        max = (a[i] > max) ? a[i] : max;
    }
    return max;
}
vector<int> maxRange(vector<int> a, vector<vector<int>> Q)
{
    vector<int> res; // result
    int start, end;
    for (int i = 0; i < Q.size(); i++)
    { // duyet danh sach cau hoi
        start = Q[i].at(0);
        end = Q[i].at(1);
        int ans = getMax(a, start, end);
        res.push_back(ans);
    }
    return res;
}
