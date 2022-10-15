//Kadane Algorithm is used to find max Sum Subarray.
#include <iostream>
using namespace std;
int maxSumSubarray(int* arr, int n) {
	int curr_sum = 0;
	int best_sum = INT_MIN;
	for (int i = 0; i < n; i++) {
		curr_sum += arr[i];
		if (curr_sum > best_sum)
			best_sum = curr_sum;
		if (curr_sum < 0)
			curr_sum = 0;
	}
	return best_sum;
}
int main()
{
	int n;
  cin>>n;
  int*arr=new int[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<maxSumSubarray(arr,n)<endl;
}

