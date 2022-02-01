/*
You are given two integers n and k and two integer arrays speed and efficiency both of length n. 
There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.
Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.
Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.

Link:
https://leetcode.com/problems/maximum-performance-of-a-team
*/

#include <bits/stdc++.h>
using namespace std;

static bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > b.first;
}

int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
{
    int p = 1e9 + 7;
    long long int ans = 0, sum = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({efficiency[i], speed[i]});
    sort(v.begin(), v.end(), compare);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        sum += v[i].second;
        pq.push(v[i].second);
        if (pq.size() > k)
        {
            sum -= pq.top();
            pq.pop();
        }
        ans = max(ans, sum * v[i].first);
    }
    return ans % p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 6;
    vector<int> speed = {2, 10, 3, 1, 5, 8};
    vector<int> efficiency = {5, 4, 3, 9, 7, 2};
    int k = 2;
    cout << "Output: " << maxPerformance(n, speed, efficiency, k);

    return 0;
}