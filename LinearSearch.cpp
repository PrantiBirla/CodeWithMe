// C++ implementation  of linear search algorithm
// Time complexity: O(N)
// Auxiliary Space: O(1)
#include <iostream>
using namespace std;

int searchNumber(int arr[], int length, int search_number)
{
	int i;
	for (i = 0; i < length; i++)
		if (arr[i] == search_number)
			return i;
	return -1;
}


int main(void)
{
	int arr[] = { 9, 3, 4, 10, 40 };
	int search_number = 10;
	int length = sizeof(arr) / sizeof(arr[0]);


	int search_result = searchNumber(arr, length, search_number);
	(search_result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index " << search_result;
	return 0;
}
