// needs some minor improvements - eg size handling and malloc failure handling

#include <stdio.h>
#include <stdlib.h>

// structs used

typedef struct Node_t
{
    int data;
    struct Node_t *next;
} Node;

typedef struct Stack_t
{
    Node *top;
    int size;
} Stack;

// These are the implemented functions

Node *createNode(int val);
Node *insertAtHead(Stack *stk, int val);
Node *deleteFromHead(Stack *stk);
Stack *initStack();
Stack *readStack();
void printStack(Stack *stk);
void push(Stack *stk, int val);
void pop(Stack *stk);
int top(Stack *stk);
int size(Stack *stk);
int isEmpty(Stack *stk);
void clear(Stack *stk);

int main()
{
    Stack *stk = readStack();
    printf("Size: %d\n", size(stk));
    printStack(stk);
    pop(stk);
    pop(stk);
    printf("Size: %d\n", size(stk));
    printStack(stk);
    push(stk, 100);
    printf("Size: %d\n", size(stk));
    printStack(stk);
    clear(stk);
    printf("Size: %d\n", size(stk));
    printStack(stk);
    return 0;
}

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtHead(Stack *stk, int val)
{
    Node *newHead = createNode(val);
    newHead->next = stk->top;
    return newHead;
}

Node *deleteFromHead(Stack *stk)
{
    if (stk->top == NULL)
    {
        return NULL;
    }
    Node *currHead = stk->top;
    Node *newHead = stk->top->next;
    currHead->next = NULL;
    free(currHead);
    return newHead;
}

Stack *initStack()
{
    Stack *stk = malloc(sizeof(Stack));
    stk->top = NULL;
    stk->size = 0;
    return stk;
}

void push(Stack *stk, int val)
{
    stk->top = insertAtHead(stk, val);
    stk->size = (stk->size) + 1;
    return;
}

void pop(Stack *stk)
{
    if (isEmpty(stk))
    {
        return;
    }
    stk->top = deleteFromHead(stk);
    stk->size = (stk->size) - 1;
    return;
}

int top(Stack *stk)
{
    if (isEmpty(stk))
    {
        return -1;
    }
    return stk->top->data;
}

int size(Stack *stk)
{
    return stk->size;
}

int isEmpty(Stack *stk)
{
    return (stk->size == 0);
}

void clear(Stack *stk)
{
    while (size(stk) > 0)
    {
        pop(stk);
    }
    return;
}

Stack *readStack()
{
    Stack *stk = initStack();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        push(stk, temp);
    }
    return stk;
}

void printStack(Stack *stk)
{
    Node *curr = stk->top;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    return;
}