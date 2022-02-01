/*
Your Task:
Complete NumberOfPath() function which takes 2 arguments(A and B) and 
returns the number of unique paths from top-left to the bottom-right cell.

Link:
https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1/
*/

#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<int>> dp;
bool valid(int i, int j)
{
    return (i >= 1 && j >= 1 && i <= R && j <= C);
}
int solve(int i, int j)
{
    if (i == 1 && j == 1)
        return dp[i][j] = 1;
    if (dp[i][j] != 0)
        return dp[i][j];
    int ans = 0;
    if (valid(i - 1, j))
        ans += solve(i - 1, j);
    if (valid(i, j - 1))
        ans += solve(i, j - 1);
    return dp[i][j] = ans;
}
int NumberOfPath(int a, int b)
{
    // code here
    R = a, C = b;
    dp.resize(a + 1, vector<int>(b + 1, 0));
    solve(a, b);
    return dp[a][b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << "Output: " << NumberOfPath(15, 15);

    return 0;
}