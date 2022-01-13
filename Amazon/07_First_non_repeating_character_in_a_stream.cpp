/*
Your Task:
You don't need to read or print anything.
Your task is to complete the function FirstNonRepeating() which takes A as input parameter and
returns a string after processing the input stream.

Link:
https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 256

struct node
{
    char data;
    struct node *left, *right;
};

void appendNode(struct node **head_ref, struct node **tail_ref, char x)
{
    struct node *temp = new node;
    temp->data = x;
    temp->left = temp->right = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = *tail_ref = temp;
        return;
    }
    (*tail_ref)->right = temp;
    temp->left = *tail_ref;
    *tail_ref = temp;
}

void removeNode(struct node **head_ref, struct node **tail_ref, struct node *temp)
{
    if (*head_ref == NULL)
        return;

    if (*head_ref == temp)
        *head_ref = (*head_ref)->right;
    if (*tail_ref == temp)
        *tail_ref = (*tail_ref)->left;
    if (temp->right != NULL)
        temp->right->left = temp->left;
    if (temp->left != NULL)
        temp->left->right = temp->right;

    delete (temp);
}

string FirstNonRepeating(string str)
{
    string ans;
    vector<bool> vis(MAX_CHAR, false);
    vector<struct node *> inDLL(MAX_CHAR, NULL);
    struct node *head = NULL, *tail = NULL;

    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (!vis[c])
        {
            if (inDLL[c] == NULL)
            {
                appendNode(&head, &tail, c);
                inDLL[c] = tail;
            }
            else
            {
                removeNode(&head, &tail, inDLL[c]);
                inDLL[c] = NULL;
                vis[c] = true;
            }
        }
        if (head != NULL)
            ans += (head->data);
        else
            ans += '#';
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "aabc";
    string ans = FirstNonRepeating(str);
    cout << ans;

    return 0;
}