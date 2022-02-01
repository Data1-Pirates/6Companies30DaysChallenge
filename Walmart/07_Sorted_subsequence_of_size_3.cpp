/*
Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k.

Link:
https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> find3Numbers(vector<int> arr, int N)
{
    // Your code here
    vector<int> ans;
    if (N < 3)
        return ans;
    int min_num = arr[0];
    int num1 = min_num;
    int num2 = INT_MAX;
    for (int i = 1; i < N; i++)
    {
        if (arr[i] == min_num)
            continue;
        else if (arr[i] < min_num)
        {
            min_num = arr[i];
            continue;
        }
        else if (arr[i] == num2)
            continue;
        else if (arr[i] < num2)
        {
            num2 = arr[i];
            num1 = min_num;
        }
        else
        {
            ans.push_back(num1);
            ans.push_back(num2);
            ans.push_back(arr[i]);
            return ans;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {1, 2, 1, 1, 3};
    vector<int> ans = find3Numbers(arr, 5);
    for (int i : ans)
        cout << i << " ";

    return 0;
}