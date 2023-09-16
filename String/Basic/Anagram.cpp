// Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not.
// An anagram of a string is another string that contains the same characters, only the order of characters can be different.
// For example, act and tac are an anagram of each other.

// Note:-
// If the strings are anagrams you have to return True or else return False
// |s| represents the length of string s.

// Example 1:
// Input:a = geeksforgeeks, b = forgeeksgeeks
// Output: YES
// Explanation: Both the string have same characters with
//         same frequency. So, both are anagrams.

#include <bits/stdc++.h>
using namespace std;

//hashing
bool isAnagram(string a, string b)
{
    // Your code here
    int n1 = a.size();
    int n2 = b.size();
    if (n1 != n2)
        return false;
    map<char, int> mpp;
    for (int i = 0; i < n1; i++)
    {
        mpp[a[i]]++;
    }
    for (int i = 0; i < n1; i++)
    {
        if (mpp.find(b[i]) == mpp.end())
        {
            return false;
        }
        else if (mpp[b[i]] == 0)
        {
            return false;
        }
        else
        {
            mpp[b[i]]--;
        }
    }
    return true;
}