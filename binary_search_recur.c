#include<stdio.h>
#define SIZE 5
int binary_search(int a[], int key, int high,int low);
int main()
{
	int i,j,ans,n,size =5,high=4,low=0;
	printf("element to find : \n");
	scanf("%d", &n);
	int Array[SIZE];
	printf("Enter elements : \n");
	for(i=0;i<SIZE;i++)
	{
		scanf("%d", &Array[i]);
	}
	if(binary_search(Array,n,high,low) ==1 )
	printf("element found");
	
	return 0;
}
int binary_search(int a[], int key, int high,int low)
{
	int mid;
		mid=(low+high)/2;
		if(key==a[mid])
		return 1;
		if (key<a[mid])
		binary_search( a, key,mid-1,low);
		else
		binary_search(a, key,high,mid+1);
		return 0;
}
