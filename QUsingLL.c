// needs some minor improvements - eg size handling and malloc failure handling

#include <stdio.h>
#include <stdlib.h>

// structs used

typedef struct Node_t
{
    int data;
    struct Node_t *next;
} Node;

typedef struct Queue_t
{
    Node *front; // deletion from here
    Node *back;  // insertion here
    int size;
} Queue;

// implemented functions

Node *createNode(int val);
Node *insertAtTail(Queue *q, int val);
Node *deleteFromHead(Queue *q);
Queue *initQ();
Queue *readQ();
void printQ(Queue *q);
void insert(Queue *q, int val);
void pop(Queue *q);
int front(Queue *q);
int size(Queue *q);
int isEmpty(Queue *q);
void clear(Queue *q);

int main()
{
    Queue *q = readQ();
    printQ(q);
    return 0;
}

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtTail(Queue *q, int val)
{
    Node *newNode = createNode(val);
    if (q->size > 0)
    {
        q->back->next = newNode;
        q->back = newNode;
    }
    else
    {
        q->front = newNode;
        q->back = newNode;
    }
    return newNode;
}

Node *deleteFromHead(Queue *q)
{
    if (q->front == NULL)
    {
        return NULL;
    }
    if (q->front == q->back)
    {
        Node *currHead = q->front;
        q->front = NULL;
        q->back = NULL;
        free(currHead);
        return NULL;
    }
    Node *currHead = q->front;
    Node *newHead = q->front->next;
    currHead->next = NULL;
    free(currHead);
    return newHead;
}

Queue *initQ()
{
    Queue *q = malloc(sizeof(Queue));
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}

Queue *readQ()
{
    Queue *q = initQ();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        insert(q, temp);
    }
    return q;
}

void printQ(Queue *q)
{
    Node *curr = q->front;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void insert(Queue *q, int val)
{
    q->back = insertAtTail(q, val);
    q->size = (q->size) + 1;
    return;
}

void pop(Queue *q)
{
    if (q->size == 0)
        return;
    deleteFromHead(q);
    q->size = (q->size) - 1;
    return;
}

int front(Queue *q)
{
    if (q->size == 0)
        return -1;
    return q->front->data;
}

int size(Queue *q)
{
    return q->size;
}

int isEmpty(Queue *q)
{
    return (q->size == 0);
}

void clear(Queue *q)
{
    while (size(q) > 0)
    {
        pop(q);
    }
    return;
}