/*
We are playing the Guessing Game. The game will work as follows:
I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

Link:
https://leetcode.com/problems/guess-number-higher-or-lower-ii
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(int start, int end)
{
    if (start >= end)
        return 0;
    if (dp[start][end] != INT_MAX)
        return dp[start][end];
    int res = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        int a = i;
        a += max(solve(start, i - 1), solve(i + 1, end));
        res = min(res, a);
    }
    return dp[start][end] = res;
}

int getMoneyAmount(int n)
{
    dp.resize(n + 1, vector<int>(n + 1, INT_MAX));
    return solve(1, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << "Output: " << getMoneyAmount(10);

    return 0;
}