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

int ans = 0;

void solve(Node *root, int L, int R)
{
    if (!root)
        return;

    int r = root->val;
    if (L <= r && r <= R)
    {
        ans++;
        solve(root->left, L, R);
        solve(root->right, L, R);
    }
    else if (r < L)
    {
        solve(root->right, L, R);
    }
    else
    {
        solve(root->left, L, R);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Node *root = buildTree(a, n);
    int L, R;
    scanf("%d %d", &L, &R);
    solve(root, L, R);
    printf("%d\n", ans);
    return 0;
}