/*
Given a number and its reverse. Find that number raised to the power of its own reverse.

Link:
https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/?company[]=Walmart&company[]=Walmart&page=1&query=company[]Walmartpage1company[]Walmart
*/

#include <bits/stdc++.h>
using namespace std;

long long power(int N, int R)
{
    // Your code here
    int Mod = 1e9 + 7;
    if (N == 1)
        return 1;
    long long int ans = 1;
    long long int n = N;
    while (R)
    {
        if (R & 1)
        {
            ans *= n;
            ans %= Mod;
        }
        R >>= 1;
        n *= n;
        n %= Mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << "Output: " << power(361, 163);

    return 0;
}