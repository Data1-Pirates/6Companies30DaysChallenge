/*
Given an array of positive integers nums and a positive integer target,
return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or
equal to target. If there is no such subarray, return 0 instead.

https://www.google.com/url?q=https://leetcode.com/problems/minimum-size-subarray-sum/&sa=D&source=editors&ust=1641716809409000&usg=AOvVaw2QvFJyfygycEufrzDzhLDL
*/

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int ans = 100001;
    int l = 0, r = 0, n = nums.size();
    int sum = 0;
    while (r < n && l <= r)
    {
        sum += nums[r];
        while (l <= r && sum >= target)
        {
            if (l == r)
                return 1;
            ans = min(ans, r - l + 1);
            sum -= nums[l];
            l++;
        }
        r++;
    }
    if (ans == 100001)
        return 0;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << "Ans: " << minSubArrayLen(target, nums);

    return 0;
}