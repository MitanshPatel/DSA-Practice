#include<bits/stdc++.h>
using namespace std;

string sortByFrequency(int n, string& s)
{
	// Write Your Code here
	string ans = "";
    set<pair<int, char>> ch;

    // Sort the string to make charcaters together.
    sort(s.begin(), s.end());

    //to count frequency of 2 char, 2 pointer used
    for (int i = 0; i < n; i++){
        int j = i;
        while (j < n && s[i] == s[j]){   //count number of times it is repeated
            j++;
        }

        // Store frequency and character.
        ch.insert({-(j - i), s[i]});
        i = j - 1;       //update i to the prev of j.
    }

    for (auto it = ch.begin(); it != ch.end(); it++){
        // Concatenating it->first number of it->second character to string.
        ans += string(abs(it->first), it->second);   //to add char(it->second) frequency(it->first) number of times.
    }

    return ans;

    //MORE SPACE
    // vector<pair<int,char>> v;
	// map <char, int> mpp;
	// for(int i=0; i<n; i++){
	// 	mpp[s[i]]++;
	// }
	// for(auto i: mpp){
	// 	v.push_back({i.second, i.first});
	// }
	// sort(v.begin(), v.end());
	// string ans;
	// for(int i=v.size()-1; i>=0; i--){
	// 	while(v[i].first!=0){
	// 		ans+=v[i].second;
	// 		v[i].first--;
	// 	}
		
	// }
	// return ans;
}