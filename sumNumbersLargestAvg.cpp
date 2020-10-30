#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> arr, int start, int end, int key)
{
	int i = (start + end) / 2;
	while (start != i && end != i)
	{
		if (arr[i] >= key)
			end = i;
		else
			start = i;
		i = (start + end) / 2;
	}
	for (i = start; i <= end; i++)
		if (arr[i] > key)
			break;
	return i;
}

int sumNumbersLargerAverage(std::vector<int> a)
{
	long long s = 0;
	for (int i = 0; i < a.size(); i++)
		s += a[i];
	long long avg = s / a.size();
	sort(a.begin(), a.end());
	long long sum = 0;
	int start = binarySearch(a, 0, a.size() - 1, avg);
	for (int i = start; i < a.size(); i++)
		sum += a[i];
	return sum;
}

int main()
{
	vector<int> a = {5, 5, 6, 9, 9};
	cout << binarySearch(a, 0, a.size() - 1, 3) << endl;
	cout << sumNumbersLargerAverage(a);
	return 0;
}