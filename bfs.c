#include<stdio.h>
int adj[100][100];
int visited[100];
int queue[100];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == 99) 
        return;
    if (front == -1) 
        front = 0;
    rear++;
    queue[rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) 
        return -1;
    int x = queue[front];
    front++;
    return x;
}

void bfs(int start, int n) {
    visited[start] = 1;
    enqueue(start);
    printf("%d ", start);
    while (front <= rear) {
        int current = dequeue();
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
                printf("%d ", i);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements in the graph \n");
    scanf("%d",&n);
    printf("Enter adjacency matrix \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    int start;
    printf("Enter starting vertex \n");
    scanf("%d",&start);
    printf("BFS Traversal : \n");
    bfs(start,n);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bfs(i,n);
        }
    }
    printf("\n");
    return 0;
}
