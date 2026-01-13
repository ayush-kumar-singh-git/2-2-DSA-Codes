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
Node* separate(Node* head);

int main()
{
    Node* list = readList();
    // printList(list);
    // Node* median= getMedian(list);
    // printf("%d\n", median->data);
    // list = reverseList(list);
    // printList(list);
    list = separate(list);
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

Node* separate(Node* head){
    Node* odd = NULL;
    Node* even = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* toGo = curr->next;
        curr -> next = NULL;
        if((curr->data)%2==1){
            odd = addNode(odd, curr);
        }else{
            even = addNode(even, curr);
        }
        curr = toGo;
    }
    if(!even) return odd;
    Node* evenEnd = even;
    while(evenEnd->next!=NULL) evenEnd = evenEnd->next;
    evenEnd->next = odd;
    return even;
}
