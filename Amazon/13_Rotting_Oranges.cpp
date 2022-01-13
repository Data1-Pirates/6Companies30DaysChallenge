/*
Your task:
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Link:
https://leetcode.com/problems/rotting-oranges/
*/

#include <bits/stdc++.h>
using namespace std;

int R, C;
struct point
{
    int x, y;
};

bool valid_cell(int i, int j)
{
    return (i >= 0 && j >= 0 && i < R && j < C);
}

bool isDlm(point temp)
{
    return (temp.x == -1 && temp.y == -1);
}

bool check(vector<vector<int>> &grid)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            if (grid[i][j] == 1)
                return true;
    }
    return false;
}

int orangesRotting(vector<vector<int>> &grid)
{
    R = grid.size();
    C = grid[0].size();

    queue<point> que;
    point temp;
    int ans = 0;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == 2)
            {
                temp.x = i;
                temp.y = j;
                que.push(temp);
            }
        }
    }
    temp.x = -1;
    temp.y = -1;
    que.push(temp);

    while (!que.empty())
    {
        bool flag = false;
        while (!isDlm(que.front()))
        {
            temp = que.front();
            que.pop();
            if (valid_cell(temp.x + 1, temp.y) && grid[temp.x + 1][temp.y] == 1)
            {
                if (!flag)
                    ans++, flag = true;
                grid[temp.x + 1][temp.y] = 2;
                temp.x++;
                que.push(temp);
                temp.x--;
            }
            if (valid_cell(temp.x - 1, temp.y) && grid[temp.x - 1][temp.y] == 1)
            {
                if (!flag)
                    ans++, flag = true;
                grid[temp.x - 1][temp.y] = 2;
                temp.x--;
                que.push(temp);
                temp.x++;
            }
            if (valid_cell(temp.x, temp.y + 1) && grid[temp.x][temp.y + 1] == 1)
            {
                if (!flag)
                    ans++, flag = true;
                grid[temp.x][temp.y + 1] = 2;
                temp.y++;
                que.push(temp);
                temp.y--;
            }
            if (valid_cell(temp.x, temp.y - 1) && grid[temp.x][temp.y - 1] == 1)
            {
                if (!flag)
                    ans++, flag = true;
                grid[temp.x][temp.y - 1] = 2;
                temp.y--;
                que.push(temp);
                temp.y++;
            }
        }
        temp = que.front();
        que.pop();
        if (!que.empty())
            que.push(temp);
    }
    return (check(grid)) ? -1 : ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> grid = {{2, 1, 0, 2, 1}, {1, 0, 1, 2, 1}, {1, 0, 0, 2, 1}};

    cout << "Output: " << orangesRotting(grid);

    return 0;
}