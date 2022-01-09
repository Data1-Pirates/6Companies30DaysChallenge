/*
Your task:
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).
Given two strings str1 and str2,
return the largest string x such that x divides both str1 and str2.

Link:
https://www.google.com/url?q=https://leetcode.com/problems/greatest-common-divisor-of-strings/&sa=D&source=editors&ust=1641716809400000&usg=AOvVaw2a9KqHtNZ2vz_Fc17q0Z9c
*/

#include <bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    int n = __gcd(n1, n2);
    string ans = str1.substr(0, n);
    for (int i = 0; i < n1; i += n)
    {
        int j = 0;
        while (j < n)
        {
            if (ans[j] != str1[i + j])
                return "";
            j++;
        }
    }
    for (int i = 0; i < n2; i += n)
    {
        int j = 0;
        while (j < n)
        {
            if (ans[j] != str2[i + j])
                return "";
            j++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1 = "ABABAB", str2 = "ABAB";
    cout << "Output: " << gcdOfStrings(str1, str2);
    return 0;
}