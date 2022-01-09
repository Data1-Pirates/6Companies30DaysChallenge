/*
Your Task:
You don't need to read or print anything. 
Your task is to complete the function canPair() which takes array and k as input parameter and 
returns true if array can be divided into pairs such that sum of every pair is divisible by k otherwise returns false.

Link:
https://www.google.com/url?q=https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1&sa=D&source=editors&ust=1641716809409000&usg=AOvVaw0Y2IDX02WrFSk0Q-QH0WcN
*/

#include <bits/stdc++.h>
using namespace std;

bool canPair(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n & 1)
        return false;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[((arr[i] % k) + k) % k]++;

    for (int i = 0; i < n; i++)
    {
        int a = ((arr[i] % k) + k) % k;
        if (2 * a == k)
        {
            if (mp[a] % 2 != 0)
                return false;
        }
        else if (a == 0)
        {
            if (mp[a] & 1)
                return false;
        }
        else if (mp[a] != mp[k - a])
            return false;
    }
    return true;
}

int main()
{
    vector<int> arr = {92, 75, 65, 48, 45, 35};
    int k = 10;
    canPair(arr, k) ? cout << "True" : cout << "False";
    return 0;
}