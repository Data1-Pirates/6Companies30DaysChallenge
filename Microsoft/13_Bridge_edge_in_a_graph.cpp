
/*
Your Task:
You don't need to read input or print anything. 
Your task is to complete the function isBridge()  which takes number of vertices V, the number of edges E, an adjacency lsit adj and 
two integers c and d denoting the edge as input parameters and returns 1 if the given edge c-d is a Bridge. Else, it returns 0.

Link:
https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!vis[adj[node][i]])
            dfs(adj[node][i], adj, vis);
    }
}

int isBridge(int V, vector<int> adj[], int c, int d)
{
    // Code here
    for (int i = 0; i < adj[c].size(); i++)
        if (adj[c][i] == d)
        {
            adj[c].erase(adj[c].begin() + i);
            break;
        }
    for (int i = 0; i < adj[d].size(); i++)
        if (adj[d][i] == c)
        {
            adj[d].erase(adj[d].begin() + i);
            break;
        }
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis);
            if (vis[c] && vis[d])
                return false;
            if (vis[c])
                return true;
            if (vis[d])
                return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V = 5, c = 0, d = 2;
    vector<int> adj[] = {
        {1, 2, 3}, {0, 2}, {0, 1}, {0, 4}, {3}};

    cout << "Output: " << isBridge(V, adj, c, d);

    return 0;
}