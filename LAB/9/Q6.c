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

int find(Node* root, int x, int* path, int idx){
    if(!root){
        return -1;
    }
    path[idx++] = root->data;
    if(x==root->data){
        return idx;
    }
    else if(x < root->data){
        find(root->left, x, path, idx);
    }else{
        find(root->right, x, path, idx);
    }
}

int answer(Node* root, int a, int b){
    int A[1000];
    int B[1000];
    int aa = find(root, a, A, 0);
    int bb = find(root, b, B, 0);
    int idx = 0;
    for(int i=0; i<aa && i<bb; i++){
        if(A[i]==B[i]) idx = i;
    }
    int ans = A[idx];
    for(int i=idx+1;i<aa;i++){
        ans += A[i];
    }
    for(int i=idx+1;i<bb;i++){
        ans += B[i];
    }
    return ans;
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
    int a,b;
    scanf("%d %d", &a, &b);
    Node *root = buildBST(arr, n);
    int ans = answer(root, a,b);
    printf("%d\n", ans);
    return 0;
}