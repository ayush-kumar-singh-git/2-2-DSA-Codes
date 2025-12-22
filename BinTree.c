#include <stdio.h>
#include <stdlib.h>

typedef struct Tree_Node_t
{
    int data;
    struct Tree_Node_t *left;
    struct Tree_Node_t *right;
} Node;

Node *createNode(int val);
Node *buildBinTree(int *preOrderSeq, int n, int resetIdx);
void preOrderTraversal(Node *root);

int main()
{
    int arr[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildBinTree(arr, 11, 0);
    preOrderTraversal(root);
    return 0;
}

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *buildBinTree(int *preOrderSeq, int n, int resetIdx)
{
    static int idx = 0;
    if (resetIdx)
    {
        idx = 0; // only use when you want to make many trees
    }
    if (idx >= n)
        return NULL;
    if (preOrderSeq[idx] == -1)
    {
        idx++;
        return NULL;
    }
    Node *root = createNode(preOrderSeq[idx]);
    idx++;
    root->left = buildBinTree(preOrderSeq, n, 0);
    root->right = buildBinTree(preOrderSeq, n, 0);
    return root;
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    return;
}