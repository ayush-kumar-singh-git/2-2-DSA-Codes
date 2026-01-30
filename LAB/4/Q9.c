/*
 * Logic : Simple Brute force
 * TC O(n^2)
 * SC O(1) other than the input list
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Pair_t{
    int x;
    int y;
}Pair;

int cmp(Pair p1, Pair p2){
    if(p1.x==p2.x){
        return p1.y<p2.y;
    }
    return p1.x<p2.x;
}

void bubble(Pair list[], int n){
    int swapped = 0;
    do{
        swapped = 0;
        for(int i=0;i<n-1;i++){
            if(cmp(list[i+1], list[i])){
                Pair temp = list[i];
                list[i] = list[i+1];
                list[i+1] = temp;
                swapped = 1;
            }
        }
    }while(swapped==1);
}

int main()
{
    int n;
    scanf("%d", &n);
    Pair list[n];
    for(int i=0;i<n;i++){
        scanf("%d %d", &list[i].x, &list[i].y);
    }
    bubble(list,n);
    int contigious = 1;
    int Y=list[0].y;
    for(int i=1;i<n;i++){
        int xx = list[i].x;
        int yy = list[i].y;
        if(xx > Y){
            contigious = 0;
            break;
        }
        if(yy>Y) Y=yy;   
    }
    for(int i=0;i<n;i++){
        printf("%d %d\n", list[i].x, list[i].y);
    }
    if(contigious) printf("Contiguous\n");
    else printf("Fragmented\n");
    return 0;
}
