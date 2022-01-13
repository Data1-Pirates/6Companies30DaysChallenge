/*
Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list

Link:
https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void linkdelete(struct Node *root, int m, int n)
{
    if (root == NULL || root->next == NULL)
        return;
    Node *ptr1 = root;
    Node *ptr2 = root;
    while (ptr1 != NULL)
    {
        for (int i = 0; i < m - 1; i++)
        {
            ptr1 = ptr1->next;
            if (ptr1 == NULL)
                return;
        }
        ptr2 = ptr1->next;
        for (int i = 0; i < n; i++)
        {
            if (ptr2 == NULL)
            {
                ptr1->next = ptr2;
                return;
            }
            ptr2 = ptr2->next;
        }
        ptr1->next = ptr2;
        ptr1 = ptr2;
    }
}

void display(Node *root)
{
    Node *ptr = root;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *head = NULL;
    int M = 2, N = 3;
    push(&head, 10);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "M = " << M << " N = " << N << "\nGiven Linked list is :\n";
    display(head);

    linkdelete(head, M, N);

    cout << "\nLinked list after deletion is :\n";
    display(head);
    return 0;
}