#include <bits/stdc++.h>
using namespace std;

vector<string> winner(string arr[], int n)
{
    // Your code here
    // Return the string containing the name and an integer
    // representing the number of votes the winning candidate got
    unordered_map<string, int> vote;
    for (int i = 0; i < n; i++)
        vote[arr[i]]++;
    string str = arr[0];
    for (auto i = vote.begin(); i != vote.end(); i++)
    {
        if (vote[str] < i->second)
            str = i->first;
        else if (vote[str] == i->second)
        {
            str = (str.compare(i->first) > 0) ? i->first : str;
        }
    }
    vector<string> ans;
    ans.push_back(str);
    ans.push_back(to_string(vote[str]));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string Votes[] = {"john", "johnny", "jackie", "johnny", "john", "jackie", "jamie", "jamie", "john", "johnny", "jamie", "johnny", "john"};
    int n = 13;
    vector<string> ans = winner(Votes, n);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}