/*
User Task:
The task is to complete the function calculateSpan() which takes two parameters, an array price[] denoting the price of stocks, and 
an integer N denoting the size of the array and number of days. This function finds the span of stock's price for all N days and 
returns an array of length N denoting the span for the i-th day.

Link:
https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr)
{
    stack<int> s;
    int n = arr.size();
    vector<int> ans(n);
    s.push(0);
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && arr[i] >= arr[s.top()])
            s.pop();
        if (s.empty())
            ans[i] = (i + 1);
        else
            ans[i] = i - s.top();
        s.push(i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = solve(arr);
    for (int i : ans)
        cout << i << " ";
    return 0;
}