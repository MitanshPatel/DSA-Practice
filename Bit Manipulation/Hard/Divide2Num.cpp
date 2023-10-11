// Given two integers dividend and divisor. Find the quotient after dividing dividend by divisor without using 
// multiplication, division and mod operator.

#include <bits/stdc++.h>
using namespace std;

long long divide(long long dividend, long long divisor) {
    //code here
    long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    while (dvd >= dvs) {
        long temp = dvs, m = 1;
        while ((temp << 1) <= dvd) {
            temp = temp<<1;
            m = m<<1;
        }
        dvd -= temp;
        ans += m;
    }
    return sign * ans;
}