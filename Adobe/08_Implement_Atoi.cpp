/*
Your Task:
Complete the function atoi() which takes a string as input parameter and
returns integer value of it. if the input string is not a numerical string then returns -1.

Link:
https://practice.geeksforgeeks.org/problems/implement-atoi/1/
*/

#include <bits/stdc++.h>
using namespace std;

int atoi(string str)
{
    // Your code here
    long long int a = 0;
    int n = str.length();
    int i = 0;
    while (i < n && str[i] == ' ')
        i++;
    if (i == n)
        return -1;
    int sign = 1;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (i < n)
    {
        if ((str[i] - '0') >= 0 && (str[i] - '0') <= 9)
            a = a * 10 + str[i] - '0';
        else
            return -1;
        i++;
    }
    return a * sign;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << "Output: " << atoi("-12345");

    return 0;
}