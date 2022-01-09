/*
Your Task:
You do not need to read input or print annything.
Your task is to complete the function decodedString() which takes s as input parameter and
returns the decoded string.

Link:
https://www.google.com/url?q=https://practice.geeksforgeeks.org/problems/decode-the-string2444/1&sa=D&source=editors&ust=1641716809409000&usg=AOvVaw1bmd9UNhKw2FSEN6A8MmAA
*/

#include <bits/stdc++.h>
using namespace std;

string solve(string str, int j, int n)
{
    if (j == n)
        return "";
    string ans = "";
    for (int i = j; i < n; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            int m = 0;
            while (str[i] >= '0' && str[i] <= '9')
            {
                m = m * 10 + str[i] - '0';
                i++;
            }
            i--;
            int N = i + 2, count = 1;
            while (N < n && count)
            {
                if (str[N] == '[')
                    count++;
                else if (str[N] == ']')
                    count--;
                N++;
            }
            string s = solve(str, i + 1, N);
            while (m--)
                ans += s;
            i = N - 1;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
            ans += str[i];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str = "11[geeks10[c]]";
    int n = str.length();
    cout << solve(str, 0, n);
    return 0;
}