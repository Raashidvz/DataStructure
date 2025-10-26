#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};

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

struct node* insert(struct node *root, int key){
    if(root==NULL){
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=key;
        newnode->left=newnode->right=NULL;
        return newnode;
    }
    if(key < root->data){ // left-subtree
        root->left=insert(root->left,key);
    }else if(key > root->data){
        root->right=insert(root->right,key);
    }else{
        printf("No duplication allowed in BST");
    }
    return root;
}

struct node* deletenode(struct node *root, int key){
    if(root==NULL){
        printf("No such element found to delete");
        return NULL;
    }
    if(key < root->data){
        root->left=deletenode(root->left,key);
    }else if(key > root->data){
        root->right=deletenode(root->right,key);
    }else{
        
        if(root->left != NULL && root->right != NULL){
            // case 1: if root have 2 childs
            // find inorder successor
            struct node *successor;
            successor=root->right;
            while(successor->left!=NULL){
                successor=successor->left;
            }
            root->data=successor->data;
            root->right=deletenode(root->right,successor->data);
            return root;
            
            
        }else if(root->left != NULL){
            // case 2: if only left child
            struct node *temp=root->left;
            free(root);
            return temp;
        }else if(root->right != NULL){
            // case 3: if only right child
            struct node *temp=root->right;
            free(root);
            return temp;
        }else{
            // case 4: No child
            free(root);
            return NULL;
        }
    }
    
    return root;
}

struct node* search(struct node *root, int key){
    if(root==NULL || root->data == key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }else{ // (key>root->data)
        return search(root->right,key);
    }
    return NULL;
}

void main(){
    struct node *root;
    int choice,key,found;
    root=NULL;
    do{
        printf("\n1. Insert node\n2.delete node\n3.Search node\n4.Inorder tree\n5.Preorder tree\n6.Postorder tree\n0.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter element to insert : ");
                    scanf("%d",&key);
                    root=insert(root,key);
                    printf("\nIn-order Traversal : ");
                    inorder(root);
                    break;
            case 2: printf("\nEnter element to delete : ");
                    scanf("%d",&key);
                    root=deletenode(root,key);
                    break;
            case 3: {
                        printf("\nEnter element to search : ");
                        scanf("%d",&key);
                        struct node* found=NULL;
                        found=search(root,key);
                        if(found != NULL){
                            printf("\nElement %d found\n",key);
                        }else{
                            printf("\nElement not found\n");
                        }
                        break;
                    }
            case 4: printf("\nInorder Traversal : ");
                    inorder(root);
                    printf("\n");
                    break;
            case 5: printf("\nPreorder Traversal : ");
                    preorder(root);
                    printf("\n");
                    break;
            case 6: printf("\nPostorder Traversal : ");
                    postorder(root);
                    printf("\n");
                    break;
            case 0:printf("\nExiting........");
                    break;
            default:printf("\nInvalid input, try again...");
        }
    }while(choice!=0);
    
}
