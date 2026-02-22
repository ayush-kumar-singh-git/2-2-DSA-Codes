#include <stdio.h>
#include <stdlib.h>

int front = 5001;
int back = 5000;

int dq[10000];

void push_front(int x){
    dq[--front] = x;    
}

void push_back(int x){
    dq[++back] = x;
}

void pop_back(){
    back--;
}

void pop_front(){
    front++;
}

int get_front(){
    return dq[front];
}

int get_back(){
    return dq[back];
}

int isEmpty(){
    return front > back;
}

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<k;i++){
        while(!isEmpty() && a[get_back()]<=a[i]){
            pop_back();
        }
        push_back(i);
    }
    int ans[10000];
    int idx=0;
    ans[idx++] = a[get_front()];
    for(int i=k;i<n;i++){
        while(!isEmpty() && get_front()<=i-k){
            pop_front();
        }
        while(!isEmpty() && a[get_back()]<=a[i]){
            pop_back();
        }
        push_back(i);
        ans[idx++] = a[get_front()];
    }
    for(int i=0;i<idx;i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
