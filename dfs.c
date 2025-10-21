#include<stdio.h>
int adj[100][100];
int visited[100];
void dfs(int start,int n){
    visited[start]=1;
    printf("%d ",start);
    for(int i=0;i<n;i++){
        if(adj[start][i]==1 && !visited[i]){
            dfs(i,n);
        }
    }
}
int main(){
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
    printf("DFS  Traversal : \n");
    dfs(start,n);
    printf("\n");
    return 0;
}
