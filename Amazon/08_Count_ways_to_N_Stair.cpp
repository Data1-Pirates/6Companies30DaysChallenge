/*
Your Task:
Your task is to complete the function countWays() which takes single argument(N) and returns the answer.

Link:
https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/
*/

#include <bits/stdc++.h>
using namespace std;

long long countWays(int m)
{
    // your code here
    long long ans = m / 2 + 1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << "Output: " << countWays(100);

    return 0;
}