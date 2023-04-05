#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* createArray(int n,int j,int k){
    if(j>=k||(k-j)<=n){
        printf("invalid choice for j and k");
    }
    else{
        int *A=malloc(n*sizeof(int));
        srand(time(0));
        for(int i=0;i<n;i++){
            A[i]=(rand()%(k-j+1))+j;
        }
    return A;
    }
}

void printArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void Bucket_Sort(int array[], int size,int m,int n) 
{
    int max = n;  
    int bucket[max+1];  
 
    
    for (int i = 0; i <= max; i++)  
    bucket[i] = 0;  
 
    for (int i = 0; i < size; i++)  
    bucket[array[i]]++;
    int j=0;   
    for (int i = 0; i <= max; i++)  
    { 
        if (bucket[i] > 0){        
            array[j++] = i; 
        }  
    }  
}  

int* taskC(int n,int j,int k){
    int* b=createArray(n,j,k);
    Bucket_Sort(b,n,j,k);
    return b;
}

int main()
{
    int j,k,n;
    printf("n=");
    scanf("%d",&n);
    printf("enter the value of j,k:");
    scanf("%d%d",&j,&k);
    int* A=taskC(n,j,k);
    printArray(A,n);

    return 0;
}