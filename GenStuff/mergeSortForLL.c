#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t{
    int data;
    struct Node_t* next;
}Node;

Node* createNode(int val){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
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
        int temp;
        scanf("%d", &temp);
        head = addToList(head, temp);
    }
    return head;
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

Node* mergeSortedll(Node* h1, Node* h2){
    Node* newList = NULL;
    Node* c1 = h1, *c2 = h2;
    while(c1 && c2){
        if(c1->data <= c2->data){
            newList = addToList(newList, c1->data);
            c1 = c1 -> next;
        }else{
            newList = addToList(newList, c2->data);
            c2 = c2 -> next;
        }
    }
    while(c1){
            newList = addToList(newList, c1->data);
            c1 = c1 -> next;
    }
    while(c2){
        newList = addToList(newList, c2->data);
            c2 = c2 -> next;
    }
    return newList;
}

Node* mergeSort(Node* head){
    if(!head || !(head->next)) return head;
    Node* m = getMedian(head);
    Node* newHead = m->next;
    m -> next = NULL;
    Node* left = mergeSort(head);
    Node* right = mergeSort(newHead);
    Node* final = mergeSortedll(left, right);
    return final;
}

void printLL(Node* head){
    Node* curr = head;
    while(curr->next){
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("%d\n", curr->data);
}

int main()
{
    Node* list = readList();
    list = mergeSort(list);
    printLL(list);
    return 0;
}
