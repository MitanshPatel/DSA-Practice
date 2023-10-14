//find pow(N,R)

#include <bits/stdc++.h>
using namespace std;

long long power(int N,int R){
    if(R==1) return N;
    if(R==0) return 1;
    
    long long val=power(N,R/2);  //recursion
    val=(val*val);
    
    if(R%2==1) val=(val*N);  //if the power is odd
    
    return val;
}