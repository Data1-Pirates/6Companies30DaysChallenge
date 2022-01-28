/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean.
Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that 
rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Link:
https://leetcode.com/problems/pacific-atlantic-water-flow/
*/

#include <bits/stdc++.h>
using namespace std;

bool valid(int R, int C, int i, int j)
{
    return (i >= 0 && i < R && j < C && j >= 0);
}
void pacific(vector<vector<int>> &heights, int R, int C, vector<vector<int>> &vis)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++)
    {
        q.push({i, 0});
        vis[i][0] = 1;
    }
    for (int j = 1; j < C; j++)
    {
        q.push({0, j});
        vis[0][j] = 1;
    }
    pair<int, int> temp;
    while (!q.empty())
    {
        temp = q.front();
        int x = temp.first, y = temp.second;
        q.pop();
        if (valid(R, C, x - 1, y) && vis[x - 1][y] == 0 && heights[x][y] <= heights[x - 1][y])
        {
            vis[x - 1][y] = 1;
            q.push({x - 1, y});
        }
        if (valid(R, C, x, y - 1) && vis[x][y - 1] == 0 && heights[x][y] <= heights[x][y - 1])
        {
            vis[x][y - 1] = 1;
            q.push({x, y - 1});
        }
        if (valid(R, C, x, y + 1) && vis[x][y + 1] == 0 && heights[x][y] <= heights[x][y + 1])
        {
            vis[x][y + 1] = 1;
            q.push({x, y + 1});
        }
        if (valid(R, C, x + 1, y) && vis[x + 1][y] == 0 && heights[x][y] <= heights[x + 1][y])
        {
            vis[x + 1][y] = 1;
            q.push({x + 1, y});
        }
    }
}
void atlantic(vector<vector<int>> &heights, int R, int C, vector<vector<int>> &vis)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++)
    {
        q.push({i, C - 1});
        vis[i][C - 1] += 2;
    }
    for (int j = 0; j < C - 1; j++)
    {
        q.push({R - 1, j});
        vis[R - 1][j] += 2;
    }
    pair<int, int> temp;
    while (!q.empty())
    {
        temp = q.front();
        int x = temp.first, y = temp.second;
        q.pop();
        if (valid(R, C, x - 1, y) && (vis[x - 1][y] == 0 || vis[x - 1][y] == 1) && heights[x][y] <= heights[x - 1][y])
        {
            q.push({x - 1, y});
            vis[x - 1][y] += 2;
        }
        if (valid(R, C, x, y - 1) && (vis[x][y - 1] == 0 || vis[x][y - 1] == 1) && heights[x][y] <= heights[x][y - 1])
        {
            q.push({x, y - 1});
            vis[x][y - 1] += 2;
        }
        if (valid(R, C, x, y + 1) && (vis[x][y + 1] == 0 || vis[x][y + 1] == 1) && heights[x][y] <= heights[x][y + 1])
        {
            q.push({x, y + 1});
            vis[x][y + 1] += 2;
        }
        if (valid(R, C, x + 1, y) && (vis[x + 1][y] == 0 || vis[x + 1][y] == 1) && heights[x][y] <= heights[x + 1][y])
        {
            q.push({x + 1, y});
            vis[x + 1][y] += 2;
        }
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int R = heights.size();
    int C = heights[0].size();
    vector<vector<int>> vis(R, vector<int>(C, 0));
    pacific(heights, R, C, vis);
    atlantic(heights, R, C, vis);
    vector<vector<int>> ans;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (vis[i][j] == 3)
            {
                vector<int> v;
                v.push_back(i);
                v.push_back(j);
                ans.push_back(v);
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> grid = {{1, 2, 2, 3, 5},
                                {3, 2, 3, 4, 4},
                                {2, 4, 5, 3, 1},
                                {6, 7, 1, 4, 5},
                                {5, 1, 1, 2, 4}};

    vector<vector<int>> ans = pacificAtlantic(grid);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}