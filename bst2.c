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

struct node * delete(struct node *root,int key){
    if (root == NULL){
        printf("\nKey not found\n");
        return root;
    }
    if(key<root->data){
        root->left=delete(root->left,key);
    }else if(key>root->data){
        root->right=delete(root->right,key);
    }else{
        // Its the node to delete, it can have 1 child, 2 child , or no child
        // case 1: no child
        if(root->left == NULL && root->right==NULL){
            free(root);
            return NULL;
        }else if(root->left==NULL){
            // Only right child 
            struct node *temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            // Only left child
            struct node *temp=root->left;
            free(root);
            return temp;
        }else{
            // Both Childs
            // get smallest in right subtree(inorder succcessor)
            struct node *successor=root;

            while(successor->left!=NULL){
                successor=successor->left;
            }
            root->data=successor->data;
            root->right=delete(root->right,successor->data);
            struct node *temp;
        }
    }

}

void search(struct node *root,int key){
    if(root==NULL){
        printf("No element Found");
        return;
    }
    
    if(key<root->data){
        search(root->left,key);

    }else if(key>root->data){
        search(root->right,key);
    }else{
        printf("\nElement %d found",key);
        return;
    }
    return;
}

void main(){
    struct node *root;
    int choice,key,found;
    root=NULL;
    // root=create();
    // printf("\nIn-order Traversal : ");
    // inorder(root);
    // printf("\nPre-order Traversal : ");
    // preorder(root);
    // printf("\nPost-order Traversal : ");
    // postorder(root);
    do{
        printf("\n1. Insert node\n2.Delete node\n3.Search node\n\n0.Exit\nEnter your choice : ");
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
                    root=delete(root,key);
            case 3: printf("\nEnter element to search : ");
                    scanf("%d",&key);
                    found=search(root,key);

        }
    }while(choice!=0);
    
}
