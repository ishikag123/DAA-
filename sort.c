#include<stdio.h>
void printarray(int arr[],int n){
	for (int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void bubble_sort(int arr[],int n){
	int c;
	
	for(int i=0;i<n-1;i++){
		for (int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
			
			c=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=c;
		}
		}
		
	}
}

void insertion_sort(int arr[],int n){
	int i,j,key;
	for(i=1;i<=n-1;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>=key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

void selection_sort(int a[],int n){
	int i,j,temp,indexOfMin;
	for(i=0;i<n-1;i++){
		indexOfMin=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[indexOfMin]){
				indexOfMin=j;
			}
		}
		temp=a[i];
		a[i]=a[indexOfMin];
		a[indexOfMin]=temp;
	}
}

void merge(int a[],int mid,int low,int high){
	int i,j,k;
	int n=high+low-1;
	int b[n];
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid&&j<=high){
		if(a[i]<a[j]){
			b[k]=a[i];
			i++;
			k++;
		}
		else{
			b[k]=a[j];
			j++;
			k++;
		}
		
	}
	while(i<=mid){
			b[k]=a[i];
			k++;
			i++;
		}
	while(j<=high){
			b[k]=a[j];
			k++;
			j++;
		}
	for(i=low;i<=high;i++){
			a[i]=b[i];
		}
}

void mergesort(int a[],int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,mid,low,high);
	}
}

  

int partition(int a[],int lb,int ub){
	int i,j,pivot;
	pivot=a[lb];
	i=lb;
	j=ub;
	while(i<j){
		while(a[i]<=pivot){
			i++;
		}
		while(a[j]>pivot){
			j--;
		}
		if(i<j){
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[j],&a[lb]);
	return j;
}

void quick_sort(int a[],int lb,int ub){
	int pos;
	if(lb<ub){
		pos=partition(a,lb,ub);
		quick_sort(a,lb,pos-1);
		quick_sort(a,pos+1,ub);
	}
}

int main(){
	int arr[]={1,54,8,63,954};
	int n=5;
	printarray(arr,n);
	quick_sort(arr,0,4);
	printarray(arr,n);
	return 0;
}