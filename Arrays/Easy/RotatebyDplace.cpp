//Given an array of integers, rotating array of elements by k elements either left or right.

#include <iostream>
using namespace std;
// Function to Reverse the array
void Reverse(int arr[], int start, int end){
  while (start <= end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

// Function to Rotate k elements to left
void Rotateeletoleft(int arr[], int n, int k){
  // Reverse first k elements
  Reverse(arr, 0, k - 1);
  // Reverse last n-k elements
  Reverse(arr, k, n - 1);
  // Reverse whole array
  Reverse(arr, 0, n - 1);
}

// Function to Rotate k elements to right
void Rotateeletoright(int arr[], int n, int k)
{
  // Reverse first n-k elements
  Reverse(arr, 0, n - k - 1);
  // Reverse last k elements
  Reverse(arr, n - k, n - 1);
  // Reverse whole array
  Reverse(arr, 0, n - 1);
}


//-----------BRUTE, using temp array--------------
// void Rotatetoright(int arr[], int n, int k){
//   if (n == 0)
//     return;
//   k = k % n;
//   if (k > n)
//     return;
//   int temp[k];
//   for (int i = n - k; i < n; i++){
//     temp[i - n + k] = arr[i];
//   }
//   for (int i = n - k - 1; i >= 0; i--){
//     arr[i + k] = arr[i];
//   }
//   for (int i = 0; i < k; i++){
//     arr[i] = temp[i];
//   }
// }


int main(){
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = 7;
  int k = 2;
  Rotateeletoleft(arr, n, k);
  cout << "After Rotating the k elements to left ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}