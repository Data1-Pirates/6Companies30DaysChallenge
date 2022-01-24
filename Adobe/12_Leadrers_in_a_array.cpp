/*
Your Task:
You don't need to read input or print anything. 
The task is to complete the function leader() which takes array A and n as input parameters and 
returns an array of leaders in order of their appearance.

Link:
https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int a[], int n)
{
    // Code here
    vector<int> l;
    int p = a[n - 1];
    l.push_back(p);
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= p)
        {
            p = a[i];
            l.push_back(p);
        }
    }
    reverse(l.begin(), l.end());
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(A) / sizeof(int);
    vector<int> ans = leaders(A, n);
    for (int i : ans)
        cout << i << " ";

    return 0;
}