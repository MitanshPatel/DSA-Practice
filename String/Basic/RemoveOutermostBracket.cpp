// s = "(()())(())"
// Output:
// "()()()"

#include <bits/stdc++.h>
using namespace std;


string removeOuter(string& s) {
        // code here
    string ans ="";
    int c = 0;
    for(int i = 0;i < s.length();i++) {
        if(s[i] == '(') {
            c++;       //increment for (
            if(c > 1) {    //put in answer only when '(' is not the first
                ans += s[i];
            }
        }else {
            if(c > 1){           //put in ans only when ) is not the last
                ans += s[i]; 
            }
            c--;    //decrement for ) to balance out and make pair
        }
    }
    return ans;
}