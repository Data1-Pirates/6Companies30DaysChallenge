/*
Your Task:
Youd do not need to read input or print anything. 
Your task is to complete the function displayContacts() which takes n, contact[ ] and s as input parameters and 
returns a list of list of strings for required prefixes. If some prefix has no matching contact return "0" on that list.

Link:
https://practice.geeksforgeeks.org/problems/phone-directory4628/1/
*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode *> child;
    bool end;
    TrieNode()
    {
        for (char i = 'a'; i <= 'z'; i++)
            child[i] = NULL;
        end = false;
    }
};

TrieNode *root = NULL;

void insert(string name)
{
    int len = name.length();
    TrieNode *itr = root;
    for (int i = 0; i < len; i++)
    {
        TrieNode *newNode = itr->child[name[i]];
        if (newNode == NULL)
        {
            newNode = new TrieNode();
            itr->child[name[i]] = newNode;
        }
        itr = newNode;
        if (i == len - 1)
            itr->end = true;
    }
}

void displayContactsUtil(TrieNode *curr, string name, vector<string> &ans)
{
    if (curr->end)
        ans.push_back(name);

    for (char i = 'a'; i <= 'z'; i++)
    {
        TrieNode *newNode = curr->child[i];
        if (newNode != NULL)
            displayContactsUtil(newNode, name + i, ans);
    }
}

vector<vector<string>> displayContacts(int n, string contact[], string name)
{
    // code here
    root = new TrieNode();
    for (int i = 0; i < n; i++)
        insert(contact[i]);
    TrieNode *prv = root;
    vector<vector<string>> result;
    string prefix = "";
    int len = name.length();
    int i;
    for (i = 0; i < len; i++)
    {
        vector<string> ans;
        prefix += name[i];
        char last = prefix[i];
        TrieNode *curr = prv->child[last];
        if (curr == NULL)
        {
            ans.push_back("0");
            result.push_back(ans);
            i++;
            break;
        }
        displayContactsUtil(curr, prefix, ans);
        result.push_back(ans);
        prv = curr;
    }
    for (; i < len; i++)
    {
        vector<string> ans;
        prefix += name[i];
        ans.push_back("0");
        result.push_back(ans);
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    int n = sizeof(contact) / sizeof(string);
    string query = "geeips";
    vector<vector<string>> ans = displayContacts(n, contact, query);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}