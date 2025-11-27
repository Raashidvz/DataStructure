#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ---------------- Node Structure ----------------
typedef struct BinomialNode {
    int key;
    int degree;
    struct BinomialNode *parent;
    struct BinomialNode *child;
    struct BinomialNode *sibling;
} Node;

// ---------------- Function Prototypes ----------------
Node* createNode(int key);
Node* unionHeaps(Node* h1, Node* h2);
Node* insert(Node* heap, int key);
Node* mergeHeaps(Node* h1, Node* h2);
Node* findMin(Node* heap);
void display(Node* heap);

// ---------------- Create a Node ----------------
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->degree = 0;
    newNode->parent = newNode->child = newNode->sibling = NULL;
    return newNode;
}

// ---------------- Merge root lists by degree ----------------
Node* mergeHeaps(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    Node *newHead = NULL, *tail = NULL;

    // Merge root lists by degree
    while (h1 && h2) {
        Node *temp;
        if (h1->degree <= h2->degree) {
            temp = h1;
            h1 = h1->sibling;
        } else {
            temp = h2;
            h2 = h2->sibling;
        }

        if (!newHead)
            newHead = tail = temp;
        else {
            tail->sibling = temp;
            tail = temp;
        }
    }

    // Attach remaining
    tail->sibling = h1 ? h1 : h2;

    return newHead;
}

// ---------------- Union Heaps (Linking Trees) ----------------
Node* unionHeaps(Node* h1, Node* h2) {
    Node *heap = mergeHeaps(h1, h2);
    if (!heap) return NULL;

    Node *prev = NULL;
    Node *curr = heap;
    Node *next = curr->sibling;

    while (next) {
        if ((curr->degree != next->degree) ||
            (next->sibling && next->sibling->degree == curr->degree)) {
            prev = curr;
            curr = next;
        }
        else {
            // Make smaller key the root
            if (curr->key <= next->key) {
                curr->sibling = next->sibling;
                next->parent = curr;
                next->sibling = curr->child;
                curr->child = next;
                curr->degree++;
            } else {
                if (prev)
                    prev->sibling = next;
                else
                    heap = next;

                curr->parent = next;
                curr->sibling = next->child;
                next->child = curr;
                next->degree++;

                curr = next;
            }
        }
        next = curr->sibling;
    }

    return heap;
}

// ---------------- Insert a Key ----------------
Node* insert(Node* heap, int key) {
    Node* newNode = createNode(key);
    return unionHeaps(heap, newNode);
}

// ---------------- Find Minimum Key ----------------
Node* findMin(Node* heap) {
    if (!heap) return NULL;

    Node* minNode = heap;
    Node* curr = heap->sibling;

    while (curr) {
        if (curr->key < minNode->key)
            minNode = curr;
        curr = curr->sibling;
    }
    return minNode;
}

// ---------------- Display Binomial Heap ----------------
void display(Node* heap) {
    if (!heap) {
        printf("Heap is empty.\n");
        return;
    }

    printf("Binomial Heap keys: ");
    Node* curr = heap;
    while (curr) {
        printf("%d ", curr->key);
        curr = curr->sibling;
    }
    printf("\n");
}

// ---------------- Main Program ----------------
int main() {
    Node* heap = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Binomial Heap Menu ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Find Minimum\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            heap = insert(heap, value);
            break;

        case 2:
            display(heap);
            break;

        case 3: {
            Node* minNode = findMin(heap);
            if (minNode)
                printf("Minimum value: %d\n", minNode->key);
            else
                printf("Heap is empty.\n");
            break;
        }

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
