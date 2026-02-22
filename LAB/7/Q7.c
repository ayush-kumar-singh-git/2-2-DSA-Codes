#include <stdio.h>

#define MAX 10000

int front = -1;
int back = -1;

int q[MAX];

void resetQueue() {
    front = -1;
    back = -1;
}

void enqueue(int x) {
    if(front == -1) {
        front = back = 0;
    } else {
        back++;
    }
    q[back] = x;
}

int main() {
    int n;
    scanf("%d", &n);

    int gas[n], dist[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &gas[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &dist[i]);

    int start = 0;

    while(start < n) {
        resetQueue();
        int currentFuel = 0;
        int count = 0;
        int idx = start;
        while(count < n) {
            enqueue(idx);
            currentFuel += gas[idx] - dist[idx];
            if(currentFuel < 0)
                break;
            idx = (idx + 1) % n;
            count++;
        }
        if(count == n) {
            printf("%d\n", start);
            return 0;
        }
        start++;
    }

    printf("-1\n");
    return 0;
}
