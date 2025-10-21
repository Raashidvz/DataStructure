#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int size;
int* createBitset(int universal[] ,int set[]){
    int* bitSet=(int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++){
        bitSet[i]=0;
        for(int j=0;j<size;j++){
            if(universal[i]==set[j]){
                bitSet[i]=1;
                break;
            }
        }
    }
    return bitSet;
}

void display(int set[]){
    for(int i=0;i<size;i++){
        printf("%d\t",set[i]);
    }
}

void Union(int setA[],int setB[]){
    int unionSet[size];
    for(int i=0;i<size;i++){
        if(setA[i] | setB[i]){
            unionSet[i]=1;
        }else{
            unionSet[i]=0;
        }
    }
    printf("\nUnion : [");
    for(int i=0;i<size;i++){
        printf("\t%d",unionSet[i]);
    }
    printf("\t]");
}

void intersection(int setA[],int setB[]){
    int interSet[size];
    for(int i=0;i<size;i++){
        if(setA[i] & setB[i]){
            interSet[i]=1;
        }else{
            interSet[i]=0;
        }
    }
    printf("\nIntersection : [ ");
    for(int i=0;i<size;i++){
        printf("\t%d",interSet[i]);
    }
    printf("\t]");
}

void difference(int set1[],int set2[]){
    int diff[size];
    for(int i=0;i<size;i++){
        if(set1[i] & ~set2[i]){
            diff[i]=1;
        }else{
            diff[i]=0;
        }
    }
    printf("\nDifference : [ ");
    for(int i=0;i<size;i++){
        printf("\t%d",diff[i]);
    }
    printf("\t]");
}


void main(){
    int U,A,B,n,u,choice;
    printf("\nEnter the size of Universal set : ");
    scanf("%d",&size);
    int universal[size];
    int bitA[size];
    int bitB[size];
    printf("\nEnter %d elements for U : ",size);
    for(int i=0;i<size;i++){
        scanf("%d",&universal[i]);
    }

    printf("\nEnter the size of A set : ");
    scanf("%d",&n);
    int setA[n];
    printf("\nEnter %d elements for A : ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&setA[i]);
    }

    printf("\nEnter the size of B set : ");
    scanf("%d",&n);
    int setB[n];
    printf("\nEnter %d elements for B : ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&setB[i]);
    }

    
    int* bitsetB=createBitset(universal,setB);
    int* bitsetA=createBitset(universal,setA);

    do{
        printf("\n1. A|B(Union)\n2. A&B(Intersect)\n3. A-B\n4. B-A\n5. Exit\n0. Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nSETA: ");
                    display(bitsetA);
                    printf("\nSETB: ");
                    display(bitsetB);
                    Union(bitsetA,bitsetB);
                    break;
            case 2: printf("\nSETA: ");
                    display(bitsetA);
                    printf("\nSETB: ");
                    display(bitsetB);
                    intersection(bitsetA,bitsetB);
                    break;
            case 3: printf("\nSETA: ");
                    display(bitsetA);
                    printf("\nSETB: ");
                    display(bitsetB);
                    difference(bitsetA,bitsetB);
                    break;
            case 4: printf("\nSETA: ");
                    display(bitsetA);
                    printf("\nSETB: ");
                    display(bitsetB);
                    intersection(bitsetB,bitsetA);
                    break;
            case 0: printf("\nExiting......!");
                    break;
            default:printf("\nWrong input!");
        }
    }while(choice!=0);
    
}