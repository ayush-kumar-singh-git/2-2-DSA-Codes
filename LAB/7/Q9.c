#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int q[MAX];
int stk[MAX];

int front = -1;
int back = -1;
int top =-1;

void enqueue(int x){
    if(front==-1 && back==-1){
        front=back=0;
    }else{
        back++;
    }
    q[back] = x;
}

int dequeue(){
    return q[front++];
}

void push(int x){
    stk[++top] = x;
}

int pop(){
    return stk[top--];
}

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d", &temp);
        enqueue(temp);
    }
    for(int i=0;i<n;i++){
        push(dequeue());
    }
    for(int i=0;i<n;i++){
        enqueue(pop());
    }
    for(int i=0;i<n-k;i++){
        push(dequeue());
    }
    for(int i=0;i<n-k;i++){
        enqueue(pop());
    }
    for(int i=0;i<n;i++){
        printf("%d ", dequeue());
    }
    printf("\n");
    return 0;
}
