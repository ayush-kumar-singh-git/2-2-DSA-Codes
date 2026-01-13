#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node_t{
    int data;
    struct Node_t* next;
}Node;

Node* createNode(int val);
Node* addToList(Node* head, int val);
Node *addNode(Node* head, Node* newNode);
Node* readList();
void printList(Node* head);
Node* rotate(Node* head, int k);
int lenList(Node* head);

int main()
{
    Node* list = readList();
    // printList(list);
    // Node* median= getMedian(list);
    // printf("%d\n", median->data);
    // list = reverseList(list);
    // printList(list);
    int k;
    scanf("%d", &k);
    list = rotate(list,k);
    printList(list);
    return 0;
}

Node* createNode(int val){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

Node* addToList(Node* head, int val){
    Node* newNode = createNode(val);
    if(head==NULL){
        head = newNode;
    }else{
        Node* curr = head;
        while(curr->next != NULL) curr = (curr->next);
        curr->next = newNode;
    }
    return head;
}

Node* readList(){
    int n;
    scanf("%d", &n);
    Node* head = NULL;
    while(n--){
        int temp;
        scanf("%d", &temp);
        head = addToList(head, temp);
    }
    return head;
}

void printList(Node* head){
    Node* curr = head;
    while(curr!=0){
        printf("%d ", curr->data);
        curr = (curr->next);
    }
    printf("\n");
}

Node *addNode(Node* head, Node* newNode){
    if(head==NULL){
        head = newNode;
    }else{
        Node* curr = head;
        while(curr->next != NULL) curr = (curr->next);
        curr->next = newNode;
    }
    return head;
}

int lenList(Node* head){
    Node* curr = head;
    int len = 0;
    while(curr){
        len++;
        curr = curr->next;
    }
    return len;
}
Node* rotate(Node* head, int k){
    int n = lenList(head);
    k = (k%n);
    if(k==0) return head;
    Node* slow = head;
    Node* fast = head;
    int kcpy=k;
    while(kcpy--){
        fast=fast->next;
    }
    while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    Node* newHead = slow->next;
    slow->next = NULL;
    fast->next = head;
return newHead;
}

