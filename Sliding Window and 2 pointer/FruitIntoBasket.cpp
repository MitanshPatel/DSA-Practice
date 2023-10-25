// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits of size N, where fruits[i]  is the type of fruit the ith tree produces.
// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.

// Example 1:
// Input:
// N = 6
// fruits [ ] = { 0, 1, 2, 2, 2, 2 }
// Output: 5
// Explanation: It's optimal to pick from trees(0-indexed) [1,2,3,4,5].

#include<bits/stdc++.h>
using namespace std;

int totalFruits(int n, vector<int> &fruits) {
    int prev=-1,curr=-1;
    int maxi=0;
    int j=0;
    for(int i=0;i<n;i++){
        if(prev==-1||fruits[i]==fruits[prev])
        prev=i;
        
        else if(curr==-1||fruits[i]==fruits[curr])
        curr=i;
        
        else if(fruits[i]!=fruits[prev]&&fruits[i]!=fruits[curr]){
            if(i-1==prev){
                j=curr+1;
                curr=i;
            }
            else{ 
                j=prev+1;
                prev=i;
            }
        }
        maxi=max(maxi,i-j+1);
    }
    return maxi;
}