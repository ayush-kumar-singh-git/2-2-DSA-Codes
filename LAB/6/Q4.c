#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct Pair_t{
    int ff;
    int ss;
}Pair;

Pair* createPair(int x){
    Pair* newPair = malloc(sizeof(Pair));
    newPair -> ff = x;
    newPair -> ss = 0;
    return newPair;
}

int topIdx = -1;

int min(int a, int b){
    return a<=b? a:b;
}

int isEmpty(Pair* stk[]){
    return topIdx == -1;
}

Pair* top(Pair* stk[]){
    return stk[topIdx];
}

void pop(Pair* stk[]){
    topIdx --;
}

void push(Pair* stk[], int x){
    Pair* newPair = createPair(x);
    if(isEmpty(stk)){
        newPair->ss = newPair->ff;
    }else{
        newPair->ss = min(newPair->ff, top(stk)->ss);
    }
    stk[++topIdx] = newPair;
    return;
}


int main()
{
    int n;
    scanf("%d", &n);
    Pair* stk[MAX];
    Pair inp[n];
    for(int i=0;i<n;i++){
        scanf("%d", &inp[i].ff);
        if(inp[i].ff==1){
            scanf("%d", &inp[i].ss);
        }
    }
    for(int i=0;i<n;i++){
        int op = inp[i].ff;
        if(op==1){
            push(stk,inp[i].ss);
        }else if(op==2){
            if(isEmpty(stk)){
                printf("Stack Empty\n");
                continue;
            }
            printf("Popped: %d\n", top(stk)->ff);
            pop(stk);
        }else if(op==3){
            if(isEmpty(stk)){
                printf("Stack Empty\n");
                continue;
            }
            printf("Minimum: %d\n", top(stk)->ss);
        }else if(op==4){
            if(isEmpty(stk)){
                printf("Stack Empty\n");
                continue;
            }
            printf("Top: %d\n", top(stk)->ff);
        }
    }
    return 0;
}
