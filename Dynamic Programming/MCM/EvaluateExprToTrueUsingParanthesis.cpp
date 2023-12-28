// Given a boolean expression S of length N with following symbols.
// Symbols
//     'T' ---> true
//     'F' ---> false
// and following operators filled between symbols
// Operators
//     &   ---> boolean AND
//     |   ---> boolean OR
//     ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true

// Example 1:
// Input: N = 7
// S = T|T&F^T
// Output: 4
// Explaination: The expression evaluates 
// to true in 4 ways ((T|T)&(F^T)), 
// (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

#include <bits/stdc++.h>
using namespace std;

//----------------Recursive-----------------
int Solve(string X, int i, int j, bool isTrue) {
	if (i >= j) {
		if (isTrue)
			return X[i] == 'T';
		else
			return X[i] == 'F';
	}

	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {
		int l_T = Solve(X, i, k - 1, true);
		int l_F = Solve(X, i, k - 1, false);
		int r_T = Solve(X, k + 1, j, true);
		int r_F = Solve(X, k + 1, j, false);

		if (X[k] == '|') {
			if (isTrue == true)
				ans += l_T * r_T + l_T * r_F + l_F * r_T;
			else
				ans += l_F * r_F;
		}
		else if (X[k] == '&') {
			if (isTrue == true)
				ans += l_T * r_T;
			else
				ans += l_T * r_F + l_F * r_T + l_F * r_F;
		}
		else if (X[k] == '^') {
			if (isTrue == true)
				ans += l_T * r_F + l_F * r_T;
			else
				ans += l_T * r_T + l_F * r_F;
		}

	}

	return ans;
}

//--------------Memoization (Using Map)---------------
unordered_map<string, int> ump;

int Solve(string X, int i, int j, bool isTrue) {
	string key = to_string(i) + " " + to_string(j) + " " + (isTrue ? "T" : "F");

	if (ump.find(key) != ump.end())
		return ump[key];

	if (i >= j) {
		if (isTrue)
			ump[key] = X[i] == 'T';
		else
			ump[key] = X[i] == 'F';
		return ump[key];
	}

	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {
		int l_T = Solve(X, i, k - 1, true);
		int l_F = Solve(X, i, k - 1, false);
		int r_T = Solve(X, k + 1, j, true);
		int r_F = Solve(X, k + 1, j, false);

		if (X[k] == '|') {
			if (isTrue == true)
				ans += l_T * r_T + l_T * r_F + l_F * r_T;
			else
				ans += l_F * r_F;
		}
		else if (X[k] == '&') {
			if (isTrue == true)
				ans += l_T * r_T;
			else
				ans += l_T * r_F + l_F * r_T + l_F * r_F;
		}
		else if (X[k] == '^') {
			if (isTrue == true)
				ans += l_T * r_F + l_F * r_T;
			else
				ans += l_T * r_T + l_F * r_F;
		}

	}

	return ump[key] = ans;
}

//----------Memoization (matrix)-----------
int t[201][201][2];
int solve(string &s, int i, int j,bool state){
    if(i>j){
        return 0;
    }
    if(t[i][j][state]!=-1){
        return t[i][j][state];
    }
    if(i==j){
        if(state==true){
            return s[i]=='T';
        }
        else{
            return s[i]=='F';
        }
    }
    
    int count=0;
    for(int k=i+1;k<j;k+=2){
        
        int lt=solve(s,i,k-1,true);
        int lf=solve(s,i,k-1,false);
        int rt=solve(s,k+1,j,true);
        int rf=solve(s,k+1,j,false);
        
        if(s[k]=='&'){
            if(state==true){
                count+=lt*rt;
            }
            else{
                count+=lf*rf+lf*rt+lt*rf;
            }
        }
        
        else if(s[k]=='|'){
            if(state==true){
                count+=lt*rt+lt*rf+lf*rt;
            }
            else{
                count+=lf*rf;
            }
        }
        
        else if(s[k]=='^'){
            if(state==true){
                count+=lt*rf+lf*rt;
            }
            else{
                count+=lt*rt+lf*rf;
            }
        }
        
    }
    
    return  t[i][j][state]=count%1003;
}

//----------------Tabulation (Bottom Up)--------------
#define ll long long 
int countWays(int n, string S){
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, 0)));
        
        for(int i=0; i<n; i++){
            dp[i][i][1] = (S[i] == 'T');
            dp[i][i][0] = (S[i] == 'F');
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                for(int isTrue=0; isTrue <=1; isTrue++){
                    ll ans=0;
                    for(int ind =i+1; ind <= j-1; ind=ind+2){
                        ll LT = dp[i][ind-1][1];
                        ll LF = dp[i][ind-1][0];
                        ll RT = dp[ind+1][j][1];
                        ll RF = dp[ind+1][j][0];
                        if(S[ind] == '&'){
                            if(isTrue) ans = (ans + (LT * RT));
                            else ans = (ans + (LT*RF) + (LF*RF) + (LF*RT));
                        }
                        else if(S[ind] == '|'){
                            if(isTrue) ans = (ans + (LT*RT) + (LT*RF) + (LF*RT));
                            else ans = (ans + (LF*RF));
                        }
                        else{
                            if(isTrue) ans = (ans + (LT*RF) + (LF*RT));
                            else ans = (ans + (LT*RT) + (LF*RF));
                        }
                    }
                    dp[i][j][isTrue] = ans;
                }
            }
        }
        return dp[0][n-1][1];
    }

int main() {
	string X; cin >> X;
	cout << Solve(X, 0, X.length() - 1, true) << endl;
	return 0;
}