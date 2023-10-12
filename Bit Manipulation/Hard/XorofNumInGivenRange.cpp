// You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

// Input: 
// L = 4, R = 8 
// Output:
// 8 
// Explanation:
// 4 ^ 5 ^ 6 ^ 7 ^ 8 = 8

#include<bits/stdc++.h>
using namespace std;

int func(int x){
    if (x % 4 == 0){
        return x;
    }
    if (x % 4 == 1){
        return 1;
    }
    if (x % 4 == 2){
        return x + 1;
    }
    if (x % 4 == 3){
        return 0;
    }
}
int findXOR(int l, int r){
    return func(l - 1) ^ func(r);
}