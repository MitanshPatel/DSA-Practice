// Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1.
// Note: Consider 0 based indexing

// Examples:

// Example 1:
// Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}
// Output: 4
// Explanation: As the target value is 13 , it appears for the first time at index number 2.

// Example 2:
// Input: N = 7, target=60, array[] = {3,4,13,13,13,20,40}
// Output: -1
// Explanation: Target value 60 is not present in the array 

#include<bits/stdc++.h>

using namespace std;

int solve(int n, int key, vector < int > & v) {
  int res = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (v[i] == key) {
      res = i;
      break;
    }
  }
  return res;
}

int main() {
  int n = 7;
  int key = 13;
  vector < int > v = {3,4,13,13,13,20,40};
   
  // returning the last occurrence index if the element is present otherwise -1
  cout << solve(n, key, v) << "\n";

  return 0;
}