/*
Your Task: 
You don't need to read input or print anything. 
Your task is to complete the function amendSentence() which takes the string s as input and 
returns a string with the stated amendments.

Link:
https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1
*/

#include <bits/stdc++.h>
using namespace std;

string amendSentence(string s)
{
    // your code here
    string ans;
    int n = s.length();
    if (n == 0)
        return ans;
    if (s[0] >= 'A' && s[0] <= 'Z')
        ans += (s[0] - 'A' + 'a');
    else
        ans += s[0];
    int i = 1;
    while (i < n)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += ' ';
            ans += (s[i] - 'A' + 'a');
        }
        else
        {
            ans += s[i];
        }
        i++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = "BruceWayneIsBatman";
    cout << "Output: " << amendSentence(s);

    return 0;
}