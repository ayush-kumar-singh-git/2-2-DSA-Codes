#include <stdio.h>
#include <stdlib.h>

typedef struct Pair_t{
    int ff;
    int ss;
}Pair;

int cmp(Pair p1, Pair p2){
    if(p1.ff!=p2.ff) return p1.ff<p2.ff;
    return p1.ss>p2.ss;
}

void bubble(Pair* a, int n){
    int swapped = 0;
    do{
        swapped = 0;
        for(int i=0;i<n-1;i++){
            if(cmp(a[i+1], a[i])){
                swapped =1;
                Pair p = a[i];
                a[i]= a[i+1];
                a[i+1]=p;
            }
        }
    }while(swapped);
}

int main()
{
    int n;
    scanf("%d", &n);
    Pair a[n];
    for(int i=0;i<n;i++){
        scanf("%d %d", &a[i].ff, &a[i].ss);
    }
    bubble(a,n);
    int st = a[0].ff, end = a[0].ss;
    for(int i = 1; i < n; i++){
        if(a[i].ff <= end){
            if(a[i].ss > end)
                end = a[i].ss;
        } else {
            printf("%d %d\n", st, end);
            st = a[i].ff;
            end = a[i].ss;
        }
    }
    printf("%d %d\n", st, end);
    return 0;
}
