/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi]
indicates that you must take course bi first if you want to take course ai.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them.
If it is impossible to finish all courses, return an empty array.

Link:
https://leetcode.com/problems/course-schedule-ii/
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int node, vector<int> &ans, vector<bool> &vis, vector<bool> &pre, unordered_map<int, vector<int>> &graph, bool &flag)
{
    vis[node] = true;
    for (auto i : graph[node])
    {
        if (!pre[i] && !vis[i])
            solve(i, ans, vis, pre, graph, flag);
        if (vis[i])
        {
            flag = false;
            return;
        }
        if (!flag)
            return;
    }
    ans.push_back(node);
    pre[node] = true;
    vis[node] = false;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    vector<int> ans;
    vector<bool> vis(numCourses, false);
    vector<bool> pre(numCourses, false);
    bool flag = true;
    for (auto i : graph)
    {
        if (!pre[i.first])
            solve(i.first, ans, vis, pre, graph, flag);
    }
    if (!flag)
    {
        vector<int> v;
        return v;
    }
    for (int i = 0; i < numCourses; i++)
    {
        if (!pre[i])
            ans.push_back(i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> ans = findOrder(numCourses, prerequisites);

    for (auto i : ans)
        cout << i << " ";

    return 0;
}