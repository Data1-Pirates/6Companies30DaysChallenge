/*
Your Task:
You don't need to read input or print anything. 
The task is to complete the function subarraySum() which takes arr, N and S as input parameters and 
returns a list containing the starting and ending positions of the first such occurring subarray from the left where sum equals to S. 
The two indexes in the list should be according to 1-based indexing. If no such subarray is found, 
return an array consisting only one element that is -1.

Link:
https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, long long tar)
{
    vector<int> ans;
    int l = 0, r = 0;
    long long sum = arr[0];
    while (l < n && r < n)
    {
        if (sum < tar)
        {
            r++;
            sum += arr[r];
        }
        else if (sum > tar)
        {
            sum -= arr[l];
            l++;
        }
        else
        {
            ans.push_back(l + 1);
            ans.push_back(r + 1);
            break;
        }
    }
    if (ans.empty())
        ans.push_back(-1);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A[] = {1, 2, 3, 7, 5};
    int n = sizeof(A) / sizeof(int);
    long long tar = 12;

    vector<int> ans = subarraySum(A, n, tar);
    for (int i : ans)
        cout << i << " ";
    return 0;
}