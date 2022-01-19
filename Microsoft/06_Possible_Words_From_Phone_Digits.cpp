/*
Your Task:
You don't need to read input or print anything. 
You just need to complete the function possibleWords() that takes an array a[ ] and N as input parameters and 
returns an array of all the possible words in lexicographical increasing order. 

Link:
https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/
*/

#include <bits/stdc++.h>
using namespace std;

void findCombinations(vector<char> keypad[], int input[], string res, int index, int n, vector<string> &ans)
{
    if (index == n)
    {
        // cout << res << " ";
        ans.push_back(res);
        return;
    }
    int digit = input[index];
    int len = keypad[digit].size();
    for (int i = 0; i < len; i++)
    {
        findCombinations(keypad, input, res + keypad[digit][i], index + 1, n, ans);
    }
}

vector<string> possibleWords(int a[], int N)
{
    // Your code here
    vector<string> ans;
    vector<char> keypad[] =
        {
            {}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

    findCombinations(keypad, a, string(""), 0, N, ans);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    vector<string> ans = possibleWords(arr, n);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}