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
Node* IncSeq(Node* head);

int main()
{
    Node* list = readList();
    list = IncSeq(list);
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
        if(curr->next!=NULL)
        printf("%d -> ", curr->data);
        else 
        printf("%d\n", curr->data);
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

Node* IncSeq(Node* head){
    Node* prev = head;
    int prevVal = head -> data; 
    Node* curr = head->next;
    while(curr){
        if(curr->data > prevVal){
            prevVal = curr->data;
            prev = curr;
            curr = curr->next;
        }else{
            Node* toGo = curr->next;
            curr->next = NULL;
            Node* temp = curr;
            curr = toGo;
            prev -> next = toGo;
            free(temp);
        }
    }
    return head;
}
