#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
        return dp[i][j] = A[i];
    if (dp[i][j] != -1)
        return dp[i][j];
    int l = A[i] + min(solve(A, i + 2, j, dp), solve(A, i + 1, j - 1, dp));
    int r = A[j] + min(solve(A, i + 1, j - 1, dp), solve(A, i, j - 2, dp));
    dp[i][j] = max(l, r);
    return dp[i][j];
}

int maxCoins(vector<int> &A, int n)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(A, 0, n - 1, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> A = {8, 15, 3, 7};
    int n = A.size();
    cout << "Output: " << maxCoins(A, n);
    return 0;
}