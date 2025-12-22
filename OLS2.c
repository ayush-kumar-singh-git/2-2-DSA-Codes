#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// Linked List Implementation
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

int findMedian(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (true)
    {
        if (fast->next == NULL)
        {
            return slow->data;
        }
        if (fast->next->next == NULL)
        {
            return (((slow->data) + (slow->next->data)) / 2);
        }
        slow = slow->next;
        fast = fast->next->next;
    }
}

Node *mergeLists(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
        return NULL;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    if (head1->data < head2->data)
    {
        head1->next = mergeLists(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = mergeLists(head1, head2->next);
        return head2;
    }
    return NULL;
}

Node *getMedian(Node *head)
{
    Node *slow = head;
    Node *fast = head->next; // important if we use head we get seg fault
    while (true)
    {
        if (fast == NULL || fast->next == NULL)
        {
            return slow;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return NULL;
}

Node *sortList(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    Node *left = head;
    Node *mid = getMedian(head);
    Node *right = mid->next;
    mid->next = NULL;
    left = sortList(left);
    right = sortList(right);
    return mergeLists(left, right);
}

Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    Node *head = readList();
    head = reverseList(head);
    printList(head);
    freeList(head);

    return 0;
}