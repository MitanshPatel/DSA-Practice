// Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array.
// It is given that all array elements are distinct.
// Note :-  l and r denotes the starting and ending index of the array.

// Input:
// N = 6
// arr[] = 7 10 4 3 20 15
// K = 3
// Output : 7
// Explanation :
// 3rd smallest element in the given array is 7.

#include <bits/stdc++.h>
using namespace std;

//------using quick sort-----------
int lomuto(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j=low; j<= high - 1; j++) {
        if (pivot >= arr[j]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
int kthSmallest(int arr[], int l, int r, int k) {
    int n = r + 1;
    while (l <= r) {
        int pi = lomuto(arr, l, r);
        if (pi == k - 1) 
            return arr[pi];
        else if (pi > k - 1)
            r = pi - 1;
        else
            l = pi + 1;
    }
    return -1;
}

//----------Using heap----------
int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> pq;
    for (int i=r; i>=0; i--){
        pq.push(arr[i]);
        if (pq.size() > k)pq.pop();
    }
    return pq.top();
}