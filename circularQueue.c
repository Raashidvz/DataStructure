#include <stdio.h>
#define MAX_SIZE 5

int arr[MAX_SIZE];
int f=-1,r=-1;

int isEmpty(){
    // if(f == -1 && r == -1 ){
    //     // printf("UnderFLow\n");
    //     return 1;
    // }else if((r+1)%MAX_SIZE == f){
    //     // printf("UnderFLow\n");
    //     return 1;
    // }else{
    //     return 0;
    // }
    return (f == -1 && r == -1);
    
}

int isFull(){
    // if((r+1)%MAX_SIZE==f){
    //     printf("OverFlow");
    //     return 1;
    // }else{
    //     return 0;
    // }
    return ((r + 1) % MAX_SIZE == f);
    
}

void enqueue(int data){
    if(isFull()){
        printf("Queue Overflow!\n");
        return;
    }
    if(f==-1 && r==-1){
        f=0;
        r=0;
    }else{
        r=(r+1)%MAX_SIZE;
        
    }
    arr[r]=data;
}


void display(){
    if(isEmpty()==1){
        printf("\nQueue is Empty\n");
        return;
    }
    int i=f;
    while(i!=r){
        printf("%d\t",arr[i]);
        i=(i+1)%MAX_SIZE;
    }
    printf("%d\n", arr[r]);
}

int search(int key){
    if(isEmpty()){
        printf("\nQueue is Empty\n");
        return 0;
    }
    int i=f,count=1;
    // do{
    //     count+=1;
    //     if(key == arr[i]){
    //         return count;
    //     }
    //     i=(i+1)%MAX_SIZE;
    // }while(i!=((r+1)%MAX_SIZE));

    while (i != r) {
        if (arr[i] == key) {
            return count;
        }
        i = (i + 1) % MAX_SIZE;
        count++;
    }
    if (arr[r] == key) { 
        return count;
    }
    return 0;
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }
    if (f == r) {  
        f = r = -1;
    } else {
        f = (f + 1) % MAX_SIZE;
    }
}

void main(){
    int choice,data,found;
    do{
        printf("\n1. Insert\n2. Remove\n3. Display\n4. Search\n0.Exit\nEnter your choice : ");
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
            case 4: printf("\nEnter element to search : ");
                    scanf("%d",&data);
                    found=search(data);
                    if(found){
                        printf("\nElement '%d' found at position '%d'",data,found);
                    }else{
                        printf("\nNo such element found");
                    }
                    break;
            case 0: printf("Exiting.......\n");
                    break;
            default:printf("\nInvalid input , try again....");

        }

    }while(choice!=0);
    
}
