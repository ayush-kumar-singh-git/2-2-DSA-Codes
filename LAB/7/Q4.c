#include <stdio.h>

#define MAX 1000

int front = -1;
int back = -1;

typedef struct {
    int ff;
    int ss;
} Pair;

Pair q[MAX];

void enqueue(int x, int y){
    if(front == -1) {
        front = back = 0;
    } else {
        back++;
    }
    q[back].ff = x;
    q[back].ss = y;
}

Pair dequeue(){
    return q[front++];
}

int isEmpty(){
    return (front == -1 || front > back);
}

int main(){
    int m,n;
    scanf("%d %d", &m, &n);

    int g[m][n];
    int visited[m][n];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &g[i][j]);
            visited[i][j] = 0;
        }
    }

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    int level = 1;
    enqueue(0,0);
    visited[0][0]=1;

    while(!isEmpty()){
        int currLen = back-front+1;
        while(currLen--){
            Pair curr = dequeue();
        if(g[curr.ff][curr.ss]==2){
            printf("%d\n", level);
            return 0;
        }

        for(int i=0;i<4;i++){
            int nx = curr.ff+dx[i];
            int ny = curr.ss+dy[i];
            if(0<=nx && nx<m && 0<=ny && ny<n){
                if(visited[nx][ny]==1||g[nx][ny]==1) continue;
                visited[nx][ny] = 1;
                enqueue(nx,ny);
            }
        }
        }
        level++;
            }
    return 0;
}
