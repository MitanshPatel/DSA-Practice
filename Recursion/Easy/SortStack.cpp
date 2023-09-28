#include <bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};
/* The below method sorts the stack s 
you are required to complete the below method */

void insert(stack<int> &s, int z){
    if(s.size()==0 || s.top()<=z){
        s.push(z);
        return;
    }
    int t=s.top();
    s.pop();
    insert(s, z);
    s.push(t);
    return;
}

void SortedStack :: sort(){
   //Your code here
   if(s.size()==0) return;
   int z=s.top();
   s.pop();
   SortedStack :: sort();
   insert(s, z);
   return;
}