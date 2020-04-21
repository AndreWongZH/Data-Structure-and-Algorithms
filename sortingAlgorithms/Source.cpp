#include <iostream>
#include <vector>
using namespace std;

void printArr(int* arr) {
	for (int n = 0; n < 10; n++) {
		cout << arr[n] << " ";
	}
	cout << endl;
}

void shuffleArr(int* arr) {
	for (int n = 0; n < 10; n++) {
		arr[n] = (9 - n);
	}
}

void bubbleSort(int* arr, int size) {
	int temp;
	int swap = 0;

	cout << "execute bubble sort" << endl;

	for (int i = 0; i < size; i++) {
		// remember to size - i - 1
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				swap = 1;
			}
		}

		if (swap == 0) {
			cout << "broken" << endl;
			break;
		}
		else {
			swap = 0;
		}
	}
}

void selectionSort(int* arr, int size) {
	int minPos;
	int temp;
	int hasSwapped = 0;

	cout << "execute selection sort" << endl;

	for (int i = 0; i < size; i++) {
		// find minimun value
		for (int j = 1 + i; j < size; j++) {
			if (arr[j] < arr[i]) {
				minPos = j;
				hasSwapped = 1;
			}
		}

		if (hasSwapped) {
			//swap values
			temp = arr[minPos];
			arr[minPos] = arr[i];
			arr[i] = temp;
			hasSwapped = 0;
		}
	}
}

void insertionSort(int* arr, int size) {
	int key;
	int j;

	cout << "execute insertion sort" << endl;

	for (int i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void merge(int* arr, int start, int mid, int end) {
	int i, j, k;

	int N = end - start + 1;

	// make temp arrys
	vector<int> temparr(N);

	i = start;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			temparr[k] = arr[i];
			i++;
		}
		else {
			temparr[k] = arr[j];
			j++;
		}
		k++;
	}

	while (i <= mid) {
		temparr[k] = arr[i];
		i++;
		k++;
	}

	while (j <= end) {
		temparr[k] = arr[j];
		j++;
		k++;
	}

	for (i = 0; i < N; i++) {
		arr[start + i] = temparr[i];
	}
}

void mergeSort(int* arr, int start, int end) {
	int mid;

	cout << "execute merge sort" << endl;

	if (start < end) {
		mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int partition(int* arr, int start, int end) {
	// failed code

	//int pivot = arr[start];
	//int m = start;
	//int high = end - 1;
	//int temp;

	//while (low < high) {
	//	while (arr[low] < arr[pivot]) {
	//		low++;
	//	}
	//	while (arr[high] > arr[pivot]) {
	//		high--;
	//	}
	//	if (low < high) {
	//		temp = arr[low];
	//		arr[low] = arr[high];
	//		arr[high] = temp;
	//	}
	//}
	//temp = arr[low - 1];
	//arr[low - 1] = arr[pivot];
	//arr[pivot] = temp;

	//return low - 1;


	int pivotValue = arr[start];
	int m = start;
	int k;

	for (k = start + 1; k <= end; k++) {
		if (arr[k] < pivotValue) {
			m++;
			swap(arr[k], arr[m]);
		}
	}
	swap(arr[start], arr[m]);
	return m;
}

void quickSort(int* arr, int start, int end) {
	cout << "execute quick sort" << endl;

	if (start < end) {
		int p = partition(arr, start, end);
		quickSort(arr, start, p - 1);
		quickSort(arr, p + 1, end);
	}
}

int main(void) {
	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int arr2[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 9, 8 };

	bubbleSort(arr, 10);
	printArr(arr);
	shuffleArr(arr);
	selectionSort(arr, 10);
	printArr(arr);
	shuffleArr(arr);
	insertionSort(arr, 10);
	printArr(arr);
	shuffleArr(arr);
	mergeSort(arr, 0, 10-1);
	printArr(arr);
	shuffleArr(arr);
	quickSort(arr, 0, 10 - 1);
	printArr(arr);
}