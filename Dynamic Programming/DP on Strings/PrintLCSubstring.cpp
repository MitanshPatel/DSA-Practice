
#include <bits/stdc++.h>
using namespace std;

int commom_substring(string str, string frr)
{
    int n = str.length();
    int m = frr.length();
    int t[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
        t[i][0] = 0;
    for (int j = 0; j < m + 1; j++)
        t[0][j] = 0;

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < m + 1; ++j)
        {
            if (str[i - 1] == frr[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }
    int ans = INT_MIN;
    int iidx = -1;
    int jidx = -1;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (t[i][j] > ans)
            {
                ans = t[i][j];
                iidx = i;
                jidx = j;
            }
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    cout << iidx << " " << jidx << endl;
    string temp = "";
    while (iidx > 0 and jidx > 0)
    {
        if (t[iidx][jidx] == 0)
            break;
        temp += str[iidx - 1];
        iidx--;
        jidx--;
    }
    reverse(temp.begin(), temp.end());
    cout << temp << endl;
    return ans;
}

int main()
{
    string str;
    string frr;
    cin >> str >> frr;
    cout << commom_substring(str, frr);

    return 0;
}