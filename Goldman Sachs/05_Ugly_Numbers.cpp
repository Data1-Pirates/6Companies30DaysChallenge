/*
Your Task:
You don't need to read input or print anything.
Your task is to complete the function getNthUglyNo() which takes an integer n as parameters and
returns an integer denoting the answer.

Link:
https://www.google.com/url?q=https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/&sa=D&source=editors&ust=1641716809399000&usg=AOvVaw24_lsopwqM_n_3Brfl1lWy
*/

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull getNthUglyNo(int n)
{
    if (n == 1)
        return 1;
    ull i2 = 0, i3 = 0, i5 = 0;
    ull a = 2;
    ull b = 3;
    ull c = 5;
    ull ans = 1;
    vector<ull> mp(n);
    mp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        ans = min(a, min(b, c));
        mp[i] = ans;
        if (ans == a)
        {
            i2++;
            a = mp[i2] * 2;
        }
        if (ans == b)
        {
            i3++;
            b = mp[i3] * 3;
        }
        if (ans == c)
        {
            i5++;
            c = mp[i5] * 5;
        }
    }
    return mp[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 10;
    cout << "Output: " << getNthUglyNo(n);
    return 0;
}