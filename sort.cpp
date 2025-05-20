// SORTING EMPORIUM:
// ---------------------
// most common sorting algorthms in c++ 
// modernized using vectors & swap, array versions can be found in the other c++ file

#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

// Selection Sort
// Time Complexity: O(n^2)
// Advantages: Easy to implement & understand
// Disadvantages: Slower than Quick Sort or Merge Sort
// Uses: Small data sets
// Description: Find the smallest element and swap it with the current element, move onto the next element, repeat.
void selectionSort(vector<int> &arr) {
	int length = arr.size();

	for (int i = 0; i < length - 1; i++) {
		// Assume first element is min
		int min = i;

		// Search whole array for new min 
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[min])
				min = j;
		}	

		// Swap the current & minimum element
		// Swap is equivalent to storing in a temp variable and moing the classic way
		swap(arr[i], arr[min]);
	
	}
}

// Bubble Sort
// Time Complexity: O(n^2)
// Advantages: Easy to implement & understand
// Disadvantages: Very slow for large data sets
// Uses: Small, nearly-sorted data sets
// Description: Repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
void bubbleSort(vector<int> &arr) {
	int length = arr.size();
	for (int i = 0; i < length - 1; i++) {
		// Optmization that checks if any swaps were made on first pass
		// If none, the array is already sorted
		bool swap_check = false;

		// Only checks array elements less than i since the right is sorted (fewer comparisons)
		for (int j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// If the left # is bigger than the one on the right, swap it
				swap(arr[j], arr[j + 1]);
				swap_check = true;
			}
		}
		if (!swap_check)
			break;

	}
}

// Insertion Sort
// Time Complexity: O(n^2)
// Advantages: Easy to implement
// Disadvantages: Very slow for large data sets
// Uses: Small data sets
// Description: Builds the sorted array one element at a time by inserting items into their correct position.
void insertionSort(vector<int> &arr) {
	int length = arr.size();
	// Start at i=1 and assume i=0 is sorted and make this the key to compare with i=0
	for (int i = 1; i < length - 1; i++) {
		int key = arr[i];
		int j = i - 1;

		// Shift elements right and insert key in right spot
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}

// Merge Sort
void merge(vector<int> &arr, int left, int mid, int right) {
	int length1 = mid - left + 1;
	int length2 = right - mid;

	vector<int> L(length1), R(length2);

	for(int i = 0; i < length1; i++)
		L[i] = arr[left + i];
	for(int j = 0; j < length2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;

	while (i < length1 && j < length2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < length1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < length2) {
		arr[k] = R[j];
		j++;
		k++;
	}

}

void mergeSort(vector<int> &arr, int left, int right) {
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void mergeSortWrapper(vector<int> &arr) {
	mergeSort(arr, 0, arr.size() - 1);
}


// Printing helper function

void printArray(const std::vector<int>& arr) {
	for (int val : arr)
		cout << val << " ";
	cout << "\n";
}

// First attempt at function that accepts a function
// Accepts the correct function, executes, times, and then prints results
void benchmark(void (*sortFunc)(vector<int>&), vector<int> arr, const string& name){
	cout << "Running: " << name << endl;
	cout << "-----------------------" << endl;

	cout << "Original array: ";
	printArray(arr);
	
	clock_t start = clock();
	sortFunc(arr);
	clock_t end = clock();

	cout << "Sorted array: ";
	printArray(arr);

	double elapsed = double(end - start) / CLOCKS_PER_SEC;
	cout << fixed << setprecision(6);
	cout << "Time: " << elapsed << " seconds." << endl << endl;
}


int main() {
	vector<int> arr = {37, 82, 11, 10, 5, 95, 26, 22, 31};

	// Performs selection sort on the data
	benchmark(selectionSort, arr, "Selection Sort");

	// Performs bubble sort on the data
	benchmark(bubbleSort, arr, "Bubble Sort");

	// Performs merge sort on the data
	benchmark(mergeSortWrapper, arr, "Merge Sort");

	return 0;
}



