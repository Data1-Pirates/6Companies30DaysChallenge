/*
Given a string consisting of some numbers, not separated by any separator. 
The numbers are positive integers and the sequence increases by one at each number except the missing number. 
The task is to complete the function missingNumber which return's the missing number. The numbers will have no more than six digits. 
Print -1 if input sequence is not valid.

Link:
https://practice.geeksforgeeks.org/problems/find-the-missing-no-in-string/1/
*/

#include <bits/stdc++.h>
using namespace std;
#define digits 6

int formNumber(const string &str, int i, int n)
{
    if (i + n > str.length())
        return -1;
    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        int a = str[i + j] - '0';
        if (a < 0 || a > 9)
            return -1;
        ans = ans * 10 + a;
    }
    return ans;
}

int missingNumber(const string &str)
{
    // Code here
    for (int i = 1; i <= digits; i++)
    {
        int n = formNumber(str, 0, i);
        if (n == -1)
            break;
        int miss_No = -1;
        bool flag = false;
        for (int j = i; j < str.length(); j += 1 + log10(n))
        {
            if (miss_No == -1 && formNumber(str, j, 1 + log10(n + 2)) == n + 2)
            {
                miss_No = n + 1;
                n += 2;
            }
            else if (formNumber(str, j, 1 + log10(n + 1)) == n + 1)
                n++;
            else
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return miss_No;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << missingNumber("99101102");
    return 0;
}