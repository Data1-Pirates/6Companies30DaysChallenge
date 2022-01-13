/*
Your task:
Given an integer array arr, return the length of the longest subarray, 
which is a mountain. Return 0 if there is no mountain subarray.

Link:
https://leetcode.com/problems/longest-mountain-in-array/
*/

#include <bits/stdc++.h>
using namespace std;

int longestMountain(vector<int> &arr)
{
    int n = arr.size();
    if (n < 3)
        return 0;
    int i = 0;
    int ans = 0;
    while (true)
    {
        while (i < n - 1 && arr[i] >= arr[i + 1])
            i++;
        if (i == n - 1)
            return ans;
        int l = i;
        while (l < n - 1 && arr[l + 1] > arr[l])
            l++;
        if (l < n - 1 && arr[l] == arr[l + 1])
        {
            i = l + 1;
            continue;
        }
        if (l == (n - 1))
        {
            return ans;
        }
        while (l < n - 1 && arr[l + 1] < arr[l])
            l++;
        if (l < n - 1 && arr[l] == arr[l + 1])
        {
            ans = max(ans, l - i + 1);
            i = l + 1;
            continue;
        }
        if (l == (n - 1))
        {
            if (arr[l] < arr[l - 1])
                ans = max(ans, l - i + 1);
            return ans;
        }
        ans = max(ans, l - i + 1);
        i = l;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {0, 0, 1, 0, 0, 1, 1, 1, 1, 1};
    cout << longestMountain(arr);

    return 0;
}