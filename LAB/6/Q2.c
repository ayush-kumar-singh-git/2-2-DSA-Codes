#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int topIdx = -1;

int isEmpty(int* stack){
    return topIdx == -1;
}

void push(int* stack, int x){
    stack[++topIdx] = x;
}

void pop(int* stack){
    if(!isEmpty(stack)) topIdx--;
}

int top(int* stack){
    if(!isEmpty(stack)) return stack[topIdx];
    else{
        printf("The Stack Is Empty\n");
    }
    return -1;
}

int main()
{
    int stk[MAX];
    int n;
    scanf("%d", &n);
    int a[n];
    int ans[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=n-1;i>=0;i--){
        while(!isEmpty(stk) && a[top(stk)]<=a[i]) pop(stk);
        if(isEmpty(stk)) ans[i]=0;
        else ans[i] = top(stk) - i;
        push(stk,i);
    }
    for(int i=0;i<n;i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}

