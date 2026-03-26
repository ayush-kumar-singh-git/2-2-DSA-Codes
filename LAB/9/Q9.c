#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
} Node;

// Create node
Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->color = RED;   // new node always RED
    n->left = n->right = n->parent = NULL;
    return n;
}

// Left Rotate
void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left)
        y->left->parent = x;

    y->parent = x->parent;

    if (!x->parent)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

// Right Rotate
void rightRotate(Node** root, Node* x) {
    Node* y = x->left;
    x->left = y->right;

    if (y->right)
        y->right->parent = x;

    y->parent = x->parent;

    if (!x->parent)
        *root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;
}

void fixInsert(Node** root, Node* z) {
    while (z->parent && z->parent->color == RED) {

        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right; // uncle

            // Case 1: Uncle is RED
            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                // Case 2: Triangle
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                // Case 3: Line
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left; // uncle

            // mirror cases
            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK; // root always black
}

Node* insert(Node* root, int data) {
    Node* z = createNode(data);
    Node* y = NULL;
    Node* x = root;

    // BST insert
    while (x) {
        y = x;
        if (data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (!y)
        root = z;
    else if (data < y->data)
        y->left = z;
    else
        y->right = z;

    fixInsert(&root, z);
    return root;
}

int blackHeight(Node* root) {
    int bh = 0;
    while (root) {
        if (root->color == BLACK)
            bh++;
        root = root->left;
    }
    return bh + 1;  // add NIL node
}

int main() {
    int n;
    scanf("%d", &n);

    Node* root = NULL;

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("%d\n", blackHeight(root));
    return 0;
}