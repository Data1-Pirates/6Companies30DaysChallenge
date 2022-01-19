/*
Your task:
You don’t need to read input or print anything. 
Your task is to complete the function isPossible() which takes the integer N denoting the number of tasks, 
P denoting the number of prerequisite pairs and prerequisite as input parameters and 
returns true if it is possible to finish all tasks otherwise returns false.

Link:
https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/
*/

#include <bits/stdc++.h>
using namespace std;
#define vus vector<unordered_set<int>>
#define vb vector<bool>

vus constGraph(int num, vector<pair<int, int>> &pre)
{
    vus ans(num);
    for (auto i : pre)
        ans[i.second].insert(i.first);
    return ans;
}

bool dfs_cycle(vus &graph, int node, vb &onpath, vb &vis)
{
    if (vis[node])
        return false;
    onpath[node] = vis[node] = true;
    for (auto i : graph[node])
        if (onpath[i] || dfs_cycle(graph, i, onpath, vis))
            return true;
    onpath[node] = false;
    return false;
}

bool isPossible(int num, vector<pair<int, int>> &prerequisites)
{
    // Code here
    vus graph = constGraph(num, prerequisites);
    vb onpath(num, false), vis(num, false);
    for (int i = 0; i < num; i++)
        if (!vis[i] && dfs_cycle(graph, i, onpath, vis))
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numTasks = 4;

    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 1));
    prerequisites.push_back(make_pair(3, 2));
    if (isPossible(numTasks, prerequisites))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}