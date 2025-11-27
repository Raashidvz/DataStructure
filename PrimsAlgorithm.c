#include<stdio.h>
#include<limits.h>
#define MAX 100

int main(){
    int visited[MAX];
    int n,st,u,v;
    int edges=1,minCost=0;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    int adjM[n][n];
    printf("Enter the adjacency matrix:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adjM[i][j]);
            if(adjM[i][j]==0)
                adjM[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<n;i++)
        visited[i]=0;
    printf("Enter the starting vertex:");
    scanf("%d",&st);
    visited[st]=1;
    while(edges < n){
        int min=INT_MAX;
        for(int i=0 ; i<n ;i++){
            if(visited[i]){
                for(int j=0; j<n; j++){
                    if(!visited[j] && adjM[i][j]<min){
                        min=adjM[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        printf("Edge %d: (%d, %d) cost: %d\n",edges++,u,v,min);
        minCost+=min;
        visited[v] = 1;
    }
    printf("Minimum cost of spanning tree: %d\n",minCost);
    return 0;
}