/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. 
Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Link:
https://leetcode.com/problems/koko-eating-bananas/
*/

#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    int g = 0;
    int n = piles.size();
    for (int i = 0; i < n; i++)
        g = max(g, piles[i]);
    int l = 1, r = g;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int sum = 0;
        // cout << l << " " << r << " " << mid << endl;
        for (int i = 0; i < n; i++)
        {
            sum += piles[i] / mid;
            if (piles[i] % mid)
                sum++;
        }
        if (sum > h)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> piles = {1, 1, 1, 999999999};
    int h = 10;
    cout << "Output: " << minEatingSpeed(piles, h);

    return 0;
}