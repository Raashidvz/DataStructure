#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node* createnewNode(int data){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void display(struct node *head){
    if(head==NULL){
        printf("Empty list");
    }else{
        struct node *temp;
        temp=head;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }

}

void search(struct node *head){
    
    if(head==NULL){
        printf("Empty list");
    }else{
        int key,count=1;
        printf("\nEnter element to search : ");
        scanf("%d",&key);
        struct node *temp;
        temp=head;
        while(temp!=NULL){
            if(key == temp->data){
                printf("\nElement Found at position %d\n",count);
                return;
            }
            temp=temp->next;
            count++;
        }
        printf("No such element found in list\n");
    }

}

int countElements(struct node *head){
    int count=0;
    if(head==NULL){
        printf("Empty list");
    }else{
        struct node *temp;
        temp=head;
        while(temp!=NULL){
            count++;
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
    return count;
}

void insertAtBegin(struct node **head){
    struct node *newnode;
    int num;
    printf("\nEnter element to insert : ");
    scanf("%d",&num);
    newnode=createnewNode(num);
    if(*head==NULL){
        *head=newnode;
    }else{
        newnode->next=*head;
        (*head)->prev=newnode;
        *head=newnode;
    }

}

void insertAtEnd(struct node **head){
    struct node *newnode;
    int num;
    printf("\nEnter element to insert : ");
    scanf("%d",&num);
    newnode=createnewNode(num);
    if(*head==NULL){
        *head=newnode;
    }else{
        struct node *temp;
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }

}

void insertAfterPosition(struct node **head){
    struct node *newnode;
    int num,pos,i=1;
    int count=countElements(*head);
    printf("\nEnter position to insert : ");
    scanf("%d",&pos);
    
    
    if(pos==1){
        insertAtBegin(head);
    }else if(pos==count+1){
        insertAtEnd(head);
    }
    else if(pos>=count+1){
        printf("\nInvalid Position. Enter position between (1 and %d)\n",count+1);
    }else{
        printf("\nEnter element to insert : ");
        scanf("%d",&num);
        newnode=createnewNode(num);
        struct node *temp;
        temp=*head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        newnode->next=temp;
        newnode->prev=temp->prev;
        temp->prev->next=newnode;
        temp->prev=newnode;

    }

}

void deleteFromFirst(struct node **head){
    if(*head==NULL){
        printf("\nUnderflow\n");
        return;
    }else{
        struct node *temp;
        temp=*head;
        *head=temp->next;
        
        if(*head!=NULL){
            (*head)->prev=NULL;
        }
        free(temp);
    }
}


void deleteEnd(struct node **head){
    if(*head==NULL){
       printf("UnderFlow");
    }else{
        struct node *temp,*previous;
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        previous=temp->prev;
        if(previous==NULL){
            *head=NULL;
        }else{
            previous->next=NULL;
        }
        free(temp);
    }
}

void deletePosition(struct node **head){
    if(*head==NULL){
       printf("UnderFlow, No elements to delete");
    }else{
        int pos,i=1;
        int count=countElements(*head);
        printf("\nEnter position to delete : ");
        scanf("%d",&pos);
        if(pos>count){
            printf("\nInvalid position\n");
        }else if(pos==1){
            deleteFromFirst(head);
        }else{
            struct node *temp,*previous;
            temp=*head;
            while(i<pos){
                temp=temp->next;
                i++;
            }
            previous=temp->prev;
            if(previous==NULL){
                *head=NULL;
            }else{
                (temp->prev)->next=temp->next;
                if(temp->next!=NULL){
                    (temp->next)->prev=temp->prev;
                }
            }
            free(temp);
        }
    }
}


void main(){
    int choice;
    struct node *head;
    head=NULL;
    do{
        printf("\n\n1.Insert at Beginning\n2.Insert at End\n3.Insert at position\n4.Delete from Beginning\n5.Delete from End\n6.Delete from position\n7.Display list\n8.Search List\n0.Exit\nSelect your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: insertAtBegin(&head);
                    display(head);
                    break;
            case 2: insertAtEnd(&head);
                    display(head);
                    break;
            case 3: insertAfterPosition(&head);
                    display(head);
                    break;
            case 4: deleteFromFirst(&head);
                    display(head);
                    break;
            case 5: deleteEnd(&head);
                    display(head);
                    break;
            case 6: deletePosition(&head);
                    display(head);
                    break;
            case 7: printf("\nList Elements : ");
                    display(head);
                    break;
            case 8: search(head);
                    break;
            case 0: printf("\nExiting......\n");
                    break;
            default:printf("\nInvalid input , try again.....");
        }
    }while(choice);
}
