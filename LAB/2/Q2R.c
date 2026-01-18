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

Node* addNodeToList(Node* head, Node* newNode){
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

Node* separate(Node* head){
    Node* odd = NULL;
    Node* even = NULL;
    Node* curr = head;
    while(curr){
        Node* nextCurr = curr->next;
        curr->next = NULL;
        if((curr->data)%2){
            odd = addNodeToList(odd, curr);
        }else{
            even = addNodeToList(even, curr);
        }
        curr = nextCurr;
    }
    if(odd == NULL) return even;
    if(even == NULL) return odd;
    curr = even;
    while(curr->next) curr = curr->next;
    curr->next=odd;
    return even;
}
int main()
{
    Node* head = readList();
    head = separate(head);
    printList(head);
    return 0;
}


