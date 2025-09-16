#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* push(struct node *top, struct node *newnode){
    
    if(top==NULL){
        top=newnode;
    }else{
        newnode->next=top;
        top=newnode;
    }
    return top;
}

struct node* pop(struct node *top){
    struct node *temp;
    if(top==NULL){
        printf("\nStack underflow");
        return top;
    }else{
        temp=(struct node*)malloc(sizeof(struct node));
        temp=top;
        top=top->next;
        free(temp);
    }
    return top;
}

// void display(struct node *top){
//     struct node *temp;
//     if(top==NULL){
//         printf("\nEmpty stack");
//     }else{
//         temp=top;
//         while(temp!=NULL){
//             printf("%d -> ",temp->data);
//             temp=temp->next;
//         }
//         printf("NULL");
//         free(temp);
//     }
// }
void display(struct node *top){
    struct node *temp;
    if(top==NULL){
        printf("\n|-----------------------|\n|\tEmpty stack\t|\n|-----------------------|\n");
    }else{
        temp=top;
        printf("\n|---------------|<-----TOP\n");
        while(temp!=NULL){
            printf("|\t%d\t|",temp->data);
            printf("\n|---------------|\n");
            temp=temp->next;
        }
        printf("|\tNULL\t|");
        printf("\n|---------------|\n");
        free(temp);
    }
}


int search(struct node *top, int key){
    struct node *temp;
    int count=0,flag=0;
    if(top==NULL){
        printf("\nEmpty stack");
    }else{
        temp=(struct node*)malloc(sizeof(struct node));
        temp=top;
        while(temp!=NULL){
            count++;
            if(key==temp->data){
                flag=1;
                break;
            }
            temp=temp->next;
        }
        // free(temp);
    }
    if(flag){
        return count;
    }else{
        return 0;
    }
}

void main(){
    int choice,data,index;
    struct node *top;
    top=NULL;
    do{
        printf("\n\n1.Push\n2.Pop\n3.Display\n4.Search\n0.Exit\nSelect your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: struct node *newnode;
                    newnode=(struct node*)malloc(sizeof(struct node));
                    printf("\nEnter data : ");
                    scanf("%d",&newnode->data);
                    newnode->next=NULL;
                    top=push(top,newnode);
                    display(top);
                    break;
            case 2: top=pop(top);
                    display(top);
                    break;
            case 3: printf("\nStack elements are: ");
                    display(top);
                    break;
            case 4: printf("\nEnter element to search : ");
                    scanf("%d",&data);
                    index=search(top,data);
                    if(index){
                        printf("\nElement '%d' found at position '%d'",data,index);
                    }else{
                        printf("\nNo element found");
                    }
                    break;
            case 0: printf("Exiting.......\n");
                    break;
            default:printf("\nInvalid input , try again....");

        }
    }while(choice);
}