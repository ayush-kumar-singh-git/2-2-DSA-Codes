// I HAVE NO IDEA WHAT THIS IS
#include <stdio.h>

#define MAX 100000

typedef struct {
    int idx;
    int arrival;
} Pair;

/* Enter Queue */
Pair enterQ[MAX];
int frontEnter = -1, backEnter = -1;

/* Exit Queue */
Pair exitQ[MAX];
int frontExit = -1, backExit = -1;

void enqueueEnter(int idx, int time){
    if(frontEnter == -1) frontEnter = backEnter = 0;
    else backEnter++;
    enterQ[backEnter].idx = idx;
    enterQ[backEnter].arrival = time;
}

void enqueueExit(int idx, int time){
    if(frontExit == -1) frontExit = backExit = 0;
    else backExit++;
    exitQ[backExit].idx = idx;
    exitQ[backExit].arrival = time;
}

Pair dequeueEnter(){
    return enterQ[frontEnter++];
}

Pair dequeueExit(){
    return exitQ[frontExit++];
}

int isEnterEmpty(){
    return (frontEnter == -1 || frontEnter > backEnter);
}

int isExitEmpty(){
    return (frontExit == -1 || frontExit > backExit);
}

void solve(int time[], int direction[], int n){
    int result[n];
    int currTime = 0;
    int i = 0;              // pointer for arrivals
    int lastDir = -1;       // -1 = idle, 0 = enter, 1 = exit

    while(i < n || !isEnterEmpty() || !isExitEmpty()){

        /* If both queues empty, jump time */
        if(isEnterEmpty() && isExitEmpty() && i < n && currTime < time[i]){
            currTime = time[i];
            lastDir = -1; // idle
        }

        /* Add all arrivals at current time */
        while(i < n && time[i] <= currTime){
            if(direction[i] == 0)
                enqueueEnter(i, time[i]);
            else
                enqueueExit(i, time[i]);
            i++;
        }

        /* Decide who goes */
        if(!isEnterEmpty() && !isExitEmpty()){
            if(lastDir == -1){
                // idle rule → exit priority
                Pair p = dequeueExit();
                result[p.idx] = currTime;
                lastDir = 1;
            }
            else if(lastDir == 1){
                Pair p = dequeueExit();
                result[p.idx] = currTime;
                lastDir = 1;
            }
            else{
                Pair p = dequeueEnter();
                result[p.idx] = currTime;
                lastDir = 0;
            }
        }
        else if(!isExitEmpty()){
            Pair p = dequeueExit();
            result[p.idx] = currTime;
            lastDir = 1;
        }
        else if(!isEnterEmpty()){
            Pair p = dequeueEnter();
            result[p.idx] = currTime;
            lastDir = 0;
        }
        else{
            continue;
        }

        currTime++;
    }

    for(int j = 0; j < n; j++)
        printf("%d ", result[j]);
}
int main(){
    int n;

    scanf("%d", &n);

    int time[n];
    int direction[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &time[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &direction[i]);

    solve(time, direction, n);

    return 0;
}
