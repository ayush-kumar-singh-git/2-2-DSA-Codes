#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t{
    int data;
    struct Node_t* right;
    struct Node_t* down;
}Node;

Node* createNode(int val){
    Node* newNode = malloc(sizeof(Node));
    newNode -> right = NULL;
    newNode -> down = NULL;
    newNode -> data = val;
    return newNode;
}

Node* append(Node* head, int val){
    Node* newNode = createNode(val);
    if(!head) return newNode;
    Node* curr = head;
    while(curr->right) curr = curr->right;
    curr -> right = newNode;
    return head;
}

void print(Node* head){
    if(!head){
        printf("\n");
        return;
    }
    Node* curr = head;
    while(curr){
        if(curr!=head)
            printf(" -> %d", curr->data);
        else 
            printf("%d", curr->data);
        curr = curr -> right;
    }
    printf("\n");
    if(head->down) printf("|\n");
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    Node* list[n];
    for(int i=0;i<n;i++){
        Node* head = createNode(i);
        for(int j=0;j<n;j++){
            int val;
            scanf("%d", &val);
            if(val){
                head = append(head, j);
            }
        }
        list[i] = head;
        if(i!=0) list[i-1]->down = head; 
    }
    printf("\n");
    for(int i=0;i<n;i++){
        print(list[i]);
    }
    return 0;
}
