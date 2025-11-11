#include <stdio.h>
#include <limits.h>

#define MAX 50
#define INF 1000000000  // large value to represent "no edge"

// Prim's algorithm: Minimum Spanning Tree for a connected, undirected, weighted graph
int main() {
    int cost[MAX][MAX];    // adjacency matrix: cost[i][j] = weight of edge i-j (INF if no edge)
    int visited[MAX];      // visited[i] == 1 means vertex i is already included in MST
    int n;                 // number of vertices
    int edge_count = 0;    // number of edges included in MST so far
    int total_cost = 0;    // running sum of weights in the MST

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        printf("Invalid number of vertices.\n");
        return 0;
    }

    printf("Enter the cost adjacency matrix (enter 0 to indicate NO edge):\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            int w;
            scanf("%d", &w);
            if (i == j) {
                cost[i][j] = INF; // ignore self-loops
            } else if (w == 0) 
            {
                cost[i][j] = INF; // 0 means no edge in input
            } else {
                cost[i][j] = w;
            }
        }
    }

    // Initialize visited[] to 0
    for (int i = 0; i < n; i++) visited[i] = 0;

    // Start MST from vertex 0 (arbitrary choice)
    visited[0] = 1;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    // Repeat until we have (n-1) edges or we detect disconnectedness
    while (edge_count < n - 1) 
    {
        int min = INF;
        int a = -1, b = -1; // endpoints of the chosen minimum edge in this iteration

        // Find the minimum weight edge that connects a visited vertex to an unvisited vertex
        for (int i = 0; i < n; i++)
        {
            if (visited[i]) {
                for (int j = 0; j < n; j++) 
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        // If no such edge was found, the graph is disconnected
        if (min == INF) break;

        // Include edge a-b in MST
        printf("%d - %d : %d\n", a, b, min);
        total_cost += min;
        visited[b] = 1;
        edge_count++;
    }

    // If we could not add enough edges, graph is disconnected
    if (edge_count != n - 1) {
        printf("\nThe given graph is NOT connected. Prim's algorithm cannot form a spanning tree.\n");
    } else {
        printf("Minimum Cost = %d\n", total_cost);
    }

    return 0;
}

