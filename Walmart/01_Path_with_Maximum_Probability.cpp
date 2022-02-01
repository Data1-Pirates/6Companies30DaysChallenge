/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] 
is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
Given two nodes start and end, find the path with the maximum probability of success to go from start to end and 
return its success probability.
If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

Link:
https://leetcode.com/problems/path-with-maximum-probability/
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<pair<double, int>>> graph;

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    priority_queue<pair<double, int>> q;
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back({succProb[i], edges[i][1]});
        graph[edges[i][1]].push_back({succProb[i], edges[i][0]});
    }
    q.push({1, start});
    pair<double, int> temp;
    vector<double> maxProb(n + 1, 0);
    maxProb[start] = 1;
    while (!q.empty())
    {
        temp = q.top();
        q.pop();
        int node = temp.second;
        double prob = temp.first;
        if (node == end)
            return prob;
        for (auto &i : graph[node])
        {
            if (maxProb[i.second] < prob * i.first)
            {
                maxProb[i.second] = prob * i.first;
                q.push({maxProb[i.second], i.second});
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    int start = 0, end = 2;
    cout << "Output: " << maxProbability(n, edges, succProb, start, end);

    return 0;
}