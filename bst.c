#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node * createNewnode(int data){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

// struct node * create(){
//     int x;
//     struct node *newnode;
//     newnode=(struct node *)malloc(sizeof(struct node));
//     printf("Enter data (-1 for no data) : ");
//     scanf("%d",&x);
//     if (x==-1){
//         return NULL;
//     }
//     newnode->data=x;
//     printf("\nEnter left child of %d : ",x);
//     newnode->left=create();
//     printf("\nEnter right child of %d : ",x);
//     newnode->right=create();
//     return newnode;
// }



void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

void preorder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}


void postorder(struct node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}



struct node * insert(struct node *root, int key){
    if(root == NULL){
        return createNewnode(key);
    }
    if(key < root->data){
        root->left=insert(root->left,key);
    }else if(key > root->data){
        root->right=insert(root->right,key);
    }else{
        printf("\nBST not allow duplicate elements!\n");
    }
    return root;
}

struct node * delete(struct note *prev, struct node *root,int key){
    if(key==root->data and prev==NULL){
        return NULL;
    }else if(key==root->data){
        // case1
        if(root->left==NULL and root->right==NULL){
            delete(root);
            return NULL;
        }else if(root->left==NULL){ // case 2

        }else if(root->right==NULL){ // case 3

        }else{ // case 4

        }
    }
    if(key<root->data){
        root->left=delete(root->left,key);
    }
    if(key>root->data){
        root->right=delete(root->right,key);
    }
}



void main(){
    struct node *root;
    int choice,key;
    root=NULL;
    // root=create();
    // printf("\nIn-order Traversal : ");
    // inorder(root);
    // printf("\nPre-order Traversal : ");
    // preorder(root);
    // printf("\nPost-order Traversal : ");
    // postorder(root);
    do{
        printf("\n1. Insert node\n2.Delete node\nSearch node\n0.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter element to insert : ");
                    scanf("%d",&key);
                    root=insert(root,key);
                    printf("\nIn-order Traversal : ");
                    inorder(root);
                    break;
            case 2: printf("\nEnter element to delete : ");
                    scanf("%d",key);
                    root=delete(NULL,root,key);

        }
    }while(choice!=0);
    
}