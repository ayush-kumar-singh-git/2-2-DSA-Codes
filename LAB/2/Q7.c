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
Node* moveAll(Node* head, int x);

int main()
{
    Node* list = readList();
    int x;
    scanf("%d", &x);
    list = moveAll(list, x);
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

Node* moveAll(Node* head, int x){
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
