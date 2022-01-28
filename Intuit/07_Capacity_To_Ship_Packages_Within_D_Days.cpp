#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int sum = 0, g = 0;
    for (int i = 0; i < n; i++)
    {
        sum += weights[i];
        g = max(g, weights[i]);
    }
    int l = g, r = sum;
    while (l <= r)
    {
        int s1 = 0, p = 1, mid = l + (r - l) / 2;
        for (int i = 0; i < n; i++)
        {
            s1 += weights[i];
            if (s1 > mid)
            {
                p++;
                s1 = weights[i];
            }
        }
        if (p <= days)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << "Output: " << shipWithinDays(weights, days);

    return 0;
}