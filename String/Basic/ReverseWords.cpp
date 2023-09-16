// Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

// Example 1:
// Input:
// S = i.like.this.program.very.much
// Output: much.very.program.this.like.i

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    // code here
    string ans;
    int prev = s.size() - 1;
    for (int i = s.size() - 1; i >= 0; i--)   //loop from behind
    {
        if (s[i] != '.')
            continue;
        else{
            ans += s.substr(i + 1, prev - (i));    //find the part from last . to first .
            ans += '.';
            prev = i - 1;
        }
    }
    ans += s.substr(0, prev + 1);
    return ans;
}