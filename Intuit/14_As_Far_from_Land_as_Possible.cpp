/*
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, 
find a water cell such that its distance to the nearest land cell is maximized, and 
return the distance. If no land or water exists in the grid, return -1.
The distance used in this problem is the Manhattan distance: 
the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

Link:
https://leetcode.com/problems/as-far-from-land-as-possible/
*/

#include <bits/stdc++.h>
using namespace std;

int n;
queue<pair<int, int>> q;

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j < n && j >= 0);
}

int maxDistance(vector<vector<int>> &grid)
{
    n = grid.size();
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                one++;
                q.push({i, j});
            }
        }
    }
    if (one == n * n || one == 0)
        return -1;
    int ans = 0;

    while (!q.empty())
    {
        int qsize = q.size();
        ans++;
        pair<int, int> temp;
        while (qsize--)
        {
            temp = q.front();
            q.pop();
            int x = temp.first, y = temp.second;
            if (valid(x - 1, y) && !grid[x - 1][y])
            {
                q.push({x - 1, y});
                grid[x - 1][y] = 1;
            }
            if (valid(x, y - 1) && !grid[x][y - 1])
            {
                q.push({x, y - 1});
                grid[x][y - 1] = 1;
            }
            if (valid(x, y + 1) && !grid[x][y + 1])
            {
                q.push({x, y + 1});
                grid[x][y + 1] = 1;
            }
            if (valid(x + 1, y) && !grid[x + 1][y])
            {
                q.push({x + 1, y});
                grid[x + 1][y] = 1;
            }
        }
    }
    return ans - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> grid = {{1, 0, 0},
                                {0, 0, 0},
                                {1, 0, 1}};

    cout << "Output: " << maxDistance(grid);
    return 0;
}