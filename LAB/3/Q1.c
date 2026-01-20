#include <stdio.h>
#include <stdlib.h>

typedef struct Data_t{
    int marks;
    int delay;
}Data;

int compareData(Data d1, Data d2){
    if(d1.marks>d2.marks) return 1;
    if(d1.marks == d2.marks && (d1.delay<d2.delay)) return 1;
    return 0;
}

void swap(Data* d1, Data* d2){
    Data temp = *d1;
    *d1 = *d2;
    *d2 = temp;
    return;
}

void bubble(Data* d, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0; j<n-i; j++){
            if(compareData(d[j+1], d[j])) swap(&d[j+1], &d[j]);
        }
    }
}

void print(Data* d, int n){
    for(int i=0;i<n;i++){
        printf("%d %d\n", d[i].marks, d[i].delay);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Data d[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&d[i].marks, &d[i].delay);
    }
    bubble(d,n);
    print(d,n);
    return 0;
}
