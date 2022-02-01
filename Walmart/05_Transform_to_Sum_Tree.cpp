/*
Given a Binary Tree of size N , where each node can have positive or negative values. 
Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. 
The values of leaf nodes are changed to 0.

Link:
https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

int sum(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        int temp = root->data;
        root->data = 0;
        return temp;
    }
    int left = 0, right = 0;
    if (root->left != NULL)
        left = sum(root->left);
    if (root->right != NULL)
        right = sum(root->right);
    int temp = root->data;
    root->data = left + right;
    return temp + left + right;
}
void toSumTree(Node *node)
{
    // Your code here
    sum(node);
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void display(Node *root)
{
    if (root == NULL)
        return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root = NULL;
    int x;
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    toSumTree(root);
    display(root);

    return 0;
}