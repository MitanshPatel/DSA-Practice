// Given an positive integer N and a list of N integers A[].
// Each element in the array denotes the maximum length of jump you can cover.
// Find out if you can make it to the last index if you start at the first index of the list.


// Example 1:
// Input:
// N = 6
// A[] = {1, 2, 0, 3, 0, 0} 
// Output:
// 1
// Explanation:
// Jump 1 step from first index to
// second index. Then jump 2 steps to reach 
// 4th index, and now jump 2 steps to reach
// the end.

#include <bits/stdc++.h>
using namespace std;


//Method 1
int canReach(int A[], int N) {
    if(N==1)
        return 1;
        
    int reachable=A[0];
    for(int i=1;i<N;++i){
        if(reachable<i)
            return 0;
        if(reachable>=N)
            return 1;
        reachable=max(reachable,A[i]+i);
    }
    return 1;
}

//Method 2
int canReach(int A[], int N) {
    int pivot = N-1;
    for(int i=N-1; i>=0; i--){
        if(i+A[i] >= pivot)
            pivot = i;
    }
    return pivot==0;
}