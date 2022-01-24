/*
Your Task:  
You don't need to read input or print anything. 
Your task is to complete the function kvowelwords() which takes an Integer N, an intege K and 
returns the total number of words of size N with atmost K vowels. As the answer maybe to large please return answer modulo 1000000007.

Link:
https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1/
*/

#include <bits/stdc++.h>
using namespace std;

long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1ll;
    x = x % p;

    if (x == 0)
        return 0;

    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int kvowelwords(int N, int K)
{
    // Write Your Code here
    long long int i, j;
    long long int MOD = 1000000007;
    long long int dp[N + 1][K + 1] = {0};
    long long int sum = 1;
    for (i = 1; i <= N; i++)
    {
        dp[i][0] = sum * 21;
        dp[i][0] %= MOD;
        sum = dp[i][0];
        for (j = 1; j <= K; j++)
        {
            if (j > i)
                dp[i][j] = 0;
            else if (j == i)
            {
                dp[i][j] = power(5ll, i, MOD);
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] * 5;
            }
            dp[i][j] %= MOD;
            sum += dp[i][j];
            sum %= MOD;
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}