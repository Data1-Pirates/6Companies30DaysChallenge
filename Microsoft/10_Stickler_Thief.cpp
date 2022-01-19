/*
Your Task:
Complete the functionFindMaxSum()which takes an array arr[] and n as input which
returns the maximum money he can get following the rules

Link:
https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/
*/

#include <bits/stdc++.h>
using namespace std;

int FindMaxSum(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];
    if (n == 2)
        return max(arr[0], arr[1]);
    int v1 = arr[0];
    int v2 = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        int ans = max(v1 + arr[i], v2);
        v1 = v2;
        v2 = ans;
    }
    return v2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {5, 5, 10, 100, 10, 5};
    cout << "Maximum loot possible : " << FindMaxSum(arr);

    return 0;
}