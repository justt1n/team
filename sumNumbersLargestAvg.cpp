#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> arr, int start, int end, int key) {
    int i = (start + end) / 2;
	while (start != i && end != i) {
		if (arr[i] >= key) end = i;
		else start = i;
		i = (start + end) / 2;
	}	
	for (i = start; i <= end; i++)
		if (arr[i] >= key) break;
	return i;

}
int main() {
	vector<int> arr = {1, 2, 3, 5};
	cout << binarySearch(arr, 0, arr.size() - 1, 0);
    return 0;
}