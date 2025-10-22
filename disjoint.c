#include <stdio.h>

#define MAX 20

// Find operation
int find(int parent[], int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

// Union operation
void unionSets(int parent[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX == rootY)
        printf("Elements %d and %d are already in the same set.\n", x, y);
    else {
        parent[rootY] = rootX;
        printf("Union done: %d and %d are now in the same set.\n", x, y);
    }
}

// MakeSet operation
void makeSet(int parent[], int n) {
    for (int i = 0; i < n; i++)
        parent[i] = i;  // each element is its own parent
}

int main() {
    int n;
    int universal[MAX];
    int parent[MAX];

    printf("Enter number of elements in the universal set: ");
    scanf("%d", &n);

    printf("Enter the elements of the universal set:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &universal[i]);

    // Initialize all sets
    makeSet(parent, n);
    printf("\nAll elements have been made into individual sets.\n");

    int choice, a, b, i, indexA, indexB;

    do {
        printf("\nMenu:\n");
        printf("1. Union two elements\n");
        printf("2. Find representative of an element\n");
        printf("3. Display all sets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two elements to union: ");
                scanf("%d %d", &a, &b);
                indexA = indexB = -1;
                for (i = 0; i < n; i++) {
                    if (universal[i] == a) indexA = i;
                    if (universal[i] == b) indexB = i;
                }
                if (indexA == -1 || indexB == -1)
                    printf("Element not found in universal set!\n");
                else
                    unionSets(parent, indexA, indexB);
                break;

            case 2:
                printf("Enter element to find: ");
                scanf("%d", &a);
                indexA = -1;
                for (i = 0; i < n; i++) {
                    if (universal[i] == a) indexA = i;
                }
                if (indexA == -1)
                    printf("Element not found in universal set!\n");
                else
                    printf("Representative of %d is %d\n",
                           a, universal[find(parent, indexA)]);
                break;

            case 3:
                printf("\nCurrent sets:\n");
                for (i = 0; i < n; i++) {
                    printf("Element %d -> Set %d\n", universal[i],
                           universal[find(parent, i)]);
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
