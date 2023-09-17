// The function takes a string(str) as argument and converts it to an integer and returns it.
//works for -12, --12.

#include<bits/stdc++.h>
using namespace std;
    
int atoi(string s) {
    //Your code here
    int ans=0;
    bool neg=false;
    if((s[0]-'0')>9) return -1;
    if((s[0]-'0')>=0) ans=s[0]-'0';
    else {
        neg=true;
    }
    int n=s.size();
    if(n==1) return ans;
    for(int i=1; i<n; i++){
        if(((s[i]-'0')>9) || ((s[i]-'0')<0)){
            return -1;
        }
        else{
            int d=s[i]-'0';
            ans=ans*10+d;
        }
    }
    if(neg) ans=ans*-1;
    return ans;
}