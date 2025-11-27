#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int adj[MAX][MAX];
int adgT[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void DFS1(int v, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS1(i, n);
        }
    }
    stack[++top] = v;
}

void DFS2(int v, int n) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adgT[v][i] && !visited[i]) {
            DFS2(i, n);
        }
    }
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
            adgT[i][j] = 0;
        }
    }

    printf("Enter edges (u v): \n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adgT[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS1(i, n);
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("\nStrongly Connected Components:\n");
    while (top != -1) {
        int v = stack[top--];
        if (!visited[v]) {
            DFS2(v, n);
            printf("\n");
        }
    }
    return 0;
}