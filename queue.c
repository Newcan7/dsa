#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int rear =-1;
void insert(int a[],int x);
int delete(int a[]);
void Display(int a[]);
int main()
{
	int a[SIZE],n,m,ch;
	while(1)
	{
		printf("1: Insert \n");
		printf("2: Delete \n");
		printf("3: Display \n");
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
			case 3: Display(a);
					break;
			default : exit(1);			
		}
	}
	return 0;		
}
void insert(int a[],int x)
{
	if(rear==SIZE-1)
	{
		printf("Queue Full \n");
		exit(1);
	}
	a[++rear]=x;
}
int delete(int a[])
{
	int i,e;
	if(rear==-1)
	{
		printf("Queue Empty \n");
		exit(1);
	}
	e=a[0];
	for(i=0;i<rear;i++)
	{
		a[i]=a[i+1];
	}
	--rear;
	return e;
	
}
void Display(int a[])
{
	int i;
	for(i=0;i<=rear;i++)
	{
		printf("%d <-- ",a[i]);
	}
}