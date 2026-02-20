#include <stdio.h>
#include <stdlib.h>

int pTop = -1;
int sTop = -1;

int peek(int* pstk, int* sstk){
    if(pTop==-1) return -1;
    return pstk[pTop];
}

int dequeue(int* pstk, int* sstk){
    if(pTop==-1) return -1;
    int val = peek(pstk, sstk);
    pTop--;
    return val;
}

void enqueue(int* pstk, int* sstk, int x){
    while(pTop!=-1){
        sstk[++sTop] = pstk[pTop--];
    }
    pstk[++pTop] = x;
    while(sTop!=-1){
        pstk[++pTop] = sstk[sTop--];
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    int a[T], b[T];
    int pStk[1000], sStk[1000];
    for(int i=0;i<T;i++){
        scanf("%d", &a[i]);
        if(a[i]==1){
            scanf("%d", &b[i]);
        }
    }
    for(int i=0;i<T;i++){
        if(a[i]==1){
            enqueue(pStk, sStk, b[i]);
        }else if(a[i]==2){
            printf("%d\n", dequeue(pStk, sStk));
        }else{
            printf("%d\n", peek(pStk, sStk));
        }
    }
    return 0;
}
