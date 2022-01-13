/*
Your Task:
You do not need to read input or print anything. 
Your task is to complete the function matrixChainOrder() which takes n and p[] as input parameters and 
returns the string with the proper order of parenthesis for n-1 matrices. Use uppercase alphabets to denote each matrix.

Link:
https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/
*/

#include <bits/stdc++.h>
using namespace std;

void printParenthesis(int i, int j, int n, int *bracket, char &name, string &ans)
{
    if (i == j)
    {
        string s(1, name);
        ans += s;
        name++;
        return;
    }
    ans += '(';
    printParenthesis(i, *((bracket + i * n) + j), n, bracket, name, ans);
    printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name, ans);
    ans += ')';
}

string matrixChainOrder(int p[], int n)
{
    int m[n][n];
    int bracket[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    string ans = "";
    char name = 'A';

    printParenthesis(1, n - 1, n, (int *)bracket, name, ans);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << matrixChainOrder(arr, n);

    return 0;
}