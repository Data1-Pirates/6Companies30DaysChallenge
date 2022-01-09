/*
Your Task:
Complete the function encode() which takes a character array as a input parameter and
returns the encoded string.

Link:
https://www.google.com/url?q=https://practice.geeksforgeeks.org/problems/run-length-encoding/1/&sa=D&source=editors&ust=1641716809398000&usg=AOvVaw1TmR46IU70QO6dAGUb2h6c
*/

#include <bits/stdc++.h>
using namespace std;

string encode(string src)
{
    // Your code here
    string ans = "";
    int n = src.length();
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i < n - 1 && src[i] == src[i + 1])
        {
            count++;
            i++;
        }
        ans += src[i];
        ans += ('0' + count);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "abbbcdddd";
    cout << "Output: " << encode(str);
    return 0;
}