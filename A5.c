#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int *taskA(int n){
     int j,k;
    
    // printf("n=");
    // scanf("%d",&n);
    printf("the value of j and k are:");
    scanf("%d%d",&j,&k);

    if(j<=1||k<=1||j>=n||k>=n||j>=k){
        printf("invalid choice for j and k");
    }
    else{
        int *A=malloc(n*sizeof(int));
        for(int i=0;i<n;i++){
            A[i]=(rand()%(k-j+1))+j;
        }
    return A;
    }
}

void taskB(int *a,int n){
    int *count=malloc((n)*sizeof(int));
    for(int i=0;i<=n-1;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[a[i]]=count[a[i]]+1;
    }
    int i=0,j=0;
    while(i<=n-1){
        if(count[i]>0){
            a[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++;
        }
    }
    printArray(a,n);
}

int main()
{
    int n;
    printf("n=");
    scanf("%d",&n);

    srand(time(0));
    int *B=taskA(n);
    printArray(B,n);
    taskB(B,n);

    return 0;
}