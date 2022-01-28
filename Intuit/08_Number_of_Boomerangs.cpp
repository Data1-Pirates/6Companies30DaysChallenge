/*
You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. 
A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the 
distance between i and k (the order of the tuple matters).
Return the number of boomerangs.

Link:
https://leetcode.com/problems/number-of-boomerangs/
*/

#include <bits/stdc++.h>
using namespace std;

int numberOfBoomerangs(vector<vector<int>> &points)
{
    int n = points.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> mp;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            int d = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
            mp[d]++;
        }
        for (auto i = mp.begin(); i != mp.end(); i++)
            ans += (i->second) * (i->second - 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> points = {{1, 0}, {0, 0}, {2, 0}};
    cout << "Output: " << numberOfBoomerangs(points);

    return 0;
}