// Given an array of N strings, find the longest common prefix among all strings present in the array.

// Example 1:
// Input:
// N = 4
// arr[] = {geeksforgeeks, geeks, geek,
//          geezer}
// Output: gee
// Explanation: "gee" is the longest common
// prefix in all the given strings.

#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        int minilen=INT_MAX;
        for(int i=0; i<n; i++){          //to find the minimum length from all given strings
            if(minilen>arr[i].length()){
                minilen=arr[i].length();
            }
        }
        string res;
        for(int i=0; i<minilen; i++){
            char c=arr[0][i];      //take the char from the 1st string
            for(int j=1; j<n; j++){     //iterate thru all the array and check if char matches all
                if(c != arr[j][i]){  //if not matches return
                    if(res=="") return "-1";
                    return res;
                }
            }
            res+=c;   //else start to add the prefix
        }
        return res;
    }