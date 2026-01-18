// Recursion uses O(n) stack space which can be otimised by iterative reversing
// Did not handle malloc failure - but lite
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

void printList(Node* head){
    Node* curr = head;
    while(curr){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

Node* getMid(Node* head){
    if(!head || !(head -> next)) return head;
    Node* slow = head;
    Node* fast = head -> next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast -> next -> next;
    }
    return slow;
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

int isPal(Node* head){
    if (!head || !head->next) return 1;
    Node* mid = getMid(head);
    Node* right = mid->next;
    mid->next = NULL;
    right = reverse(right);
    Node* curr1 = head;
    Node* curr2 = right;
    int res = 1;
    while(curr2){
        if(curr1->data!=curr2->data){
            res = 0;
            break;
        }
        curr1 = curr1 -> next;
        curr2 = curr2->next;
    }
    // restoring tehe original ll (optional)
    right = reverse(right);
    mid -> next = right;
    return res;
}

int main()
{
    Node* head = readList();
    if(isPal(head)) printf("True\n");
    else printf("False\n");
    return 0;
}
