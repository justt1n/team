#include <iostream>
#include <vector>

using namespace std;

vector<int> slidingWindowMax(vector<int> arr, int k)
{
<<<<<<< HEAD:test.c
	cout << "code from Qk" << endl;
	cout << "another code";
=======
    cout << "code from Qk" << endl;
>>>>>>> 1bf639ce2666278c57dc912153be73a8eb5f1d0f:test.cpp
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
