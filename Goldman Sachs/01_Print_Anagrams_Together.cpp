/*
Your Task:
The task is to complete the function Anagrams() that takes a list of strings as input and
returns a list of groups such that each group consists of all the strings that are anagrams.

Link:
https://www.google.com/url?q=https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/&sa=D&source=editors&ust=1641716809397000&usg=AOvVaw0cq2DcjHeKkI891yIWlNLc
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> Anagrams(vector<string> &string_list)
{
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> ans1;
    int n = string_list.size();
    if (n == 0)
        return ans;
    for (int i = 0; i < n; i++)
    {
        string s = string_list[i];
        sort(s.begin(), s.end());
        ans1[s].push_back(string_list[i]);
    }
    for (auto i = ans1.begin(); i != ans1.end(); i++)
        ans.push_back(i->second);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> str = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> ans = Anagrams(str);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}