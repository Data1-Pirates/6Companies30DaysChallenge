/*
Your Task:  
You don't need to read input or print anything. 
Complete the function max_of_subarrays() which takes the array, N, and K as input parameters and 
returns a list of integers denoting the maximum of every contiguous subarray of size K.

Link:
https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(vector<int> arr, int n, int k)
{
    // your code here
    stack<int> st;
    vector<int> v;
    st.push(0);
    int l = 0, r = 0;
    vector<int> ans;
    deque<int> q;
    for (; r < k; r++)
    {
        while (!q.empty() && arr[r] >= arr[q.back()])
            q.pop_back();
        q.push_back(r);
    }
    ans.push_back(arr[q.front()]);
    while (r < n)
    {
        l++;
        while (!q.empty() && q.front() < l)
            q.pop_front();
        while (!q.empty() && arr[r] >= arr[q.back()])
            q.pop_back();
        q.push_back(r);
        ans.push_back(arr[q.front()]);
        r++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = 9;
    int k = 3;
    vector<int> ans = max_of_subarrays(arr, n, k);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}