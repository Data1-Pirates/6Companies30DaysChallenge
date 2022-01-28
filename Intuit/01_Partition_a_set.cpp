/*
Your task:
Given a set of integers, the task is to divide it into two sets S1 and S2 
such that the absolute difference between their sums is minimum. 

Link:
https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    int n = arr.size();
    long long int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int y = sum / 2;
    vector<bool> dp(y + 1, false);
    vector<bool> dd(y + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + arr[i] <= y; j++)
        {
            if (dp[j])
                dd[j + arr[i]] = true;
        }
        for (int j = 0; j <= y; j++)
        {
            if (dd[j])
            {
                dp[j] = true;
                dd[j] = false;
            }
        }
    }
    int ans = 0;
    for (int i = sum; i >= 0; i--)
        if (dp[i])
        {
            ans = sum - 2 * i;
            break;
        }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {1, 6, 11, 5};
    cout << "Output: " << solve(arr);

    return 0;
}