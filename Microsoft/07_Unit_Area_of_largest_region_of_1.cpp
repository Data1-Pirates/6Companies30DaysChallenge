/*
Your Task:
You don't need to read or print anyhting. 
Your task is to complete the function findMaxArea() which takes grid as input parameter and 
returns the area of the largest region of 1's.

Link:
https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/
*/

#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>

bool valid(vvi &arr, int r, int c, vvb &vis)
{
    int R = arr.size();
    int C = arr[0].size();
    return (r >= 0 && r < R && c >= 0 && c < C && arr[r][c] && !vis[r][c]);
}

void DFS(vvi &arr, int r, int c, vvb &vis, int &count)
{
    int rows[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int cols[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    vis[r][c] = true;
    for (int i = 0; i < 8; i++)
    {
        if (valid(arr, r + rows[i], c + cols[i], vis))
        {
            count++;
            DFS(arr, r + rows[i], c + cols[i], vis, count);
        }
    }
}

int findMaxArea(vector<vector<int>>& arr)
{
    int R = arr.size();
    int C = arr[0].size();
    vvb vis(R, vector<bool>(C, false));
    int result = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] && !vis[i][j])
            {
                int count = 1;
                DFS(arr, i, j, vis, count);
                result = max(result, count);
            }
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vvi arr = {{0, 0, 1, 1, 0},
               {1, 0, 1, 1, 0},
               {0, 1, 0, 0, 0},
               {0, 0, 0, 0, 1}};

    cout << findMaxArea(arr);

    return 0;
}