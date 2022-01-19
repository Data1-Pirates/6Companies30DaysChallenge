/*
Your Task:
You don't have to take input. 
Complete the function connect() that takes root as parameter and connects the nodes at same level. 
The printing is done by the driver code. First line of the output will be level order traversal and second line will be inorder travsersal

Link:
https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *nextRight;

    Node(int x)
    {
        data = x;
    }
};

void connect(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int qsize = q.size();
        int i = 0;
        Node *temp;
        while (i < qsize)
        {
            temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            if (i < qsize - 1)
                temp->nextRight = q.front();
            else
                temp->nextRight = NULL;
            i++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    connect(root);
    // Let us check the values
    // of nextRight pointers
    cout << "Following are populated nextRight pointers in the tree"
            " (-1 is printed if there is no nextRight)\n";
    cout << "nextRight of " << root->data << " is "
         << (root->nextRight ? root->nextRight->data : -1) << endl;
    cout << "nextRight of " << root->left->data << " is "
         << (root->left->nextRight ? root->left->nextRight->data : -1) << endl;
    cout << "nextRight of " << root->right->data << " is "
         << (root->right->nextRight ? root->right->nextRight->data : -1) << endl;
    cout << "nextRight of " << root->left->left->data << " is "
         << (root->left->left->nextRight ? root->left->left->nextRight->data : -1) << endl;

    return 0;
}