#include <bits/stdc++.h>
using namespace std;

int LCS(int firstArr[], int secondArr[], int n, int m)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[firstArr[i]] = i;
    vector<int> temp;
    for (int i = 0; i < m; i++)
    {
        if (mp.find(secondArr[i]) != mp.end())
            temp.push_back(mp[secondArr[i]]);
    }
    vector<int> tail;
    if (temp.size() > 0)
        tail.push_back(temp[0]);
    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] > tail.back())
            tail.push_back(temp[i]);
        else if (temp[i] < tail[0])
            tail[0] = temp[i];
        else
        {
            auto it = lower_bound(tail.begin(), tail.end(), temp[i]);
            *it = temp[i];
        }
    }
    return tail.size();
}

int minInsAndDel(int A[], int B[], int N, int M)
{
    // code here
    int x = LCS(B, A, M, N);
    int ans = N - x + M - x;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A[] = {1, 2, 5, 3, 1};
    int B[] = {1, 3, 5};
    cout << "Output: " << minInsAndDel(A, B, 5, 3);
    return 0;
}