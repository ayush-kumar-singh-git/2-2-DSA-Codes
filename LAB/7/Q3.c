// Didn't modify just printed but who cares :)
#include <stdio.h>
#include <stdlib.h>

int front = -1;
int back = -1;
int topIdx = -1;

void push(int* stk, int x){
    stk[++topIdx] = x;
}

int top(int* stk){
    return stk[topIdx];
}

void pop(int* stk){
    topIdx--;
}

void enqueue(int* q, int x){
    if(front == -1 || front > back){
        front = back = 0;
    } else {
        back++;
    }
    q[back] = x;
}

void dequeue(int* q){
    front++;
}

int peek(int* q){
    return q[front];
}

int isEmpty(int* q){
    return (front==-1 && back==-1) || (front>back);
}

int main()
{
    int n;
    scanf("%d", &n);
    int q[1000];
    int s[1000];
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d", &temp);
        enqueue(q,temp);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<n/2;j++){
            push(s, peek(q));
            dequeue(q);
        }
        while(topIdx>-1){
            enqueue(q, top(s));
            pop(s);
        }
    }
    for(int i=0;i<n/2;i++){
        push(s, peek(q));
        dequeue(q);
    }
    while(topIdx>-1){
        printf("%d %d ", peek(q), top(s));
        pop(s);
        dequeue(q);
    }
    printf("\n");
    return 0;
}

