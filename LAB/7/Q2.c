#include <stdio.h>
#include <stdlib.h>

int front = -1;
int back = -1;

void enqueue(int* q, int x){
    if(front == -1 || front > back){
        front = back = 0;
    } else {
        back++;
    }
    q[back] = x;
}

void dequeue(int* q){
    front++;
}

int peek(int* q){
    return q[front];
}

int isEmpty(int* q){
    return (front==-1 && back==-1) || (front>back);
}

int main()
{
    char s[10000];
    scanf("%s", s);
    int freq[26]={0};
    int q[10000];
    int i=0;
    while(s[i]!='\0'){
        freq[s[i]-'a']++;
        enqueue(q, s[i]-'a');
        int done = 0;
        while(!isEmpty(q)){
            int ch = peek(q);
            if(freq[ch]==1){
                done = 1;
                printf("%c ", ch+'a');
                break;
            }
            dequeue(q);
        }
        if(!done) printf("-1 ");
        i++;
    }
    printf("\n");
    return 0;
}
