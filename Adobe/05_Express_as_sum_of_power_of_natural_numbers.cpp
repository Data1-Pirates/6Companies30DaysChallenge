/*
Your Task:
You dont need to read input or print anything.
Complete the function numOfWays() which takes n and x as input parameter and
returns the total number of ways n can be expressed as sum of xth power of unique natural numbers.

Link:
https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1
*/

#include <bits/stdc++.h>
using namespace std;

unsigned long long int power(int n, int x)
{
    if (n == 0)
        return 0;
    if (x == 0)
        return 1;
    if (x == 1)
        return n;
    unsigned long long int ans = 1;
    while (x)
    {
        if (x & 1)
            ans *= n;
        x = x >> 1;
        n = n * n;
    }
    return ans;
}

int numOfWays(int n, int x)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    int MOD = 1e9 + 7;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            unsigned long long int y = power(i, x);
            if (j >= y)
            {
                dp[j] = (dp[j] + dp[j - y]) % MOD;
            }
        }
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << "Output: " << numOfWays(100, 2);

    return 0;
}