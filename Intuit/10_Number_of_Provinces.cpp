/*
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and
the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.

Link:
https://leetcode.com/problems/number-of-provinces/
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &arr, int node, vector<bool> &vis)
{
    vis[node] = true;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == node)
            continue;
        if (!vis[i] && arr[node][i])
            dfs(arr, i, vis);
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int ans = 0;
    int n = isConnected.size();
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            ans++;
            dfs(isConnected, i, vis);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> isConnected = {{1, 0, 0},
                                       {0, 1, 0},
                                       {0, 0, 1}};

    cout << "Output: " << findCircleNum(isConnected);

    return 0;
}