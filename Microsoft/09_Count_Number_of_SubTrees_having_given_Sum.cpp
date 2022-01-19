/*
Your Task:
You don't need to read input or print anything. 
Your task is to complete the function countSubtreesWithSumX() which takes the root node and an integer X as inputs and 
returns the number of subtrees of the given Binary Tree having sum exactly equal to X.

Link:
https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
    }
};

int solve(Node *root, int sum, int &X)
{
    if (root == NULL)
        return 0;

    int left = solve(root->left, sum, X);
    int right = solve(root->right, sum, X);
    int add = root->data + left + right;
    if (add == sum)
        X++;
    return add;
}

int countSubtreesWithSumX(Node *root, int x)
{
    int count = 0;
    solve(root, x, count);
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root = new Node(5);
    root->left = new Node(-10);
    root->right = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(8);
    root->right->left = new Node(-4);
    root->right->right = new Node(7);

    int x = 7;

    cout << "Count = " << countSubtreesWithSumX(root, x);

    return 0;
}