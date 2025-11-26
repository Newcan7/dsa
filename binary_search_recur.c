#include<stdio.h>
#define SIZE 5
int arr[SIZE];
int binary_search(int key,int low,int high);
int main()
{
	int i,n,high=SIZE-1,low=0;
	printf("Element to find : \n");
	scanf("%d", &n);
	printf("Enter elements : \n");
	for(i=0;i<SIZE;i++)
	{
		scanf("%d", &arr[i]);
	}
	if(binary_search(n,high,low)==1)
		printf("Element found");
	return 0;
}
int binary_search(int key,int low,int high)
{
	int mid;
		mid=(low+high)/2;
		if(key==arr[mid])
			return 1;
		if (key<arr[mid])
			binary_search(key,low,mid-1);
		else if(key>arr[mid])
			binary_search(key,mid+1,high);
		return 0;
} // bithday update happy birthday !!!!
