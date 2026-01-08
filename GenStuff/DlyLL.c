#include <stdio.h>
#include <stdlib.h>

// structs used
typedef struct Node_t
{
    int data;
    struct Node_t *next;
    struct Node_t *prev;
} Node;

typedef struct doublyLinkedList
{
    Node *head;
    Node *tail;
    int size;
} DLL;

// functions to be defined - will do someother day

Node *createNode(int val);
Node *insertAtHead(int val);
Node *insertAtTail(int val);
Node *deleteFromHead(DLL *dll);
Node *deleteFromTail(DLL *dll);
DLL *init();
DLL *readDLL();
void push_front(DLL *dll, int val);
void push_back(DLL *dll, int val);
void pop_front(DLL *dll);
void pop_back(DLL *dll);
int front(DLL *dll);
int back(DLL *dll);
int size(DLL *dll);
int printDLL(DLL *dll);
int isEmpty(DLL *dll);
void clearDLL(DLL *dll);

int main()
{

    return 0;
}