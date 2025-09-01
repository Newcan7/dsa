#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int rear =-1,front=0,count=0;
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
	if(count>=MAX)
		printf("Queue Full \n");
	else
	count++;
	if(rear>=MAX)
	rear=0;
	else
	rear ++;
	
	a[rear]=x;
}
int delete(int a[])
{
	int x;
	if(count<=0)
	printf("Queue Empty \n");
	else 
	count--;
	x=a[front];
	return x;
}
