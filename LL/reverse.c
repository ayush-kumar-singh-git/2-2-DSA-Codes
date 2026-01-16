#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t{
    int data;
    struct Node_t* next;
}Node;

// Necessary Functions
Node* createNode(int val); // O(1)
Node* addToList(Node* head, int val); // O(n)
Node* readList(); // O(n^2) - but can be improved
void printList(Node* head); // O(n)

Node* reverse(Node* head); // O(n)

int main()
{
    Node* head = readList();
    printList(head);
    head = reverse(head);
    printList(head);
    return 0;
}

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
    while(curr->next) curr=curr->next;
    curr -> next = newNode;
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
    while(curr){
        printf("%d -> ", curr->data);
        curr = curr->next;
        if(curr -> next == NULL){
            printf("%d\n", curr->data);
            curr = curr -> next;
        }
    }
    return;
}

Node* reverse(Node* head){
    if(!head || !(head->next)) return head;
    Node* curr = head;
    Node* toBeTail = curr -> next;
    curr -> next = NULL;
    Node* newHead = reverse(toBeTail);
    toBeTail -> next = curr;
    return newHead;
}
