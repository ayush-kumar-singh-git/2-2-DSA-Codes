#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node_t
{
    int data;
    struct Node_t *next;
} Node;

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    return newNode;
}

Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (head == NULL)
        {
            head = addToList(head, temp);
        }
        else
        {
            addToList(head, temp);
        }
    }
    return head;
}

void printList(Node *head)
{
    Node *cpy = head;
    while (cpy != NULL)
    {
        printf("%d ", cpy->data);
        cpy = cpy->next;
    }
    printf("\n");
    return;
}

void freeList(Node *head)
{
    Node *curr, *nxt;
    curr = head;
    while (curr != NULL)
    {
        nxt = curr->next;
        free(curr);
        curr = nxt;
    }
}