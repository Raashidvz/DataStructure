#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];
int f=-1,r=-1;

int isEmpty(){
    if(f ==-1 && r == -1){
        printf("UnderFLow\n");
        return 1;
    }
    if(f==r && f==-1){
        printf("UnderFLow");
        return 1;
    }
}

int isFull(){
    if((r+1 % MAX_SIZE)==f){
        printf("OverFlow");
        return 1;
    }
}

void enqueue(int data){
    if(isFull()){
        return;
    }
    if(f==-1 && r==-1){
        f++;
        r++;
        arr[r]=data;
        return;
    }else{
        r=(r+1)%MAX_SIZE;
        arr[r]=data;
    }
}


void display(){
    if(isEmpty()){
        return;
    }
    int i=f;
    do{
        printf("%d\t",arr[f]);
        i=(f+1)%MAX_SIZE;
    }while(i!=((r+1)%MAX_SIZE));
}

void dequeue(){
    if(isEmpty()){
        return;
    }
    f=(f+1)%MAX_SIZE;
}

void main(){
    int choice,data,found;
    do{
        printf("\n1. Insert\n2. Remove\n3. Display\n0.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter data : ");
                    scanf("%d",&data);
                    enqueue(data);
                    display();
                    break;
            case 2: dequeue();
                    display();
                    break;
            case 3: printf("\nQueue elements are: ");
                    display();
                    break;
            // case 4: printf("\nEnter element to search : ");
            //         scanf("%d",&data);
            //         found=search(data);
            //         if(found){
            //             printf("\nElement '%d' found at position '%d'",data,found);
            //         }else{
            //             printf("\nNo such element found");
            //         }
            //         break;
            case 0: printf("Exiting.......\n");
                    break;
            default:printf("\nInvalid input , try again....");

        }

    }while(choice);
    
}