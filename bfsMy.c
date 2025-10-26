// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int* bfs(int n, int start, int adj[n][n]){
    int visited[n];
    int *bfs_queue=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    int queue[MAX];
    int front=0, rear=0, b_pointer=0;
    queue[rear++]=start;
    visited[start]=1;
    while(front < rear){
        int v = queue[front++];
        bfs_queue[b_pointer++]=v;
        for(int i=0;i<n;i++){
            if(adj[v][i]==1 && !visited[i]){
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
    bfs_queue[b_pointer]=-1;
    return bfs_queue;
}
int main() {
    int n,i,j,start=0;
    printf("\nEnter number of elements :");
    scanf("%d",&n);
    int node_elements[n];
    printf("\nEnter elements :");
    for(i=0;i<n;i++){
        scanf("%d",&node_elements[i]);
    }
    printf("\nEnter adjacency matrix : ");
    int adj[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    
    printf("\nEnter starting element for BFS : ");
    scanf("%d",&start);
    for(i=0;i<n;i++){
        if(node_elements[i]==start){
            break;
        }
    }
    
    int *result=bfs(n,i,adj);
    
    for(int i=0;i<result[i]!=-1;i++){
        printf("%d\t",node_elements[result[i]]);
    }
    free(result);
    
}
