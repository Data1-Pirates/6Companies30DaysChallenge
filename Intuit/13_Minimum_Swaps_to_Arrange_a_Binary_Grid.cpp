/*
Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
A grid is said to be valid if all the cells above the main diagonal are zeros.
Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

Link:
https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid
*/

#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &index, int i, int j)
{
    int temp = index[i];
    index[i] = index[j];
    index[j] = temp;
}

int minSwaps(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<int> index(n);
    int i, j, k, l;
    for (i = 0; i < n; i++)
    {
        k = 0;
        for (j = n - 1; j >= 0; j--)
        {
            if (grid[i][j] == 0)
            {
                k++;
            }
            else
            {
                break;
            }
        }
        index[i] = k;
    }
    int ans = 0;
    for (i = 0; i < n; i++)
    {
        j = n - 1 - i;
        for (k = i; k < n; k++)
        {
            if (index[k] >= j)
            {
                break;
            }
        }
        if (k == n)
        {
            return -1;
        }
        else
        {
            for (l = k; l > i; l--)
            {
                swap(index, l, l - 1);
            }
            ans += k - i;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> grid = {{0, 0, 1},
                                {1, 1, 0},
                                {1, 0, 0}};

    cout << "Output: " << minSwaps(grid);

    return 0;
}