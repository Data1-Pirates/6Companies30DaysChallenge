/*
You are given an integer n representing the length of an unknown array that you are trying to recover. 
You are also given an array sums containing the values of all 2n subset sums of the unknown array (in no particular order).
Return the array ans of length n representing the unknown array. If multiple answers exist, return any of them.
An array sub is a subset of an array arr if sub can be obtained from arr by deleting some (possibly zero or all) elements of arr. 
The sum of the elements in sub is one possible subset sum of arr. The sum of an empty array is considered to be 0.

Link:
https://leetcode.com/problems/find-array-given-subset-sums
*/

#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

vector<int> recoverArray(int n, vector<int> &sums)
{
    sort(sums.begin(), sums.end());
    vector<int> v;
    while (sums.size() > 1)
    {
        unordered_map<int, int> mp;
        vector<int> v1, v2;
        int a = sums[1] - sums[0];
        bool flag = false;
        for (int j = 0; j < sums.size(); j++)
        {
            if (!mp[sums[j]])
            {
                v1.push_back(sums[j]);
                mp[sums[j] + a]++;
                if (sums[j] == 0)
                    flag = true;
            }
            else
            {
                v2.push_back(sums[j]);
                mp[sums[j]]--;
            }
        }
        if (flag)
        {
            v.push_back(a);
            sums = v1;
        }
        else
        {
            v.push_back(-a);
            sums = v2;
        }
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> sums = {-3, -2, -1, 0, 0, 1, 2, 3};
    vector<int> ans = recoverArray(8, sums);
    display(ans);
    return 0;
}