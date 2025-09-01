#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int rear =-1,front=0;
void insert(int a[],int x);
int delete(int a[]);
int main()
{
	int a[MAX],n,m,ch;
	while(1)
	{
		printf("1: Insert \n");
		printf("2: Delete \n");
		printf("Enter choice : \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter element : \n");
					scanf("%d",&n);
					insert(a,n);
					break;
			case 2: m = delete(a);
			        printf("deleted element is : %d \n",m);	
					break;
			default : exit(1);			
		}
	}
	return 0;		
}
void insert(int a[],int x)
{
	++rear;
	if(rear==MAX)
	{
		printf("Queue Full \n");
		exit(1);
	}
	a[rear]=x;
}
int delete(int a[])
{
	if(front>rear)
	{
		printf("Queue Empty \n");
		exit(1);
	}
	return a[front++];
}
