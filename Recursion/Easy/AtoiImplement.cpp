//string to integer conversion

#include <bits/stdc++.h>
#include<string>
using namespace std;


int computeAtoi(string &s, bool isNeg, long ans, int idx, int len){
    // base cases
    if (idx == len){
        return isNeg ? ans * (-1) : ans; // at end return
    }

    if (ans >= INT_MAX - 1 && isNeg)
        return INT_MIN; // reaches INT_MIN

    if (ans >= INT_MAX)
        return INT_MAX; // reaches INT_MAX

    if (s[idx] == '-' && s[idx + 1] == '+')
        return 0; // alternate symbols

    if (s[idx + 1] == '-' && s[idx] == '+')
        return 0; // alternate symbols

    // getting num from 0 - 9
    if (s[idx] - '0' >= 0 && s[idx] - '0' <= 9){
        ans = ans * 10 + s[idx] - '0';
    }

    // any other charcter encountered other than ' ', '-' , '+' return

    else if (s[idx] != ' ' && s[idx] != '-' && s[idx] != '+'){
        return isNeg ? ans * (-1) : ans;
    }

    // flag for -ve value
    if (s[idx] == '-')
        isNeg = true;

    // compute for next index
    computeAtoi(s, isNeg, ans, idx + 1, len);
}

int createAtoi(string s){
    // Write your code here.
    return computeAtoi(s, false, 0, 0, s.length());
}