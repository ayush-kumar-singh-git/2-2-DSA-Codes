#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t
{
    int val;
    struct Node_t *left;
    struct Node_t *right;
} Node;

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int val)
{
    Node *newNode = createNode(val);
    if (!root)
        return newNode;
    Node *curr = root;
    while (1)
    {
        if (val < curr->val)
        {
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = newNode;
                break;
            }
        }
        else
        {
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = newNode;
                break;
            }
        }
    }
    return root;
}

Node *buildTree(int *a, int n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, a[i]);
    }
    return root;
}

int inOSucc(Node *root)
{
    Node *succ = root->right;
    while (succ && succ->left)
    {
        succ = succ->left;
    }
    if (succ)
        return succ->val;
    return -1;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Node *root = buildTree(a, n);
    int x;
    scanf("%d", &x);
    Node *node = NULL;
    while (1)
    {
        if (x == root->val)
        {
            node = root;
            break;
        }
        else if (x < root->val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    printf("%d\n", inOSucc(node));
    return 0;
}