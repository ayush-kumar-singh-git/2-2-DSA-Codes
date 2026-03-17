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

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

int count = 0;

void solve(Node* root, int L, int R){
    if(!root) return;
    if(root->data >= L && root->data <= R){
        count++;
        solve(root->left, L, R);
        solve(root->right, L, R);
    }
    else if(root->data < L){
        solve(root->right, L, R);
    }else{
        solve(root->left, L, R);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int L, R;
    scanf("%d %d", &L, &R);
    Node *root = buildBST(a, n);
    solve(root, L, R);
    printf("%d\n", count);
    return 0;
}