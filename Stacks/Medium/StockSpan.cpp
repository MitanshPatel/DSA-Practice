// The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day,
// for which the price of the stock on the current day is less than or equal to its price on the given day.

// Example 1:
// Input: 
// N = 7, price[] = [100 80 60 70 60 75 85]
// Output:
// 1 1 1 2 1 4 6
// Explanation:
// Traversing the given input span for 100 
// will be 1, 80 is smaller than 100 so the 
// span is 1, 60 is smaller than 80 so the 
// span is 1, 70 is greater than 60 so the 
// span is 2 and so on. Hence the output will 
// be 1 1 1 2 1 4 6.
#include <bits/stdc++.h>
using namespace std;

vector <int> calculateSpan(int price[], int n)
{
    // Your code here
    stack<pair<int, int>> st;
    vector<int> span(n, 1); 
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first <= price[i]) {
            span[i] += st.top().second; 
            st.pop(); 
        }
        st.push({price[i], span[i]}); 
    }
    
    return span;

}