/*
 * Logic : Brutte Force
 * TC O(n^3)
 * SC O(1) other than the input list
 */
#include <stdio.h>
#include <stdlib.h>

void bubble(int* a,int n, int l, int r){
    int swapped = 0;
    do{
        swapped = 0;
        for(int j=l;j<r;j++){
            if(a[j+1]<a[j]){
                int t= a[j];
                a[j] =a[j+1];
                a[j+1]=t;
                swapped =1;
            }
        }
    }while(swapped==1);
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int curr = 1;
    int st = 0, end = n-1;
    while(1){
        if(curr%2==1){
            if(st+curr-1>end){
                bubble(a,n,st,end);
                break;
            }else{
                bubble(a,n,st,st+curr-1);
                st = st+curr;
            }
        }else{
            if(end-curr+1<st){
                bubble(a,n,st,end);
                break;
            }else{
                bubble(a,n,end-curr+1, end);
                end = end - curr;
            }
        }
        curr++;
    }
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
