// Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
// Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
// Note: All occurrences of every character in str1 should map to the same character in str2

// Example 1:

// Input:
// str1 = aab
// str2 = xxy
// Output: 1
// Explanation: There are two different
// charactersin aab and xxy, i.e a and b
// with frequency 2and 1 respectively.
#include <bits/stdc++.h>
using namespace std;

bool areIsomorphic(string str1, string str2)
{
    // Your code here
    int n1 = str1.size();
    int n2 = str2.size();
    if (n1 != n2)
        return false;
    map<char, char> mpp;      //to store the mapping
    map<char, int> visit;    //if the char is already visited or not. to check for one to one mapping. 1->visited
    for (int i = 0; i < n1; i++)
    {
        if (mpp.find(str1[i]) == mpp.end())     //if map does not exist
        {
            if (visit[str2[i]] == 1)    // as it is visited, it cannot make more pairs. return false
            {
                return false;
            }
            mpp[str1[i]] = str2[i];
            visit[str2[i]] = 1;
        }

        if ((mpp[str1[i]] != str2[i]))     //if mapping is false
        {
            return false;
        }
    }
    return true;
}