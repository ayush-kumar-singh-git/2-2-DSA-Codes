// TC is O(n^2) but can be optimized to O(n), however the question doesnot ask for it
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

Node* addNode(Node* head, Node* newNode){
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

Node* mvX(Node* head, int x){
    Node* prev = NULL;
    Node* curr = head;
    Node* otherHead = NULL;
    while(curr){
        if(curr->data==x){
            if(prev){
                prev -> next = curr -> next;
                Node* temp = curr;
                curr = curr -> next;
                temp->next=NULL;
                otherHead=addNode(otherHead, temp);
            }else{
                head = curr->next;
                Node* temp = curr;
                curr = curr -> next;
                temp -> next = NULL;
                otherHead=addNode(otherHead, temp);
            }
        }else{
            prev = curr;
            curr = curr -> next;
        }
    }
    curr=  head;
    if(!curr) return otherHead;
    while(curr->next){
        curr= curr->next;
    }
    curr->next = otherHead;
    return head;
}

int main()
{
    Node* head = readList();
    int x;
    scanf("%d", &x);
    head = mvX(head,x);
    printList(head);
    return 0;
}



