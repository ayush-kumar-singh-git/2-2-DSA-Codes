#include <stdio.h>
#include <stdlib.h>

// this is not a complete implementation of dblyLL only required functions are implemented

typedef struct Node_t
{
    int data;
    struct Node_t *prev;
    struct Node_t *next;
} Node;

Node *createNode(int val);
Node *addAtEnd(Node *listHead, Node *newNode);
Node *gotoNext(Node *listHead);
Node *gotoPrev(Node *listHead);
Node *readList();
void printList(Node *listHead);
void problemA();
Node *findInList(Node *listHead, int val);
Node *addNext(Node *listHead, Node *nextNode);
void removeNode(Node *node);
void problemB();
void problemC();
Node *getHead(Node *listHead);
Node *getTail(Node *listHead);

int main()
{
    problemC();
    return 0;
}

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *addAtEnd(Node *listHead, Node *newNode)
{
    if (listHead == NULL)
    {
        return newNode;
    }
    Node *curr = listHead;
    while (curr->next)
    {
        curr = curr->next;
    }
    newNode->prev = curr;
    curr->next = newNode;
    return listHead;
}

Node *gotoNext(Node *listHead)
{
    if (listHead->next != NULL)
        return listHead->next;
    return listHead;
}

Node *gotoPrev(Node *listHead)
{
    if (listHead->prev != NULL)
        return listHead->prev;
    return listHead;
}

Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *listHead = NULL;
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        Node *newNode = createNode(temp);
        listHead = addAtEnd(listHead, newNode);
    }
    return listHead;
}

void printList(Node *listHead)
{
    Node *curr = listHead;
    while (curr->prev != NULL)
        curr = curr->prev;
    while (curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    return;
}

void problemA()
{
    Node *curr = readList();
    int operation = 0;
    while (operation != 5)
    {
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            int new;
            scanf("%d", &new);
            curr = addAtEnd(curr, createNode(new));
            break;
        case 2:
            printf("%d\n", curr->data);
            break;
        case 3:
            curr = gotoNext(curr);
            break;
        case 4:
            curr = gotoPrev(curr);
            break;
        }
    }
}

Node *findInList(Node *listHead, int val)
{
    Node *temp1 = listHead;
    Node *temp2 = listHead;
    while (temp1)
    {
        if (temp1->data == val)
        {
            return temp1;
        }
        temp1 = temp1->next;
    }
    while (temp2)
    {
        if (temp2->data == val)
        {
            return temp2;
        }
        temp2 = temp2->prev;
    }
    return NULL; // if not found
}

Node *addNext(Node *curr, Node *node)
{
    node->next = curr->next;
    node->prev = curr;
    if (curr->next)
        curr->next->prev = node;
    curr->next = node;
    return curr;
}

void removeNode(Node *node)
{
    if (!node)
        return;

    if (node->prev)
        node->prev->next = node->next;

    if (node->next)
        node->next->prev = node->prev;

    free(node);
}

void problemB()
{
    Node *curr = readList();
    int operation = 0;
    int new;
    while (operation != 5)
    {
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            scanf("%d", &new);
            curr = addAtEnd(curr, createNode(new));
            break;
        case 2:
            printf("%d\n", curr->data);
            break;
        case 3:
            curr = gotoNext(curr);
            break;
        case 4:
            curr = gotoPrev(curr);
            break;
        case 6:
            scanf("%d", &new);
            Node *node = findInList(curr, new);
            removeNode(node);
            node = createNode(new);
            curr = addNext(curr, node);
            break;
        }
    }
}

void problemC()
{
    int k;
    scanf("%d", &k);
    Node *list = readList();
    Node *left = getHead(list);
    Node *right = getTail(list);
    int found = 0;
    while (left->data != right->data)
    {
        if (left->data + right->data == k)
        {
            found = 1;
            break;
        }
        else if (left->data + right->data < k)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    printf("%d\n", found);
}

Node *getHead(Node *listHead)
{
    Node *curr = listHead;
    while (curr->prev)
    {
        curr = curr->prev;
    }
    return curr;
}

Node *getTail(Node *listHead)
{
    Node *curr = listHead;
    while (curr->next)
    {
        curr = curr->next;
    }
    return curr;
}