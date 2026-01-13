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
Node* modify(Node* head);

int main()
{
    Node* list = readList();
    // printList(list);
    // Node* median= getMedian(list);
    // printf("%d\n", median->data);
    // list = reverseList(list);
    // printList(list);
    list = modify(list);
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

Node* modify(Node* head){
    if(!head || !(head->next)) return head;
    Node* slow = head;
    Node* fast = head->next;
    while(slow && fast){
        Node* sumNode = createNode(slow->data + fast->data);
        Node* nSlow = fast->next;
        Node* nFast;
        if(nSlow)
        nFast = nSlow->next;
        else nFast = NULL;
        fast->next =sumNode;
        sumNode ->next = nSlow;
        slow = nSlow;
        fast = nFast;
    }
    return head;
}

