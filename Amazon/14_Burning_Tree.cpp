/*
Your Task:  
You don't need to read input or print anything. 
Complete the function minTime() which takes the root of the tree and target as input parameters and 
returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.

Link:
https://practice.geeksforgeeks.org/problems/burning-tree/1/
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        right = left = NULL;
    }
};

Node *newNode(int val)
{
    Node *temp = new Node(val);
    return temp;
}

int burnTree(Node *root, int target, queue<Node *> &q, int &ans)
{
    if (root == NULL)
        return 0;

    if (root->data == target)
    {
        if (root->left != NULL)
            q.push(root->left);
        if (root->right != NULL)
            q.push(root->right);
        return 1;
    }

    int a = burnTree(root->left, target, q, ans);
    if (a == 1)
    {
        int qsize = q.size();
        ans++;
        while (qsize--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        if (root->right != NULL)
            q.push(root->right);
        return 1;
    }

    int b = burnTree(root->right, target, q, ans);
    if (b == 1)
    {
        int qsize = q.size();

        ans++;
        while (qsize--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        if (root->left != NULL)
            q.push(root->left);
        return 1;
    }
    return 0;
}

int minTime(Node *root, int target)
{
    // Your code goes here
    int ans = 0;
    queue<Node *> q;
    burnTree(root, target, q, ans);
    while (!q.empty())
    {
        int qsize = q.size();
        if (qsize)
            ans++;
        while (qsize--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->left->left = newNode(8);
    root->left->right->left = newNode(9);
    root->left->right->right = newNode(10);
    root->left->right->left->left = newNode(11);

    int target = 8;

    cout << minTime(root, target);
    return 0;
}