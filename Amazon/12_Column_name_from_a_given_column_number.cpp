/*
Your Task:
You don't need to read input or print anything. 
Your task is to complete the function colName() which takes the column number N as input and 
returns the column name represented as a string.

Link:
https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/
*/

#include <bits/stdc++.h>
using namespace std;

string colName(long long int n)
{
    string ans = "";
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (n)
    {
        if (n % 26)
        {
            ans = alpha[n % 26 - 1] + ans;
            n = n / 26;
        }
        else
        {
            ans = 'Z' + ans;
            n = n / 26;
            n--;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << colName(4294967295);

    return 0;
}