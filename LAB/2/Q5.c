#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t{
    int data;
    struct Node_t* next;
}Node;

Node* createNode(int val);
Node* addToList(Node* head, int val);
Node *addNode(Node* head, Node* newNode);
Node* readList();
void printList(Node* head);
Node* swapInPairs(Node* head);
Node* swapInPairsItr(Node* head);

int main()
{
    Node* list = readList();
    list = swapInPairsItr(list);
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

Node* swapInPairs(Node* head){
    if(!head || !(head -> next)) return head;
    Node* one = head;
    Node* two = head -> next;
    Node* newHead = two -> next;
    two -> next = one;
    one -> next = swapInPairs(newHead);
    return two;
}

Node* swapInPairsItr(Node* head){
    if(!head || !(head->next)) return head;
    Node* ances = NULL;
    Node* prev = head;
    Node* curr = head -> next;
    head = curr;
    while(1){
        Node* nextNode = curr -> next;
        Node* nextAnces = prev;
        curr -> next = prev;
        prev -> next = nextNode;
        if(ances!=NULL)
        ances -> next = curr;
        if(!nextNode || !(nextNode->next)) break;
        prev = nextNode;
        curr = nextNode -> next;
        ances = nextAnces;
    }
    return head;
}
