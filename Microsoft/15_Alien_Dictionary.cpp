/*
Your Task:
You don't need to read or print anything. 
Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and 
returns a string denoting the order of characters in the alien language.

Link:
https://practice.geeksforgeeks.org/problems/alien-dictionary/1/
*/

#include <bits/stdc++.h>
using namespace std;

void topologicalSort(int node, unordered_map<int,vector<int>>&adj, vector<bool> &vis, stack<int> &s)
{
    vis[node] = true;
    for (auto i = adj[node].begin(); i != adj[node].end(); ++i)
        if (!vis[*i])
            topologicalSort(*i, adj, vis, s);
    s.push(node);
}

string findOrder(string dict[], int n, int k)
{
    // code here
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n - 1; i++)
    {
        string str1 = dict[i], str2 = dict[i + 1];
        for (int j = 0; j < min(str1.length(), str2.length()); j++)
        {
            if (str1[j] != str2[j])
            {
                adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                break;
            }
        }
    }
    string ans;
    vector<bool> vis(k, false);
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        if (!vis[i])
            topologicalSort(i, adj, vis, s);
    }
    while (!s.empty())
    {
        ans += (s.top()+'a');
        s.pop();
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    cout << findOrder(dict, 5, 4);

    return 0;
}