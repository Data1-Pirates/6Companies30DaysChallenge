/*
Your Task:
You do not need to read input or print anything.
Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and
returns 1 if the partition is possible. Otherwise, returns 0.

Link:
https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
*/

#include <bits/stdc++.h>
using namespace std;

int equalPartition(int N, int arr[])
{
    // code here
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum % 2)
        return 0;
    vector<bool> pre(sum / 2 + 1, false);
    pre[0] = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = sum / 2; j >= arr[i]; j--)
        {
            if (j == arr[i] || pre[j - arr[i]])
                pre[j] = true;
            if (pre[sum / 2])
                return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << "Output: " << equalPartition(n, arr);
    return 0;
}