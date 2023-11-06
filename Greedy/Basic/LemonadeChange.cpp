// You are an owner of lemonade island, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by given array bills[]). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

// NOTE: At first, you do not have any bill to provide changes with. You can provide changes from the bills that you get from the previous customers.
// Given an integer array bills of size N where bills [ i ] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

// Example 1:

// Input:
// N = 5
// bills [ ] = {5, 5, 5, 10, 20}
// Output: True
// Explanation: 
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change we return true.

#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(int n, vector<int> &bills) {
    // code here
    int five=0,ten=0;
    for(int i=0;i<n;i++){
        if(bills[i]==20){
            if(ten && five){
                ten--;
                five--;
            }
            else if(five>=3){
                five-=3;
            }
            else return false;
        }
        else if(bills[i]==10){
            ten++;
            if(five)five--;
            else return false;
        }
        else five++;
    }
    return true;
}