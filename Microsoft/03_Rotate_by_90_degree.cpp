/*
Your Task:
You only need to implement the given function rotate(). 
Do not read input, instead use the arguments given in the function. 
Given a square matrix[][] of size N x N. 
The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.

Link:
https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/
*/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &arr, int n)
{
    for (int i = 0; i <= n / 2 - 1; i++)
    {
        for (int j = i; j + i < n - 1; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][n - 1 - i];
            arr[j][n - 1 - i] = arr[n - 1 - i][n - 1 - j];
            arr[n - 1 - i][n - 1 - j] = arr[n - 1 - j][i];
            arr[n - 1 - j][i] = temp;
        }
    }
}

void display(vector<vector<int>> &arr)
{
    for (auto i : arr)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> v = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16}};

    display(v);
    int n = v.size();
    rotate(v, n);
    display(v);
    return 0;
}