/*
Your Task:  
You don't need to read input or print anything. 
Complete the function minDifference() which takes N and array arr as input parameters and returns the integer value

Link:
https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/
*/

#include <bits/stdc++.h>
using namespace std;

int minDifference(int v[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += v[i];
    int y = sum / 2 + 1;
    vector<bool> dp(y, false), dd(y, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + v[i] < y; j++)
        {
            if (dp[j])
            {
                dd[j + v[i]] = true;
            }
        }
        for (int j = 0; j < y; j++)
        {
            if (dd[j])
            {
                dp[j] = true;
                dd[j] = false;
            }
        }
    }
    for (int i = y - 1; i >= 0; i--)
    {
        if (dp[i])
            return (sum - 2 * i);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v[] = {1, 6, 11, 5};
    int n = sizeof(v) / sizeof(int);
    cout << minDifference(v, n);
    return 0;
}