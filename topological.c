#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int v, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }

    stack[++top] = v;   // push after visiting all neighbours
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, n);

    printf("\nTopological Sort Order:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}