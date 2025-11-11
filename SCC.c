#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], rev[MAX][MAX];
int visited[MAX], stack[MAX], top = -1;
int n; // number of vertices

void push(int v) { stack[++top] = v; }
int pop() { return stack[top--]; }

void dfs1(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (graph[v][i] && !visited[i])
            dfs1(i);
    push(v);
}

void dfs2(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (rev[v][i] && !visited[i])
            dfs2(i);
}

int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
            rev[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // directed edge
    }

    // Step 1: Perform DFS to get finishing times
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);

    // Step 2: Reverse graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            rev[j][i] = graph[i][j];

    // Step 3: DFS on reversed graph in stack order
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nStrongly Connected Components:\n");

    while (top != -1) {
        int v = pop();
        if (!visited[v]) {
            dfs2(v);
            printf("\n");
        }
    }

    return 0;
}

