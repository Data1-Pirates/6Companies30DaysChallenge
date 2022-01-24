/*
Your Task:  
You don't need to read input or print anything. 
Complete the function AllParenthesis() which takes N as input parameter and returns the list of balanced parenthesis.

Link:
https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
void solve(int n, int o, int c, string str)
{
    if (o == n && c == n)
        ans.push_back(str);
    if (o < n)
    {
        solve(n, o + 1, c, str + '(');
    }
    if (c < o)
        solve(n, o, c + 1, str + ')');
}
vector<string> AllParenthesis(int n)
{
    // Your code goes here
    solve(n, 0, 0, "");
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    AllParenthesis(4);
    for (auto i : ans)
        cout << i << "\n";

    return 0;
}