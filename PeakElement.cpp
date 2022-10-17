#include<iostream>
using namespace std;
int PeakElementFunc(int arrayNum[], int start, int end) {
   int i, mid;
   mid = (end+start+1)/2;
   if((arrayNum[mid] > arrayNum[mid+1] && mid == start)||(arrayNum[mid] > arrayNum[mid-1] && mid == end)) {
      return arrayNum[mid];
   } else if(arrayNum[mid] < arrayNum[mid-1] && arrayNum[mid] > arrayNum[mid+1]) {
      return arrayNum[mid];
   } else if(arrayNum[mid] <= arrayNum[mid+1]) {
      return PeakElementFunc(arrayNum, mid+1, end);
   } else if(arrayNum[mid] <= arrayNum[mid-1]) {
      return PeakElementFunc(arrayNum, start,mid-1);
   }
}
int main() {
   int count, i, p;
   cout<<"\nEnter the number of element: ";
   cin>>count;
   int arr[count];
   for(i = 0; i < count; i++) {
      cout<<"Enter element "<<i+1<<": ";
      cin>>arr[i];
   }
   p = PeakElementFunc(arr, 0, count-1);
   cout<<"\nThe peak element of the given array is: "<<p;
   return 0;
}