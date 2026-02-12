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
    return stack[topIdx];
}

int ok(char* s, int l, int r){
    int stk[MAX];
    topIdx = -1;
    for(int i=l;i<=r;i++){
        if(s[i]=='('){
            push(stk,1);
        }else{
            if(topIdx==-1) return 0;
            pop(stk);
        }
    }
    return topIdx == -1 ? 1 : 0;
}

int max(int a, int b){ return a>=b ? a : b; }

int main()
{
    char in[1000];
    scanf("%s", in);
    int n = 0;
    while(in[n]!='\0') n++;
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ok(in,i,j)){
                ans = max(ans, j-i+1);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
