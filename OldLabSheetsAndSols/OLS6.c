#include <stdio.h>
#include <stdlib.h>

// stuff for dbly linked list (our jugaad for deque)

typedef struct Node_t
{
    int data;
    struct Node_t *prev;
    struct Node_t *next;
} Node;

Node *createNode(int val);
Node *push_back(Node *listTail, Node *newNode);
Node *push_front(Node *listHead, Node *newNode);
void printList(Node *listHead);

// solutions
void problemD();
void problemF();

int main()
{
    problemF();
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

Node *push_back(Node *listTail, Node *newNode)
{
    if (listTail == NULL)
        return newNode;
    Node *curr = listTail;
    newNode->prev = curr;
    curr->next = newNode;
    return newNode;
}

Node *push_front(Node *listHead, Node *newNode)
{
    if (listHead == NULL)
        return newNode;
    Node *curr = listHead;
    newNode->next = curr;
    curr->prev = newNode;
    listHead = newNode;
    return listHead;
}

void printList(Node *listHead)
{
    Node *curr = listHead;
    while (curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    return;
}

void problemD()
{
    int n;
    scanf("%d", &n);
    int arr[n], ans[n]; // ans is not needed as such, can just print
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *freq = (int *)calloc(n, sizeof(int)); // used calloc only to intitialize to null
    int q[n];                                  // using array as queue
    int st = 0, end = 0;                       // start and end of the queue
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        q[end] = arr[i];
        end++;
        while (st < end && freq[q[st]] > 1)
        {
            st++;
        }
        if (st == end)
            ans[i] = -1;
        else
            ans[i] = q[st];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return;
}

void problemF()
{
    // we will use a doubly linked list to simulate deque
    int n;
    scanf("%d", &n);
    Node *listHead = NULL;
    Node *listTail = NULL;
    int curr;
    scanf("%d", &curr);
    Node *newNode = createNode(curr);
    listHead = push_front(listHead, newNode);
    listTail = listHead;
    for (int i = 1; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        Node *newNode = createNode(temp);
        if (temp < curr)
        {
            listHead = push_front(listHead, newNode);
            curr = temp;
        }
        else
        {
            listTail = push_back(listTail, newNode);
        }
    }
    printList(listHead);
}