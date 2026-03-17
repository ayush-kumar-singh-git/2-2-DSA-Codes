/*
    Instead of storing the whole inorder we can just do it on the fly
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t
{
    int data;
    struct Node_t *left;
    struct Node_t *right;
} Node;

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *findParent(Node *root, int val)
{
    if (!root)
        return NULL;
    if (root->data > val && root->left == NULL)
        return root;
    else if (root->data < val && root->right == NULL)
        return root;
    else if (root->data > val)
        return findParent(root->left, val);
    else if (root->data < val)
        return findParent(root->right, val);
}

Node *insert(Node *root, int val)
{
    Node *newNode = createNode(val);
    if (!root)
        return newNode;
    Node *parent = findParent(root, val);
    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    return root;
}

void inorder(Node *root, int* arr, int* idx)
{
    if (!root)
        return;
    inorder(root->left, arr, idx);
    arr[(*idx)++] = root->data;
    inorder(root->right, arr, idx);
    return;
}

Node *buildBST(int *a, int n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, a[i]);
    }
    return root;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int k;
    scanf("%d", &k);
    Node *root = buildBST(arr, n);
    int inO[n];
    int idx = 0;
    inorder(root, inO, &idx); // inorder is always sorted
    printf("%d\n", inO[k-1]);
    return 0;
}