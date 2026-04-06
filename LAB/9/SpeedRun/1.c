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

int LCA(Node* root, int x, int y){
    int a[1000];
    int b[1000];
    int m=0, n=0;
    Node* curr = root;
    while(1){
        a[m++] = curr->val;
        if(x == curr->val){
            break;
        }else if(x < curr -> val){
            curr = curr->left;
        }else{
            curr = curr -> right;
        }
    }
    curr = root;
    while(1){
        b[n++] = curr->val;
        if(y == curr->val){
            break;
        }else if(y < curr -> val){
            curr = curr->left;
        }else{
            curr = curr -> right;
        }
    }
    int ans = 0;
    for(int i =0; i<m && i<n ; i++){
        if(a[i] == b[i]) ans = a[i];
    }
    return ans;
}


int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Node *root = buildTree(a, n);
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", LCA(root,x,y));
    return 0;
}