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
Node* reverseList(Node* head);
void maxDupFreq(Node* head);

int main()
{
    Node* list = readList();
    maxDupFreq(list);
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

Node* reverseList(Node* head){
    if(!head || !(head->next)) return head;
    Node* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}


void maxDupFreq(Node* head){
    Node* curr = head->next;
    int maxFreq = 1;
    int ans = head->data;
    int prev = head->data;
    int cf = 1;
    while(curr){
        if(curr->data == prev){
            cf++;
            if(cf>maxFreq){
                maxFreq = cf;
                ans = curr->data;
            }
        }else{
            cf = 1;
            prev = curr->data;
        }
        curr = curr->next;
    }
    if(maxFreq>1) printf("%d\n", ans);
    else printf("-1\n");
}
