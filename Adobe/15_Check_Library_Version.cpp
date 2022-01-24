/*
Your task:
Given two library versions of an executable: for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”. 
Find out which one is more recent?
*/

#include <bits/stdc++.h>
using namespace std;

bool checkVersion(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    int i1 = 0, i2 = 0;
    while (i1 < n1 && i2 < n2)
    {
        int a = 0, b = 0;
        while (i1 < n1 && str1[i1] != '.')
        {
            a = a * 10 + str1[i1] - '0';
            i1++;
        }
        i1++;
        while (i2 < n2 && str2[i2] != '.')
        {
            b = b * 10 + str2[i2] - '0';
            i2++;
        }
        i2++;
        if (a > b)
            return true;
        if (a < b)
            return false;
    }
    if (i2 >= n2)
        return true;
    if (i1 >= n1)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1 = "10";
    string str2 = "10.1";
    if (checkVersion(str1, str2))
        cout << str1 << " is newer version\n";
    else
        cout << str2 << " is newer version\n";
    return 0;
}