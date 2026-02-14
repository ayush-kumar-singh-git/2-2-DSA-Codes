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
    int n;
    scanf("%d", &n);
    int a[n],b[n],ans[5*n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<n;i++) scanf("%d", &b[i]);
    int stk[MAX];
    int i = 0, j = 0, k = 0;
    while(i<n){
        push(stk, a[i]);
        ans[k++] = 1;
        i++;
        while(!isEmpty(stk) && top(stk) == b[j]){
            pop(stk);
            ans[k++] = -1;
            j++;
        }
    }
    if(j!=n){
        printf("Impossible\n");
    }else{
        for(int x=0;x<k;x++){
            if(ans[x]==1) printf("Push\n");
            else printf("Pop\n");
        }
    }
    return 0;
}

