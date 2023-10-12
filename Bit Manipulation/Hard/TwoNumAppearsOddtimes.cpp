// Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. 
// Find the two numbers in decreasing order which has odd occurrences.

// Example 1:

// Input:
// N = 8
// Arr = {4, 2, 4, 5, 2, 3, 3, 1}
// Output: {5, 1} 
// Explaination: 5 and 1 have odd occurrences.

#include<bits/stdc++.h>
using namespace std;

//for 2 numbers that occur odd times
vector<long long int> twoOddNum(long long int Arr[], long long int N)  {
    // code here
    int xo = 0,a = 0 ,b = 0;
    for(int i = 0 ; i< N; i++) xo ^= Arr[i];
    int rsbm =xo & -xo;  //to find rightmost set bit

    for(int i = 0 ; i< N; i++){
        if(Arr[i]&rsbm) a ^= Arr[i];
        else b ^= Arr[i];
    }
    return {a,b};
}

//if 1 number occurs odd times
int getOddOccurrence(int arr[], int n) {
    // code here
    int xor1=arr[0];
    for(int i=1; i<n; i++){
        xor1=xor1^arr[i];
    }
    return xor1;
}