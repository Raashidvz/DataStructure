#include <stdio.h>
#include <stdlib.h>

typedef struct BTreeNode {
    int *keys;
    struct BTreeNode **children;
    int n;              // current number of keys
    int leaf;           // 1 = leaf, 0 = internal
} BTreeNode;

int t; // order of B-tree (minimum degree)

// Function prototypes
BTreeNode* createNode(int leaf);
void traverse(BTreeNode *root);
BTreeNode* insert(BTreeNode *root, int k);
void insertNonFull(BTreeNode *node, int k);
void splitChild(BTreeNode *parent, int i);

BTreeNode* createNode(int leaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->leaf = leaf;
    node->keys = (int*)malloc(sizeof(int) * (2*t - 1));
    node->children = (BTreeNode**)malloc(sizeof(BTreeNode*) * (2*t));
    node->n = 0;
    return node;
}

void traverse(BTreeNode *root) {
    if (root == NULL) return;

    int i;
    for (i = 0; i < root->n; i++) {
        if (!root->leaf)
            traverse(root->children[i]);
        printf("%d ", root->keys[i]);
    }
    if (!root->leaf)
        traverse(root->children[i]);
}

void splitChild(BTreeNode *parent, int i) {
    BTreeNode *full = parent->children[i];
    BTreeNode *newNode = createNode(full->leaf);

    newNode->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        newNode->keys[j] = full->keys[j + t];

    if (!full->leaf) {
        for (int j = 0; j < t; j++)
            newNode->children[j] = full->children[j + t];
    }

    full->n = t - 1;

    for (int j = parent->n; j >= i+1; j--)
        parent->children[j+1] = parent->children[j];

    parent->children[i+1] = newNode;

    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j+1] = parent->keys[j];

    parent->keys[i] = full->keys[t-1];
    parent->n++;
}

void insertNonFull(BTreeNode *node, int k) {
    int i = node->n - 1;

    if (node->leaf) {
        while (i >= 0 && k < node->keys[i]) {
            node->keys[i+1] = node->keys[i];
            i--;
        }
        node->keys[i+1] = k;
        node->n++;
    }
    else {
        while (i >= 0 && k < node->keys[i])
            i--;

        i++;

        if (node->children[i]->n == 2*t - 1) {
            splitChild(node, i);
            if (k > node->keys[i])
                i++;
        }
        insertNonFull(node->children[i], k);
    }
}

BTreeNode* insert(BTreeNode *root, int k) {
    if (root == NULL) {
        root = createNode(1);
        root->keys[0] = k;
        root->n = 1;
        return root;
    }

    if (root->n == 2*t - 1) {
        BTreeNode *newRoot = createNode(0);
        newRoot->children[0] = root;
        splitChild(newRoot, 0);

        int i = (k > newRoot->keys[0]) ? 1 : 0;
        insertNonFull(newRoot->children[i], k);

        return newRoot;
    }
    else {
        insertNonFull(root, k);
        return root;
    }
}

void display(BTreeNode *root, int level) {
    if (root == NULL) return;

    printf("\nLevel %d : ", level);
    for (int i = 0; i < root->n; i++)
        printf("%d ", root->keys[i]);

    if (!root->leaf) {
        for (int i = 0; i <= root->n; i++)
            display(root->children[i], level + 1);
    }
}



int main() {
    BTreeNode *root = NULL;
    int n, key;

    printf("Enter order (minimum degree) t of B-Tree: ");
    scanf("%d", &t);

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("\nB-Tree (in sorted order): ");
    traverse(root);
    printf("\n");

    printf("\n\nB-Tree Structure:\n");
    display(root, 0);

    return 0;
}
