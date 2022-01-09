/*
Your Task:
You don't need to read or print anything.
Your task is to complete the function CountWays() which takes the string as str as input parameter and
returns the total number of ways the string can be decoded modulo 10^9 + 7.

Link:
https://www.google.com/url?q=https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/&sa=D&source=editors&ust=1641716809406000&usg=AOvVaw0L88yfHMJ5ykLo6z_ohsRp
*/

#include <bits/stdc++.h>
using namespace std;

/* To print the required strings

void solve(string str, int i, string ans)
{
    int n = str.length();
    if (i == n)
    {
        cout << ans << endl;
        return;
    }
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ans += alpha[str[i] - '0' - 1];
    solve(str, i + 1, ans);
    ans.pop_back();
    if (i < n - 1)
    {
        int a = (str[i] - '0') * 10 + str[i + 1] - '0';
        if (a <= 26)
        {
            ans += alpha[a - 1];
            solve(str, i + 2, ans);
        }
    }
}
*/

int CountWays(string &str)
{
    // Code here
    int n = str.length();
    vector<int> count(n + 1);
    count[0] = 1;
    count[1] = 1;

    if (str[0] == '0')
        return 0;

    for (int i = 2; i <= n; i++)
    {
        count[i] = 0;
        if (str[i - 1] > '0')
            count[i] = count[i - 1];
        if (str[i - 2] == '1' || (str[i - 2] == '2' && str[i - 1] < '7'))
            count[i] = (count[i] + count[i - 2]) % 1000000007;
    }
    return count[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "1234";
    cout << "Count is " << CountWays(str);
    return 0;
}