//Kruskals Algorithm
#include <stdio.h>
#include <stdlib.h>

struct Edge{
    int src,dest,weight;
};


int find(int parent[], int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unionSet(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[yroot] = xroot;  // make one root the parent of the other
}

void sortEdges(struct Edge edges[],int e){
    struct Edge  temp;
    for(int i=0;i<e-1;i++){
        for(int j=0;j<e-i-1;j++){
            if(edges[j].weight > edges[j+1].weight){
                temp=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;
            }
        }
    }
}

void display(struct Edge edges[],int e){
    for(int i=0;i<e;i++){
        printf("\n%d --> %d\t%d",edges[i].src,edges[i].dest,edges[i].weight);
    }
    printf("\n");
}

void kruskals(struct Edge edges[],int v, int e){
    // Sort edges
    sortEdges(edges, e);

    // create parent set with each vertex is its own parent
    int parent[v];
    for(int j=0;j<v;j++){
        parent[j]=j;
    }

    struct Edge result[v];
    int i=0;
    int count=0;

    while (count < v - 1 && i < e) {
        struct Edge next = edges[i++];   // pick next smallest edge
    
        int x = find(parent, next.src);
        int y = find(parent, next.dest);
    
        // If including this edge doesn’t form a cycle
        if (x != y) {
            result[count++] = next;
            unionSet(parent, x, y);
        }
        // Else skip this edge (it forms a cycle)
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");
    int totalWeight = 0;
    for (int j = 0; j < count; j++) {
        printf("%d -- %d\tWeight: %d\n", result[j].src, result[j].dest, result[j].weight);
        totalWeight += result[j].weight;
    }
    printf("Total weight of MST = %d\n", totalWeight);
    
}

void main(){
    // int v,e;
    // printf("\nEnter number of vertices : ");
    // scanf("%d",&v);
    // printf("\nEnter number of edges : ");
    // scanf("%d",&e);
    // struct Edge edges[e];
    // printf("\nEnter edges : ");
    // for(int i=0;i<e;i++)
    //     scanf("%d%d%d",&edges[i].src,&edges[i].dest,&edges[i].weight);

    int v=4;
    int e=5;
    struct Edge edges[e];

    edges[0].src=0;
    edges[0].dest=1;
    edges[0].weight=10;

    edges[1].src=0;
    edges[1].dest=2;
    edges[1].weight=6;

    edges[2].src=0;
    edges[2].dest=3;
    edges[2].weight=5;
    
    edges[3].src=1;
    edges[3].dest=3;
    edges[3].weight=15;

    edges[4].src=2;
    edges[4].dest=3;
    edges[4].weight=4;
    
    printf("Before Sorting");
    display(edges,e);
    sortEdges(edges,e);
    printf("\nAfter Sorting");
    display(edges,e);
    kruskals(edges,v,e);

}
