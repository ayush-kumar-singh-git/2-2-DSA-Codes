#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t{
    int data;
    struct  Node_t* next;
}Node;

Node* createNode(int val){
    Node* newNode = malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}

Node* addToList(Node* head, int val){
    Node* newNode = createNode(val);
    if(!head) return newNode;
    Node* curr = head;
    while(curr->next) curr = curr->next;
    curr->next = newNode;
    return head;
}

Node* readList(){
    int n;
    scanf("%d", &n);
    Node* head = NULL;
    while(n--){
        int t;
        scanf("%d", &t);
        head = addToList(head, t);
    }
    return head;
}

void printList(Node* head){
    Node* curr = head;
    while(curr){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

Node* swapNodesInPair(Node* head){
    if(!head || !(head->next)) return head;
    Node* nextNode = head->next->next;
    Node* immNext = head->next;
    immNext->next = head;
    head->next = swapNodesInPair(nextNode);
    return immNext;
}

int main()
{
    Node* head = readList();
    head = swapNodesInPair(head);
    printList(head);
    return 0;
}

