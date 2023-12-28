// Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.

// Scrambled string: Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.
// Below is one possible representation of str = coder:
 
// To scramble the string, we may choose any non-leaf node and swap its two children. 
// Suppose, we choose the node co and swap its two children, it produces a scrambled string ocder.
// Similarly, if we continue to swap the children of nodes der and er, it produces a scrambled string ocred.

// Note: Scrambled string is not the same as an Anagram.

// Print "Yes" if S2 is a scrambled form of S1 otherwise print "No".

// Example 1:

// Input: S1="coder", S2="ocder"
// Output: Yes
// Explanation: ocder is a scrambled 
// form of coder.

//     ocder
//    /    \
//   oc    der
//  / \    
// o   c  

// As "ocder" can represent it 
// as a binary tree by partitioning 
// it into two non-empty substrings.
// We just have to swap 'o' and 'c' 
// to get "coder".

#include <bits/stdc++.h>
using namespace std;

//----------Recursive----------------
bool Solve(string X, string Y) {
	if (X.compare(Y) == 0)
		return true;
	if (X.length() <= 1)
		return false;

	int n = X.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++) {
		if ((Solve(X.substr(0, i), Y.substr(n - i, i)) && Solve(X.substr(i), Y.substr(0, n - i))) || // these are two condition for swapping and not swapping the string 
		        (Solve(X.substr(0, i), Y.substr(0, i)) && Solve(X.substr(i), Y.substr(i)))) {
			flag = true; // change the  flag to true and break 
			break;
		}
	}

	return flag;
}

//-----------Memoization---------------
unordered_map<string, int> ump;

bool Solve(string X, string Y) {
	string key = X + " " + Y;
	if (ump.find(key) != ump.end()) // if we did not found the and travesed upto end of the map 
		return ump[key];

	if (X.compare(Y) == 0) {
		ump[key] = true;
		return true;
	}
	if (X.length() <= 1) {
		ump[key] = false;
		return false;
	}

	int n = X.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++) {
		if ((Solve(X.substr(0, i), Y.substr(n - i, i)) && Solve(X.substr(i), Y.substr(0, n - i))) ||
		        (Solve(X.substr(0, i), Y.substr(0, i)) && Solve(X.substr(i), Y.substr(i)))) {
			flag = true;
			break;
		}
	}

	return ump[key] = flag; // store in table for further reference 
}

int main() {
	string X, Y; cin >> X >> Y;

	if (X.length() != Y.length())
		cout << "No\n";
	else
		Solve(X, Y) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}