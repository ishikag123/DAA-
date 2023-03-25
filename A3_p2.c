#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearsearch(int arr[],int size,int element){
		for (int i=0;i<size;i++){
			if (arr[i]==element){
				return i;
			}
		}
        return -1;

}

int method0 ( int *A, int n )
{
    int a,b,c,i,j,k,flag=0;
    for (a=1;a<=n;a++){
        for(b=a+1;b<=n;b++){
            for(c=b+1;c<=n;c++){
                j=linearsearch(A,n,a);
                k=linearsearch(A,n,b);
                i=linearsearch(A,n,c);
                if(i>=0 && j>=0 && k>=0 && i<j && i<k && j<k){
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag){
        return 0;
    }
    else{
        return 1;
    }
}

int method1 ( int *A, int n )
{
    int flag=0,a,b,c;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(A[i]>A[k] && A[i]>A[j] && A[j]<A[k]){
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag){
        return 0;
    }
    else{
        return 1;
    }
}

int method2 ( int *A, int n )
{
    int c,flag=0;
    for(int i=0;i<n;i++){
        c=A[i];
        for(int j=i+2;j<=n-1;j++){
            if(A[i+1]<c && A[j]<c && A[i+1]<A[j]){
                flag=1;
                break;
            }
        }
    }
    if(flag){
        return 0;
    }
    else{
        return 1;
    }
}

int method3 ( int *A, int n )
{
//your method should return 1 on success, and 0 on failure
//write an O(n) method to solve this probelm
//hint: you may look into the stack concept
}

int main ()
{
   int i, n, *A, *B;

   //scan the input
   scanf("%d", &n);
   A = (int*) malloc (sizeof(int)*n);
   for (i=0; i<n; ++i) scanf(" %d", &A[i]);

   printf("\n");
    printf("    Method 0: %s\n", method0(A,n) ? "Valid" : "Invalid");
    printf("    Method 1: %s\n", method1(A,n) ? "Valid" : "Invalid");
    printf("    Method 2: %s\n", method2(A,n) ? "Valid" : "Invalid");
//    printf("    Method 3: %s\n", method3(A,n) ? "Valid" : "Invalid");

   exit(0);
}
