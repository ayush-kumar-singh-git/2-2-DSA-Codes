#include <stdio.h>
#include <stdlib.h>

#define max 1000

int topidx = -1;

int isempty(float* stack){
    return topidx == -1;
}

void push(float* stack, float x){
    stack[++topidx] = x;
}

void pop(float* stack){
    if(!isempty(stack)) topidx--;
}

float top(float* stack){
    return stack[topidx];
    return -1;
}

int main()
{
    char in[10000];
    scanf("%s", in);
    float stk[max];
    int i = 0;
    int ie = 0;
    while(in[i]!='\0'){
        char c = in[i];
        if(c=='+' || c=='-' || c=='*' || c=='/'){
            if(topidx == -1 || topidx == 0){
                printf("invalid expression\n");
                ie = 1;
                break;
            }
            float two = top(stk);
            pop(stk);
            float one = top(stk);
            pop(stk);
            float val = 0;
            if(c=='+'){
                val = one + two;
            }else if(c=='-'){
                val = one - two;
            }else if(c=='*'){
                val = one * two;
            }else{
                if(two == 0){
                    printf("Invalid expression\n");
                    ie = 1;
                    break;
                }else{
                    val = one/two;
                }
            }
            push(stk, val);
        }
            else{
            float val = in[i]-'0';
            push(stk,val);
        }
        i++;
    }
    if(!ie && topidx == 0){
        printf("%.2f\n", top(stk));
    }else if(!ie){
        printf("Invalid expression\n");
    }
    return 0;
}

