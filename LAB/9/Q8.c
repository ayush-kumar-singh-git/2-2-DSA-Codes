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
    int x;
    scanf("%d", &x);
    Node *root = buildBST(arr, n);
    int inO[n]; // for a BST Inorder will always be sorted
    int idx = 0;
    inorder(root, inO, &idx);
    int l =0, r=n-1;
    int ans = -1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(inO[m] <= x){
            l = m+1;
        }else{
            ans = m;
            r = m-1;
        }
    }
    if(ans==-1)
        printf("-1\n");
    else
        printf("%d\n", inO[ans]);
    return 0;
}