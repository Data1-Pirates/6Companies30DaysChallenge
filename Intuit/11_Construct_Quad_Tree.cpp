/*
Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.
Return the root of the Quad-Tree representing the grid.

Link:
https://leetcode.com/problems/construct-quad-tree/
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node *rec_construct(vector<vector<int>> &grid, int row_start, int row_end, int col_start, int col_end, int factor)
{
    int sum = 0;
    for (int i = row_start; i < row_end; i++)
    {
        for (int j = col_start; j < col_end; j++)
        {
            sum += grid[i][j];
        }
    }
    Node *ans;
    if (sum == 0)
        ans = new Node(false, true);
    else if (sum == (factor * factor))
        ans = new Node(true, true);
    else
    {
        ans = new Node(false, false);
        factor = factor / 2;
        ans->topLeft = rec_construct(grid, row_start, row_start + factor, col_start, col_start + factor, factor);
        ans->topRight = rec_construct(grid, row_start, row_start + factor, col_start + factor, col_end, factor);
        ans->bottomLeft = rec_construct(grid, row_start + factor, row_end, col_start, col_start + factor, factor);
        ans->bottomRight = rec_construct(grid, row_start + factor, row_end, col_start + factor, col_end, factor);
    }
    return ans;
}
Node *construct(vector<vector<int>> &grid)
{
    int n = grid.size();
    Node *ans = rec_construct(grid, 0, n, 0, n, n);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> grid = {{0, 1}, {1, 0}};
    Node*head = construct(grid);

    return 0;
}