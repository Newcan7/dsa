#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int main()
{
	void bubble_sort(int []);
    void selection_sort(int []);
    void insertion_sort(int []);
	void quick_sort(int[],int,int);
	int i,j,ch;
	int Array[SIZE];
	printf("Enter unsorted elements : \n");
	for(i=0;i<SIZE;i++)
	{
		scanf("%d", &Array[i]);
	}
	printf("1 for bubble \n");
	printf("2 for selection \n");
	printf("3 for insertion \n");
	printf("4 for quick \n");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: bubble_sort(Array);
		break; 
		case 2: selection_sort(Array);
		break;
		case 3: insertion_sort(Array);
		break;
		case 4: quick_sort(Array,0,SIZE-1);
		break;
	}
	return 0; 
}
void bubble_sort(int a[])
{
	int i,j,temp,flag;
	for(i=0;i<SIZE-1 && flag==1;i++)
	{
		flag=0;
		for(j=0;j<SIZE-i-1;j++)
			if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;	
					flag=1;
				}
	}
	printf("BUBBLE Sorted Array is : \n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d \n", a[i]);
	}
}
void selection_sort(int a[])
{
	int i,j,temp;
	for (i=0;i<SIZE-1;i++)
	for(j=i+1;j<SIZE;j++)
	if(a[i]>a[j])
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	printf("SELECTION Sorted Array is : \n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d \n", a[i]);
	}
}
void insertion_sort(int a[])
{
	int i,j,temp;
	for (i=0;i<SIZE;i++)
	{
	temp=a[i];
	for(j=i-1;j>=0 && temp< a[j] ;j--)
	  a[j+1]=a[j];
	a[j+1]=temp;
}	
	printf("INSERTION Sorted Array is : \n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d \n", a[i]);
	}
}
void quick_sort(int a[],int l,int h)
{
	int p,i;
	int partition(int[],int,int);
	if(l<h)
	{
		p = partition(a,l,h);
		quick_sort(a,l,p-1);
		quick_sort(a,p-1,h);
	}
	{
	printf("QUICK Sorted Array is : \n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d \n", a[i]);
	}
	exit(1);
	}
}
int partition(int a[],int l,int h)
{
	int low=l;
	int high =h;
	int pivot = a[low];
	int t;
	while(low<high)
	{
		while(a[low]<pivot)
			low++;
		while(a[high]>pivot)
			high--;
		if(low<high)
		{
			t=a[low];
			a[low]=a[high];
			a[high]=t;
		}
	}
	a[high]=pivot;
	return high;
}


