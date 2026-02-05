#include <stdio.h>
#include <stdlib.h>

typedef struct Trip_t{
    int ff;
    int ss;
    int tt;
}Trip;

int cmp(Trip p1, Trip p2){
    if(p1.ff!=p2.ff) return p1.ff<p2.ff;
    if(p1.ss!=p2.ss) return p1.ss<p2.ss;
    return p1.tt<p2.tt;
}

void bubbleTrip(Trip* a, int n){
    int swapped = 0;
    do{
        swapped = 0;
        for(int i=0;i<n-1;i++){
            if(cmp(a[i+1], a[i])){
                swapped =1;
                Trip p = a[i];
                a[i]= a[i+1];
                a[i+1]=p;
            }
        }
    }while(swapped);
}
int equal(Trip t1, Trip t2){
    return (t1.ff==t2.ff) && (t1.ss==t2.ss) && (t1.tt==t2.tt);
}

void bubbleInt(int* a, int n){
    int swapped = 0;
    do{
        swapped = 0;
        for(int i=0;i<n-1;i++){
            if(a[i+1]<a[i]){
                int t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
                swapped = 1;
            }
        }
    }while(swapped);
}

int* order(int a, int b, int c){
    int* arr  = (int*) calloc(3, sizeof(int));
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;
    bubbleInt(arr,3);
    return arr;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0;i<n;i++){
        scanf("%d", &a[i]);    
    }
    int x  = 0;
    Trip ans[1000];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]+a[k]==0){
                    int* v = order(a[i],a[j],a[k]);
                    ans[x].ff = v[0];
                    ans[x].ss = v[1];
                    ans[x].tt = v[2];
                    free(v);
                    x++;
                }
            }
        }
    }
    if(x==0){
        printf("No triplets found\n");
        return 0;
    }
    bubbleTrip(ans, x);
    int i =0;
    while(i<x){
        int j = i+1;
        while(j<x && equal(ans[j], ans[i])) j++;
        printf("%d %d %d\n", ans[i].ff, ans[i].ss, ans[i].tt);
        i=j;
    }
    return 0;
}
