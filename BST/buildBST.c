#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t{
    int data;
    struct Node_t* left;
    struct Node_t* right;
}Node;

Node* createNode(int val);
Node* insert(Node* bst, Node* newNode);
Node* buildBST(int* a, int n);
void inOrderTraversal(Node* tree);
Node* search(Node* root, int val);
int minimum(Node* root);
int maximum(Node* root);

int main()
{
    int n = 10;
    int arr[10] = {4,3,5,8,1,2,7,6,10,9};
    Node* root = buildBST(arr,n);
    inOrderTraversal(root);
    printf("\n");
    int a = 2;
    int b = 12;
    search(root, a) == NULL ? printf("Not Found\n") : printf("Found\n");
    search(root, b) == NULL ? printf("Not Found\n") : printf("Found\n");
    printf("%d\n", maximum(root));
    printf("%d\n", minimum(root));
    return 0;
}

Node* createNode(int val){
    Node* newNode = malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Node* insert(Node* bst, Node* newNode){
    if(!bst) return newNode;
    if(bst->data > newNode->data){
        if(bst->left == NULL){
            bst -> left = newNode;
        }else{
            insert(bst->left, newNode);
        }
    }else{
        if(bst->right == NULL){
            bst -> right = newNode;
        }else{
            insert(bst->right, newNode);
        }
    }
    return bst;
}

Node* buildBST(int* a, int n){
    Node* root = NULL;
    for(int i=0;i<n;i++){
        Node* newNode = createNode(a[i]);
        root = insert(root, newNode);
    }
    return root;
}

void inOrderTraversal(Node* tree){
    if(!tree) return;
    inOrderTraversal(tree->left);
    printf("%d ", tree->data);
    inOrderTraversal(tree->right);
}

Node* search(Node* root, int val){
    if(!root) return NULL;
    if(val == root->data) return root;
    if(val < root->data) return search(root->left, val);
    else return search(root->right, val);
    return NULL;
}

int minimum(Node* root){
    Node* node = root;
    int x = root->data;
    while(node){
        x = node -> data;
        node = node -> left;
    }
    return x;
}

int maximum(Node* root){
    Node* node = root;
    int x = root->data;
    while(node){
        x = node -> data;
        node = node -> right;
    }
    return x;
}
