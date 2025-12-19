#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void merge(int a[],int l,int mid,int u)
{
    int i=l,k=l,j=mid+1;
    int t[u];
    while(i<=mid && j<=u)
    {
        if(a[i]<=a[j])
            t[k++]=a[i++];
        else
            t[k++]=a[j++];    
    }
    while(i<=mid)
        t[k++]=a[i++];
    while (j<=u)
        t[k++]=a[j++];
    for(k=l;i<=u;k++)
        a[k]=t[k];
    
}
void merge_sort(int a[], int l, int u)
{
    if(l<u)
    {
        merge_sort(a,l,((l+u)/2));
        merge_sort(a,((l+u)/2)+1,u);
        merge(a,l,((l+u)/2),u);
    }
}

void display(int a[])
{
    int i;
    printf("Merge Sorted Array is : \n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d \n", a[i]);
	}
}

int main()
{
	int i,j,ch;
	int Array[SIZE];
	printf("Enter unsorted elements : \n");
	for(i=0;i<SIZE;i++)
	{
		scanf("%d", &Array[i]);
	}
	printf("1 for merge sort \n");
    printf("2. Display \n");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: merge_sort(Array,0,4);
		break;
        case 2: display(Array);
        break;
	}
	return 0; 
}
