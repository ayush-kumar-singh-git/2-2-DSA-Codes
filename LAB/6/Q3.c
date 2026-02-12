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

int max(int a, int b){ return a>=b? a: b; }

void print(int* a, int n){
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int stk[MAX];
    int pmin[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        while(!isEmpty(stk) && a[top(stk)]>=a[i]) pop(stk);
        if(isEmpty(stk)) pmin[i] = -1;
        else pmin[i] = top(stk);
        push(stk, i);
    }
    //print(pmin,n);
    topIdx = -1;
    int nmin[n];
    for(int i=n-1;i>=0;i--){
        while(!isEmpty(stk) && a[top(stk)]>=a[i]) pop(stk);
        if(isEmpty(stk)) nmin[i] = n;
        else nmin[i] = top(stk);
        push(stk, i);
    }
    //print(nmin,n);
    int ans = 0;
    for(int i =0;i<n;i++){
        int area = (nmin[i]-pmin[i]-1)*a[i];
        area = max(area, a[i]);
        ans = max(ans, area);
    }
    printf("%d\n", ans);
    return 0;
}

