// C++ program to implement recursive Binary Search
// Time Complexity: O(log n)
// Auxiliary Space: O(log n)
#include <bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int left, int right, int search_element)
{
	if (right >= left) {
		int middle_element = left + (right - left) / 2;

		// If the element is present at the middle
		// itself
		if (arr[middle_element] == search_element)
			return middle_element;

		// If element is smaller than middle element, then
		// it can only be present in left subarray
		if (arr[middle_element] > search_element)
			return binarySearch(arr, left, middle_element - 1, search_element);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, middle_element + 1, right, search_element);
	}

	//return -1 if element is not present
	return -1;
}

int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
	return 0;
}
