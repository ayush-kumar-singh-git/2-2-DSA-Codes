#include <stdio.h>
#include <string.h>

#define MAX 10000
#define MAX_LEN 32

int front = -1;
int back = -1;

char q[MAX][MAX_LEN];

void enqueue(char *str) {
    if(front == -1) {
        front = back = 0;
    } else {
        back++;
    }
    strcpy(q[back], str);
}

void dequeue(char *result) {
    strcpy(result, q[front]);
    front++;
}

int isEmpty() {
    return front == -1 || front > back;
}

int main() {
    int N;
    scanf("%d", &N);

    front = back = -1;

    enqueue("1");

    for(int i = 0; i < N; i++) {
        char curr[MAX_LEN];
        dequeue(curr);
        printf("%s ", curr);
        char next0[MAX_LEN], next1[MAX_LEN];
        strcpy(next0, curr);
        strcat(next0, "0");
        strcpy(next1, curr);
        strcat(next1, "1");
        enqueue(next0);
        enqueue(next1);
    }

    return 0;
}
