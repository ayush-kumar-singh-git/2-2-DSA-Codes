#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t
{
    int val;
    struct Node_t *left;
    struct Node_t *right;
} Node;

Node q[1000];
int front = -1;
int back = -1;

void push(Node x)
{
    if (front == back && front == -1)
    {
        front++;
        back++;
    }
    q[back++] = x;
}

Node pop()
{
    return q[front++];
}

int empty()
{
    return front == back;
}


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
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Node *root = buildTree(a, n);

    push(*root);
    int dir = 1;
    while (!empty())
    {
        int sz = back - front;
        Node a[100];
        int x = 0;
        for (int i = 0; i < sz; i++)
        {
            Node curr = pop();
            if (curr.left)
                push(*curr.left);
            if (curr.right)
                push(*curr.right);
            a[x++] = curr;
        }

        if(dir == 1){
            for(int i=0;i<x;i++){
                printf("%d ", a[i].val);
            }
        }else{
            for(int i=x-1;i>=0;i--){
                printf("%d ", a[i].val);
            }
        }
        dir*=-1;
    }
    printf("\n");
    return 0;
}