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

int len(Node* head){
    Node* curr = head;
    int l=0;
    while(curr){
        l++;
        curr = curr->next;
    }
    return l;
}

Node* rotate(Node* head, int k){
    if(!head) return head;
    int n = len(head);
    k = k%(n);
    k = n-k;
    if(k==0) return head;
    Node* kthNode = head;
    for(int i = 1; i < k; i++){
        kthNode = kthNode->next;
    }
    Node* newHead = kthNode -> next;
    kthNode -> next = NULL;
    Node* curr = newHead;
    while(curr->next) curr = curr->next;
    curr ->next = head;
    return newHead;
}

int main()
{
    Node* head = readList();
    int k;
    scanf("%d", &k);
    head = rotate(head, k);
    printList(head);
    return 0;
}


