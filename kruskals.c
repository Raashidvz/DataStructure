#include <stdio.h>

#define MAX 100

int parent[MAX];  // used for Disjoint Set (Union-Find)

// Function to find the set (representative) of a vertex
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to unite (merge) two subsets
void union_set(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int n, e;  // n = number of vertices, e = number of edges
    int edges[MAX][3];  // stores edge list: {u, v, weight}
    int u, v, w;
    int i, j, k;
    int total_cost = 0;
    int ne = 0; // number of edges in MST

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);

    // Step 1: Initialize disjoint sets
    for (i = 0; i < n; i++)
        parent[i] = i;

    // Step 2: Sort edges by ascending weight (simple bubble sort)
    for (i = 0; i < e - 1; i++) 
    {
        for (j = i + 1; j < e; j++)
        {
            if (edges[i][2] > edges[j][2])
            {
                int temp0 = edges[i][0];
                int temp1 = edges[i][1];
                int temp2 = edges[i][2];
                edges[i][0] = edges[j][0];
                edges[i][1] = edges[j][1];
                edges[i][2] = edges[j][2];
                edges[j][0] = temp0;
                edges[j][1] = temp1;
                edges[j][2] = temp2;
            }
        }
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");

    // Step 3: Add edges one by one
    for (i = 0; i < e && ne < n - 1; i++) 
    {
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v) 
        {  // no cycle
            printf("%d - %d : %d\n", u, v, w);
            total_cost += w;
            union_set(set_u, set_v);
            ne++;
        }
    }

    printf("Total cost of MST = %d\n", total_cost);

    return 0;
}
