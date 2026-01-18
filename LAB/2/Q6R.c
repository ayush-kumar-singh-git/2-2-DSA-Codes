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
    while(curr->next){
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("%d\n", curr->data);
}

Node* incSeq(Node* head){
    if(!head || !(head->next)) return head;
    Node* prev = head;
    Node* curr = head->next;
    while(curr){
        if(curr->data > prev->data){
            prev = curr;
            curr = curr->next;
        }else{
            Node* toDispose = curr;
            prev->next = curr->next;
            curr = curr->next;
            toDispose->next = NULL;
            free(toDispose);
        }
    }
    return head;
}

int main()
{
    Node* head = readList();
    head = incSeq(head);
    printList(head);
    return 0;
}
