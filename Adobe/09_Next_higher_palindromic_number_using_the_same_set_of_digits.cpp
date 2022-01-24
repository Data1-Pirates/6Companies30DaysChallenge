/*
Your Task:  
You don't need to read input or print anything. 
Your task is to complete the function nextPalin() which takes the string N as input parameters and 
returns the answer, else if no such number exists returns "-1".

Link:
https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/
*/

#include <bits/stdc++.h>
using namespace std;

void reverse(string &str, int i, int j)
{
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
}

string nextPalin(string str)
{
    int n = str.length();
    string ans;
    if (n <= 3)
    {
        ans = "-1";
        return ans;
    }
    int mid = n / 2 - 1;
    int i, j;
    for (i = mid - 1; i >= 0; i--)
    {
        if (str[i] < str[i + 1])
            break;
    }
    if (i < 0)
    {
        ans = "-1";
        return ans;
    }
    int smallest = i + 1;
    for (j = i + 2; j <= mid; j++)
    {
        if (str[j] > str[i] && str[j] <= str[smallest])
            smallest = j;
    }
    swap(str[i], str[smallest]);
    swap(str[n - i - 1], str[n - smallest - 1]);
    reverse(str, i + 1, mid);
    if (n % 2 == 0)
        reverse(str, mid + 1, n - i - 2);
    else
        reverse(str, mid + 2, n - i - 2);
    ans = str;
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num = "4697557964";
    // int n = num.length();
    cout << "Output: " << nextPalin(num);

    return 0;
}