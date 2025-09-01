#include<stdio.h>
#define SIZE 5
int linear_search(int arr[],int size,int key);
int main()
{
	int i,j,ans,n,size =5;
	printf("element to find : \n");
	scanf("%d", &n);
	int Array[SIZE];
	printf("Enter elements : \n");
	for(i=0;i<SIZE;i++)
	{
		scanf("%d", &Array[i]);
	}
	ans = linear_search(Array,size,n);
	if(ans=1)
	printf("ELEMENT NOT FOUND");
	else
	printf("the element %d is at %d index ",n,ans);
	return 0;
}
int linear_search(int arr[],int size,int key)
{
	if(size==0)
	return -1;
	if(arr[size-1]==key)
	return size-1;
	return linear_search(arr,size-1,key);
}

