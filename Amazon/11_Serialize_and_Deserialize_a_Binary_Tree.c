/*
Your Task:
The task is to complete two function serialize which takes the root node of the tree as input and stores the tree into an file and 
deSerialize which deserializes the file to the original tree and returns the root of it.
*/

#include <stdio.h>
#include <stdlib.h>
#define MARKER -1

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *newNode(int key)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

void serialize(struct Node *root, FILE *fp)
{
    if (root == NULL)
    {
        fprintf(fp, "%d ", MARKER);
        return;
    }

    fprintf(fp, "%d ", root->key);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

void deSerialize(struct Node **root, FILE *fp)
{
    int val;
    if (fscanf(fp, "%d ", &val) == -1 || val == MARKER)
        return;

    *root = newNode(val);
    // printf("%d ", (*root)->key);
    deSerialize(&((*root)->left), fp);
    deSerialize(&((*root)->right), fp);
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main()
{
    struct Node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL)
    {
        puts("Could not open file");
        return 0;
    }
    serialize(root, fp);
    fclose(fp);

    struct Node *root1 = NULL;
    fp = fopen("tree.txt", "r");
    deSerialize(&root1, fp);

    printf("\nInorder Traversal of the tree constructed from file:\n");
    inorder(root1);

    return 0;
}