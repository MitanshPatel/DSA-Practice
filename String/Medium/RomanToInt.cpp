#include<bits/stdc++.h>
using namespace std;

int romanToDecimal(string &str) {
    // code here
    int n=str.size();
    unordered_map<char,int> mp = {
        {'I',1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    
    int x=0;
    for(int i=0; i<n-1; i++){
        if( mp[str[i]] < mp[str[i+1]] ){    //in situation like IX (1<10)=9[-1+10] or CD(100<500)=400[-100+500] or IV 
            x-=mp[str[i]];
        }
        else{        //normally add
            x+=mp[str[i]];
        }
    }
    x+=mp[str[n-1]];
    return x;
}