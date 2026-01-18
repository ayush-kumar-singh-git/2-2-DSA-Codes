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

Node* insertSum(Node* head){
    if(!head || !(head->next)) return head;
    Node* one = head;
    Node* two = head -> next;
    while(one && two){
        Node* nextOne = two -> next;
        Node* sum = createNode(one->data+two->data);
        two -> next = sum;
        sum -> next = nextOne;
        one = nextOne;
        if(!one) break;
        two = nextOne -> next;
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

int main()
{
    Node* head = readList();
    head = insertSum(head);
    printList(head);
    return 0;
}

