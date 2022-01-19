/*
Your Task:
You only need to complete the function generate() that takes N as parameter and 
returns vector of strings denoting binary numbers.

Link:
https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> generate(int n)
{
    // Your code here
    vector<string> ans;
    queue<string> q;
    q.push("1");
    if (n == 1)
    {
        ans.push_back(q.front());
        return ans;
    }
    int i = 0;
    while (i < n)
    {
        int qsize = q.size();
        while (qsize-- && i < n)
        {
            string temp = q.front();
            q.pop();
            q.push(temp + '0');
            q.push(temp + '1');
            ans.push_back(temp);
            i++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> ans = generate(10);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}