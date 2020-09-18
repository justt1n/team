#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int>> harderEasyProblem(vector<long long> p, vector<int> q, vector<int> r)
{
    vector<vector<int>> a;
    int n = p.size();
    for (int i = 0; i < n; i++)
        for (int j = 1; j < p[i]; j++)
            if (p[i] % j == 0)
            {
                int k = p[i] / j;
                if (k / j == q[i])
                    if (k % j == r[i])
                    {
                        a.push_back({k, j});
                        break;
                    }
                    else if (j / k == q[i])
                        if (j % k == r[i])
                        {
                            a.push_back({j, k});
                            break;
                        }
            }
    return a;
}

int main()
{
    vector<long long> p = {36, 323, 104, 240};
    vector<int> q = {4, 1, 1, 1};
    vector<int> r = {0, 2, 5, 8};
    vector<vector<int>> ketQua = harderEasyProblem(p, q, r);
    int n = p.size();
    for (int i = 0; i < ketQua.size(); i++)
        cout << ketQua[i].at(0) << " " << ketQua[i].at(1) << endl;
    return 0;
    cout << "ne";
}