/*
Given an array nums which consists of non-negative integers and an integer m, 
you can split the array into m non-empty continuous subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.

Link:
https://leetcode.com/problems/split-array-largest-sum/
*/

#include <bits/stdc++.h>
using namespace std;

int splitArray(vector<int> &nums, int m)
{
    int n = nums.size();
    int sum = 0;
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        g = max(g, nums[i]);
    }
    int low = g, high = sum;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int s1 = 0, p = 1;
        for (int i = 0; i < n; i++)
        {
            s1 += nums[i];
            if (s1 > mid)
            {
                p++;
                s1 = nums[i];
            }
        }
        if (p <= m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {7, 2, 5, 10, 8};
    int m = 2;
    cout << "Output: " << splitArray(arr, m);

    return 0;
}