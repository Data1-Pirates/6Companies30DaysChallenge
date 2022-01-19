/*
Your Task:
You dont need to read input or print anything. 
Complete the function spirallyTraverse() that takes matrix, r and c as input parameters and 
returns a list of integers denoting the spiral traversal of matrix. 

Link:
https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> arr, int r, int c)
{
    vector<int> ans;
    // int r = arr.size(), c = arr[0].size();
    int i1 = 0, i2 = r - 1, j1 = 0, j2 = c - 1;
    while (i1 <= i2 && j1 <= j2)
    {
        for (int k = j1; k <= j2; k++)
            ans.push_back(arr[i1][k]);
        i1++;
        for (int k = i1; k <= i2; k++)
            ans.push_back(arr[k][j2]);
        j2--;
        if (i2 >= i1)
        {
            for (int k = j2; k >= j1; k--)
                ans.push_back(arr[i2][k]);
            i2--;
        }
        if (j1 <= j2)
        {
            for (int k = i2; k >= i1; k--)
                ans.push_back(arr[k][j1]);
            j1++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> arr{{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}};

    vector<int> ans = spirallyTraverse(arr, 4, 4);
    for (auto i : ans)
        cout << i << " ";

    return 0;
}