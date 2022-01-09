/*
Your Task:

You don't need to read input or print anything.
Your task is to complete the function printMinNumberForPattern() which takes the string S and
returns a string containing the minimum number following the valid pattern.

Link:
https://www.google.com/url?q=https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1&sa=D&source=editors&ust=1641716809407000&usg=AOvVaw3qunlevBv9TX5ro4EmZT1e
*/

#include <bits/stdc++.h>
using namespace std;

string printMinNumberForPattern(string str)
{
    // code here
    int n = str.length();
    int l = -1, r = 0;
    int pre_no = 0;
    string ans = "";
    while (l < n)
    {
        while (r < n && str[r] == 'D')
            r++;
        pre_no = (r - l + pre_no);
        int k = pre_no;
        while (l < n && l < r)
        {
            ans += (k + '0');
            l++;
            k--;
        }
        r++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "DDID";
    cout << "String is " << printMinNumberForPattern(str);
    return 0;
}