// Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. 
//The relative order of the elements should be kept the same.
// If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. 
//It does not matter what you leave beyond the first k elements.
// Note: Return k after placing the final result in the first k slots of the array.

#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}

int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}