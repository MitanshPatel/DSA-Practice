// You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

// Example 1:

// Input: N = 4
// Output: 5
// Explanation:
// For numbers from 1 to 4.
// For 1: 0 0 1 = 1 set bits
// For 2: 0 1 0 = 1 set bits
// For 3: 0 1 1 = 2 set bits
// For 4: 1 0 0 = 1 set bits
// Therefore, the total set bits is 5.

#include <bits/stdc++.h>
using namespace std;

int highestPow(int n){
    int x = 0; 
    while(1 << x <= n) x++;
    return x-1;
}

int solve(int n){
    if(n == 0) return 0;
    // Calculate Highest Power
    int x = highestPow(n);
    // Count Bits Till 2 ^ x - 1 if n = 11 Then for 7
    int bits = (1 << (x-1)) * x;
    // Count the Rest left Most Bits
    int rest = n - (1 << x) + 1;
    return  bits + rest + solve(rest - 1);
}
int countSetBits(int n){
    return solve(n);
}