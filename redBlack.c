#include <stdio.h>
#include <stdlib.h>

// Node colors
#define RED 1
#define BLACK 0

typedef struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
} Node;

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; // New node is always red
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// BST insertion
Node* bstInsert(Node* root, Node* node) {
    if (root == NULL)
        return node;

    if (node->data < root->data) {
        root->left = bstInsert(root->left, node);
        root->left->parent = root;
    } else if (node->data > root->data) {
        root->right = bstInsert(root->right, node);
        root->right->parent = root;
    }
    return root;
}

// Left rotate
void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

// Right rotate
void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

// Fix red-black properties after insertion
void fixViolation(Node** root, Node* z) {
    while (z != *root && z->parent->color == RED) {
        Node* grandparent = z->parent->parent;

        if (z->parent == grandparent->left) {
            Node* uncle = grandparent->right;
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                z->parent->color = uncle->color = BLACK;
                z = grandparent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                grandparent->color = RED;
                rightRotate(root, grandparent);
            }
        } else {
            Node* uncle = grandparent->left;
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                z->parent->color = uncle->color = BLACK;
                z = grandparent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                grandparent->color = RED;
                leftRotate(root, grandparent);
            }
        }
    }
    (*root)->color = BLACK;
}

// Insert a node in Red-Black Tree
Node* insertRB(Node* root, int data) {
    Node* node = createNode(data);
    root = bstInsert(root, node);
    fixViolation(&root, node);
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d%s ", root->data, root->color == RED ? "(R)" : "");
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    printf("%d%s ",root->data,root->color == RED ? "(R)" : "");
    preorder(root->left);
    preorder(root->right);
}

// Search in Red-Black Tree
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1.Insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Search\n0.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insertRB(root, value);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                Node* found = search(root, value);
                if (found)
                    printf("Found: %d (%s)\n", found->data, found->color == RED ? "R" : "B");
                else
                    printf("Not found\n");
                break;
            case 0:
                printf("\nExiting..........");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
