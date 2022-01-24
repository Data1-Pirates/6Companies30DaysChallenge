/*
Your Task:
You don't need to read input or print anything.
Your task is to complete the function lenghtOfLongestAP() which takes the array of integers called set[]
and n as input parameters and returns the length of LLAP.

Link:
https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/
*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestAP(int A[], int n)
{
    // code here
    if (n <= 2)
        return n;
    vector<vector<int>> dp(n, vector<int>(n, 2));
    int ans = 2;
    for (int j = n - 2; j >= 1; j--)
    {
        int i = j - 1, k = j + 1;
        while (i >= 0 && k < n)
        {
            if (A[i] + A[k] > 2 * A[j])
                i--;
            else if (A[i] + A[k] < 2 * A[j])
                k++;
            else
            {
                dp[i][j] = max(dp[j][k] + 1, dp[i][j]);
                ans = max(ans, dp[i][j]);
                i--;
                k++;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A[] = {1, 7, 10, 13, 14, 19};
    int n = sizeof(A) / sizeof(int);
    cout << "Output: " << lengthOfLongestAP(A, n);

    return 0;
}