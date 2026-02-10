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

int main()
{
    int stack[MAX];
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    push(stack,5);
    printf("%d\n", top(stack));
    printf("%d\n", isEmpty(stack));
    pop(stack);
    while(!isEmpty(stack)){
        printf("%d\n", top(stack));
        pop(stack);
    }
    return 0;
}
