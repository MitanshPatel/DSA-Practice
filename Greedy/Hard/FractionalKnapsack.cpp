// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item. 

// Example 1:

// Input:
// N = 3, W = 50
// values[] = {60,100,120}
// weight[] = {10,20,30}
// Output:
// 240.00
// Explanation:Total maximum value of item
// we can have is 240.00 from the given
// capacity of sack. 

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool cmp(Item a, Item b){
    return a.value/(a.weight*1.0)>b.value/(b.weight*1.0);
}

double fractionalKnapsack(int w, Item arr[], int n){
    sort(arr,arr+n,cmp);
    double sum=0.0;
    
    for(int i=0;i<n;i++){
        if(w-arr[i].weight>=0){
            sum+=arr[i].value;
            w-=arr[i].weight;
        //   cout<<sum<<" ";
        }
        else{
            sum+=w*(arr[i].value/(arr[i].weight*1.0));
            break;
        }
    }
    return sum;
}

