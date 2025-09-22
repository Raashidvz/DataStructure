/******************************************************************************

Merge two sorted arrays in sorted order.

*******************************************************************************/
#include <stdio.h>

// Function to display Array
void display(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

// Function to sort Array
void sort(int arr[],int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i] > arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    // Call display to show sorted array
    display(arr,size);
}


int main()
{
    int m,n,i,j,k;
    sizeCheck:
    printf("Enter size of array 1 : ");
    scanf("%d",&m);
    
    
    printf("Enter size of array 2 : ");
    scanf("%d",&n);
    
    // Validation for negative array size
    if(m<0 || n<0){ 
        printf("\nInvalid size, enter a positive digit for both array size!\n");
        goto sizeCheck;
    }
    
    // Declare array size
    int a[m];
    int b[n];
    int c[m+n];
    
    // Read First Array and sort it.
    printf("\nEnter %d elements for array 1 : ",m);
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    sort(a,m);
    
    // Read second array and sort it.
    printf("\nEnter %d elements for array 2 : ",n);
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    sort(b,n);
    
    // Store both arrays to third array in sorted order. 
    for(k=i=j=0;i<m && j<n;k++){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
        }else{
            c[k]=b[j];
            j++;
        }
    }
    
    // Add balance element of first array.
    if(i<m){
        while(i<m){
            c[k]=a[i];
            k++;
            i++;
        }
    }
    
    // Add balance element of second array.
    if(j<n){
        while(j<n){
            c[k]=b[j];
            k++;
            j++;
        }
    }
    
    printf("\nMerged Sorted array : ");
    display(c,m+n);
    

    return 0;
}
