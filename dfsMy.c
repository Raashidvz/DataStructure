#include <stdio.h>
#include <stdlib.h>

int adj[100][100];
int visited[100];

void dfs(int start, int n, int node_elements[]) {
    visited[start] = 1;
    printf("%d ", node_elements[start]);  // Print actual element value

    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            dfs(i, n, node_elements);
        }
    }
}

int main() {
    int n, i;
    printf("Enter number of nodes in the graph: ");
    scanf("%d", &n);

    int node_elements[n];
    printf("Enter node elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &node_elements[i]);
    }

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int start_value;
    printf("Enter starting vertex (actual element): ");
    scanf("%d", &start_value);

    // Find index of starting element
    int start_index = -1;
    for (i = 0; i < n; i++) {
        if (node_elements[i] == start_value) {
            start_index = i;
            break;
        }
    }

    if (start_index == -1) {
        printf("Invalid start vertex!\n");
        return 0;
    }

    printf("\nDFS Traversal:\n");
    dfs(start_index, n, node_elements);
    printf("\n");

    return 0;
}
