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
Node* readBigInt(int n);
void addBigInt();
void printBigInt(Node* head);
void printCommon(Node* h1, Node* h2);

int main()
{
    // Node* list = readList();
    // maxDupFreq(list);
    // addBigInt();
    Node* one = readList();
    Node* two = readList();
    printCommon(one, two);
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

Node* readBigInt(int n){
    Node* head = NULL;
    while(n--){
        char temp;
        scanf(" %c", &temp);
        head = addToList(head, temp-'0');
    }
    return head;
}

void addBigInt(){
    int m,n;
    scanf("%d", &m);
    Node* num1 = readBigInt(m);
    scanf("%d", &n);
    Node* num2 = readBigInt(n);
    num1 = reverseList(num1); // this step is not needed if you read optimally in O(n), ie insert at head and stuff
    num2 = reverseList(num2); // same as above
    Node* ans = NULL;
    int carry = 0;
    Node* curr1 = num1;
    Node* curr2 = num2;
    while( curr1 && curr2){
        int total = curr1->data + curr2->data + carry;
        int val = total%10;
        carry = total/10;
        ans = addToList(ans, val);
        curr1 = curr1->next;
        curr2 = curr2 -> next;
    }
    while(curr1){
    int total = curr1->data + carry;
    ans = addToList(ans, total % 10);
    carry = total / 10;
    curr1 = curr1->next;
}

while(curr2){
    int total = curr2->data + carry;
    ans = addToList(ans, total % 10);
    carry = total / 10;
    curr2 = curr2->next;
}

    while(carry>0){
        ans = addToList(ans, carry%10);
        carry/=10;
    }
    ans = reverseList(ans);
    printBigInt(ans);
}

void printBigInt(Node* head){
    Node* curr = head;
    while(curr){
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void printCommon(Node* h1, Node* h2){
    // assuming the given linked lists are sorted
    Node* c1 = h1;
    Node* c2 = h2;
    int last = -100000000;
    while(c1 && c2){
        if(c1->data == c2->data){
            if(last == c1->data){
                c1 = c1 -> next;
                c2 = c2 -> next;
            }else{
                last = c1 -> data;
                printf("%d ", last);                
                c1 = c1 -> next;
                c2 = c2 -> next;
            }
        }else if(c1->data < c2->data){
            c1 = c1 -> next;
        }else{
            c2 = c2 -> next;
        }
    }
    printf("\n");
    return;
}
