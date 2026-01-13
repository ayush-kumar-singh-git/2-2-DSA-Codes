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
Node* readList();
void printList(Node* head);
Node* getMedian(Node* head);
Node* reverseList(Node* head);
int isPal(Node* head);

int main()
{
    Node* list = readList();
    printList(list);
    // Node* median= getMedian(list);
    // printf("%d\n", median->data);
    // list = reverseList(list);
    // printList(list);
    if(isPal(list)) printf("True\n");
    else printf("False\n");
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

Node* getMedian(Node* head){
    if(head==NULL || head->next == NULL) return head;
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* reverseList(Node* head){
    if(!head || !(head->next)) return head;
    Node* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int isPal(Node* head){
    if(!head || !(head->next)) return TRUE;
    Node* median = getMedian(head);
    Node* left = head;
    Node* nextHead = reverseList(median->next);
    median->next = nextHead;
    Node* right = median->next;
    while(right){
        if(left->data != right->data) return FALSE;
        left = left ->next;
        right = right->next;
    }
    return TRUE;
}
