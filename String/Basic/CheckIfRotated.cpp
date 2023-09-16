// Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1. The characters in the strings are in lowercase.

// Example 1:
// Input:
// geeksforgeeks
// forgeeksgeeks
// Output:
// 1

#include <bits/stdc++.h>
using namespace std;

bool areRotations(string s1, string s2)
{
    // Your code here
    int n1 = s1.size();
    int n2 = s2.size();
    if (n1 != n2)
        return false;
    for (int i = 0; i < n2; i++)     //rotate for string length of time
    {
        char c = s2[0];     //take the first char
        s2 = s2 + c;        //add it to the end
        s2 = s2.substr(1, n2 + 1);    //take substring from 2nd el to last. to rotate it.
        if (s1 == s2)        //check for rotation
            return true;
    }
    return false;
}