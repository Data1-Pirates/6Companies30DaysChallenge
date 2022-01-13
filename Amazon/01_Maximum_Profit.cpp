/*
Your Task:
You do not need to read input or print anything. 
Your task is to complete the function maxProfit() which takes the values K, N and 
the array A[] as input parameters and returns the maximum profit.

Link:
https://practice.geeksforgeeks.org/problems/maximum-profit4657/1
*/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &price, int k)
{
    int n = price.size();
    vector<vector<int>> profit(k + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int max_so_far = 0;

            for (int m = 0; m < j; m++)
                max_so_far = max(max_so_far, price[j] - price[m] + profit[i - 1][m]);

            profit[i][j] = max(profit[i][j - 1], max_so_far);
        }
    }

    return profit[k][n - 1];
}

int main()
{
    int k = 2;
    vector<int> price = {10, 22, 5, 75, 65, 80};
    int n = sizeof(price) / sizeof(price[0]);

    cout << "Maximum profit is: " << maxProfit(price, k);

    return 0;
}