/*
Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, 
and each pile has a positive integer number of stones piles[i].
The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.
Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones 
either from the beginning or from the end of the row. This continues until there are no more piles left, 
at which point the person with the most stones wins.
Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

Link:
https://leetcode.com/problems/stone-game
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(vector<int> &piles, int s, int e)
{
    if (s > e)
        return 0;
    if (dp[s][e] != -1)
        return dp[s][e];
    if (s == e)
        return dp[s][e] = piles[s];
    int l = piles[s] + min(solve(piles, s + 2, e), solve(piles, s + 1, e - 1));
    int r = piles[e] + min(solve(piles, s + 1, e - 1), solve(piles, s, e - 2));
    return dp[s][e] = max(l, r);
}
bool stoneGame(vector<int> &piles)
{
    int sum = 0;
    int n = piles.size();
    dp.resize(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
        sum += piles[i];
    int alice = solve(piles, 0, n - 1);
    return (alice > sum - alice);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> piles = {5, 3, 4, 5};
    if (stoneGame(piles))
        cout << "Winner: Alice\n";
    else
        cout << "Winner: Bob\n";

    return 0;
}