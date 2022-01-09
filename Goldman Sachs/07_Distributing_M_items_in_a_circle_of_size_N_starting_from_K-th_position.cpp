/*
M items are to be delivered in a circle of size N.
Find the position where the M-th item will be delivered if we start from a given position K.
Note that items are distributed at adjacent positions starting from K.

Link:
https://www.google.com/url?q=https://www.geeksforgeeks.org/distributing-m-items-circle-size-n-starting-k-th-position/&sa=D&source=editors&ust=1641716809406000&usg=AOvVaw0lohtfG57h1Q2F2eSw8ddl
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m = 8, n = 5, k = 2;
    // cin >> m >> n >> k;

    int ans = m + k - 1;
    ans = ans % n;
    if (ans == 0)
        ans = n;
    cout << ans << endl;
    return 0;
}