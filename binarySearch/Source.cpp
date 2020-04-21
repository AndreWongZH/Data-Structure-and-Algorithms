#include <iostream>
using namespace std;

int binarySearch(int size, int* arr, int key) {
	int mid;
	int begin = 0;
	int end = size;

	while (begin < end - 1) {
		mid = (begin + end) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		if (arr[mid] > key) {
			end = mid;
		}
		else {
			// remember to +1
			begin = mid+1;
		}
	}

	return -1;
}

int main(void) {
	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int arr2[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

	cout << binarySearch(9, arr2, 3) << endl;
}