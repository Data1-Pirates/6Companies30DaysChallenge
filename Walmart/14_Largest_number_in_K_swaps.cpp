/*
Your task:
You don't have to read input or print anything. 
Your task is to complete the function findMaximumNum() which takes the string and an integer as input and 
returns a string containing the largest number formed by perfoming the swap operation at most k times.

Link:
https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;

void solve(string &str, int k, string &ans, int i)
{
    if (k == 0)
        return;
    int n = str.length();
    char c = str[i];
    for (int j = i + 1; j < n; j++)
        if (c < str[j])
            c = str[j];
    if (c != str[i])
        k--;
    for (int j = n - 1; j >= i; j--)
    {
        if (str[j] == c)
        {
            swap(str[j], str[i]);
            if (str.compare(ans) > 0)
                ans = str;
            solve(str, k, ans, i + 1);
            swap(str[j], str[i]);
        }
    }
}

string findMaximumNum(string str, int k)
{
    // code here.
    string ans = str;
    solve(str, k, ans, 0);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "129814999";
    int k = 4;
    cout << "Output: " << findMaximumNum(str, k);

    return 0;
}