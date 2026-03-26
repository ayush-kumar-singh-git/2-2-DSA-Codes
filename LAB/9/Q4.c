#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t
{
    int data;
    struct Node_t *left;
    struct Node_t *right;
} Node;

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
    return root;
}
Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
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

Node *buildBST(int *a, int n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, a[i]);
    }
    return root;
}

int front = -1;
int back = -1;

Node* q[1000];

void enqueue(Node* x){
    if(front == -1){
        front = 0;
        back = 0;
    }
    q[back++] = x;
}


void dequeue(){
    front++;
}

int isEmpty(){
    return front==back || front==-1;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    Node* root = buildBST(a, n);

    enqueue(root);
    int dir = 1;
    while(!isEmpty()){
        int l = front;
        int r = back - 1;
        int size = r - l + 1;
        Node* temp[1000];
        for(int i = 0; i < size; i++){
            temp[i] = q[front + i];
        }
        if(dir == 1){
            for(int i = 0; i < size; i++){
                printf("%d ", temp[i]->data);
            }
        }else{
            for(int i = size-1; i >= 0; i--){
                printf("%d ", temp[i]->data);
            }
        }
        for(int i = 0; i < size; i++){
            if(temp[i]->left) enqueue(temp[i]->left);
            if(temp[i]->right) enqueue(temp[i]->right);
        }
        for(int i = 0; i < size; i++) dequeue();
                dir *= -1;
    }
            printf("\n");
    return 0;
}