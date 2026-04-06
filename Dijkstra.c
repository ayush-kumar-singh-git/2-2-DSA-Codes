#include <stdio.h>
#include <stdlib.h>

#define INF 10000
#define MAX 1000

typedef struct Node_t{
    int dist;
    int node;
}Node;

typedef struct Edge {
    int to, weight;
    struct Edge* next;
} Edge;

Edge* adj[MAX];

void addEdge(int u, int v, int w){
    Edge* e = malloc(sizeof(Edge));
    e->to = v;
    e->weight = w;
    e->next = adj[u];
    adj[u] = e;
}

Node* pq[1000];
int sz = 0;

Node* createNode(int n, int d){
    Node* newNode = malloc(sizeof(Node));
    newNode -> dist = d;
    newNode -> node = n;
    return newNode;
}

int compare(Node* a, Node* b){
    if(a->dist < b->dist) return 1;
    else if (b->dist < a->dist) return 0;
    else return a->node < b->node;
}

void swap(Node** a, Node** b){
    Node* t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int idx){
    if(idx==0) return;
    int parent = (idx-1)/2;
    if(compare(pq[idx], pq[parent])){
        swap(&pq[idx], &pq[parent]);
        heapifyUp(parent);
    }
}

void heapifyDown(int idx){
    if(2*idx+1>=sz) return;

    int minIdx = 2*idx+1;

    if(2*idx+2 < sz && compare(pq[2*idx+2], pq[2*idx+1])) minIdx = 2*idx+2;

    if(compare(pq[minIdx], pq[idx])){
        swap(&pq[minIdx], &pq[idx]);
        heapifyDown(minIdx);
    }

}

void insert(int n, int d){
    Node* newNode = createNode(n, d);
    
    pq[sz++] = newNode;

    heapifyUp(sz-1);

    return;
}

Node* getMin(){
    Node* minm = pq[0];
    pq[0] = pq[sz-1];
    sz--;
    heapifyDown(0);
    return minm;
}


#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000
#define MAX 1000

// ---------- Priority Queue ----------

typedef struct Node_t{
    int dist;
    int node;
} Node;

Node* pq[MAX];
int sz = 0;

Node* createNode(int n, int d){
    Node* newNode = malloc(sizeof(Node));
    newNode->dist = d;
    newNode->node = n;
    return newNode;
}

int compare(Node* a, Node* b){
    if(a->dist < b->dist) return 1;
    else if(b->dist < a->dist) return 0;
    else return a->node < b->node;
}

void swap(Node** a, Node** b){
    Node* t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int idx){
    if(idx == 0) return;
    int parent = (idx - 1) / 2;
    if(compare(pq[idx], pq[parent])){
        swap(&pq[idx], &pq[parent]);
        heapifyUp(parent);
    }
}

void heapifyDown(int idx){
    if(2*idx + 1 >= sz) return;

    int minIdx = 2*idx + 1;

    if(2*idx + 2 < sz && compare(pq[2*idx+2], pq[2*idx+1]))
        minIdx = 2*idx + 2;

    if(compare(pq[minIdx], pq[idx])){
        swap(&pq[minIdx], &pq[idx]);
        heapifyDown(minIdx);
    }
}

void insert(int n, int d){
    if(sz >= MAX){
        printf("Heap overflow\n");
        return;
    }
    pq[sz++] = createNode(n, d);
    heapifyUp(sz-1);
}

Node* getMin(){
    if(sz == 0) return NULL;

    Node* minm = pq[0];
    pq[0] = pq[sz-1];
    sz--;
    heapifyDown(0);
    return minm;
}

int dist[MAX];
int visited[MAX];

void dijkstra(int src, int n){

    for(int i = 0; i < n; i++){
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;
    insert(src, 0);

    while(sz > 0){
        Node* cur = getMin();
        if(cur == NULL) break;

        int u = cur->node;

        if(visited[u]){
            free(cur);
            continue;
        }

        visited[u] = 1;

        Edge* temp = adj[u];

        while(temp){
            int v = temp->to;
            int w = temp->weight;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                insert(v, dist[v]);
            }

            temp = temp->next;
        }

        free(cur);
    }
}


int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) adj[i] = NULL;

    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(src, n);

    printf("Shortest distances:\n");
    for(int i = 0; i < n; i++){
        if(dist[i] == INF) printf("%d : INF\n", i);
        else printf("%d : %d\n", i, dist[i]);
    }

    return 0;
}
