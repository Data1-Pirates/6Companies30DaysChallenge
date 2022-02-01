/*
You are given an array of strings nums and an integer k. 
Each string in nums represents an integer without leading zeros.
Return the string that represents the kth largest integer in nums.

Link:
https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> arrSize;
static bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > b.first;
}

void solve(vector<string> &nums, int l, int r, int len)
{
    l++, r--;
    for (int i = len - 1; i >= 0; i--)
    {
        vector<vector<int>> dp(10);
        for (int j = l; j <= r; j++)
        {
            dp[nums[arrSize[j].second][i] - '0'].push_back(arrSize[j].second);
        }
        int j = l;
        for (int k = 9; k >= 0; k--)
        {
            for (int m = 0; m < dp[k].size(); m++)
            {
                arrSize[j].second = dp[k][m];
                j++;
            }
        }
    }
}

string kthLargestNumber(vector<string> &nums, int k)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
        arrSize.push_back({nums[i].size(), i});
    sort(arrSize.begin(), arrSize.end(), compare);

    int len = arrSize[k - 1].first;
    int l = k - 1, r = k - 1;
    while (l >= 0 && arrSize[l].first == len)
        l--;
    while (r < n && arrSize[r].first == len)
        r++;
    solve(nums, l, r, len);
    return nums[arrSize[k - 1].second];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> nums = {"623", "521", "2", "42"};
    cout << "Output: " << kthLargestNumber(nums, 2);

    return 0;
}