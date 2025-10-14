#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

// DFS 
void dfs(int v){
    visited[v]=1;
    printf("%d",v);

    for(int i=0;i<n;i++){
        if(adj[v][i]==1 && !visited[i]){
            dfs(i);
        }
    }
}

// BFS

void bfs(int start){
    int queue[MAX],front=0,rear=0;
    for(int i=0;i<n;i++){
        visited[i]=0; //reset visited for BFS
    }
    visited[start]=1;
    queue[rear++]=start;

    while(front<rear){
        int v=queue[front++];
        printf("%d",v);

        for(int i=0;i<n;i++){
            if(adj[v][i]==1 && !visited[i]){
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
}

void main(){
    printf("\nEnter number of vertices : ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix : ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    int start;
    printf("\nEnter starting vertex (0 to %d) : ",n-1);
    scanf("%d",&start);
    printf("\nDFS Traversal : ");
    dfs(start);
    printf("\nBSF Traversal : ");
    bfs(start);
}
