#include <stdio.h>

	int linearsearch(int arr[],int size,int element){
		for (int i=0;i< size;i++){
			if (arr[i]==element){
				return i;
			}
		}
		return -1;
	}
int binarysearch(int arr[],int size,int element){
	int low,mid,high;
	low=0;
	high=size-1;
	while(low<=high){
		mid=(low+high)/2;
	if (arr[mid]==element){
		return mid;
	}
	if(arr[mid]<element){
		low=mid+1;
	}
	else{
		high=mid-1;
		
		
	}
		
	}
	return -1;
	
}
int main(){
	int arr[]={1,8,56,98,174,223,341,456,548,564,608,739,1145};
	

	int size=sizeof(arr)/sizeof(arr[0]);
	int element;
//	for(int k=0;k<size;k++){
//		printf("%d ",arr[k]);
//	}
	printf("\nenter element:");
	scanf("%d",&element);
	int index=binarysearch(arr,size,element);
	printf("index=%d",index);
	return 0;
	
}