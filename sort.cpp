// SORTING EMPORIUM
// ---------------------
// most common sorting algorthms in c++ 
// modernized using vecotrs, array versions can be found in the other c++ file

#include <iostream>
#include <vector>

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
		swap(arr[i], arr[min]);
	}
}





// Printing helper function

void printArray(const std::vector<int>& arr) {
	for (int val : arr)
		cout << val << " ";
	cout << "\n";
}


int main() {
	vector<int> arr = {37, 82, 11, 10, 5, 95, 26, 22, 31};

	cout << "Original array: ";
	printArray(arr);

	// Performs selection sort on the data
	selectionSort(arr);

	cout << "Array after Selection Sort: ";
	printArray(arr);

	return 0;
}
