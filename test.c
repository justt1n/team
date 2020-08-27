#include <iostream>
#include <vector>

using namespace std;

vector<int> slidingWindowMax(vector<int> arr, int k)
{
	cout << "code from Qk" << endl;
	cout << "another code";
    vector<int> res;
    if (k > arr.size())
        return res;
    int max;
    for (int i = 0; i <= arr.size() - k; i++)
    {
        max = arr[i];
        for (int j = i + 1; j <= i + k - 1; j++)
        {
            max = (arr[j] >= max) ? arr[j] : max;
        }
        res.push_back(max);
    }
    return res;
}
