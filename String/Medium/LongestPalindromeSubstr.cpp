#include <iostream>
#include <string>
using namespace std;
    
string longestPalin (string s) {
    // code here
    int n=s.size();
    int st=0, maxL=1;
    
    //for odd len of palindrome
    for(int i=0; i<n; i++){
        int l=i, r=i;
        while(l>=0 && r<n){
            if(s[l]!=s[r]) break;
            l--;
            r++;
        }
        int len=r-l-1;
        if(len>maxL){
            maxL=len;
            st=l+1;
        }
    }
    
    //for even len of palindrome
    for(int i=0; i<n; i++){
        int l=i, r=i+1;
        while(l>=0 && r<n){
            if(s[l]!=s[r]) break;
            l--;
            r++;
        }
        int len=r-l-1;
        if(len>maxL){
            maxL=len;
            st=l+1;
        }
    }
    
    return s.substr(st,maxL);
}