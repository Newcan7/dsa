#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int queue[SIZE];
int rear =-1;
void insert(int x);
int delete();
void Display();
int main()
{
	int n,ch;
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
					insert(n);
					break;
			case 2: printf("deleted element is : %d \n",delete(queue));	
					break;
			case 3: Display();
					break;
			default : exit(1);			
		}
	}
	return 0;		
}
void insert(int x)
{
	if(rear==SIZE-1)
	{
		printf("Queue Full \n");
		exit(1);
	}
	queue[++rear]=x;
}
int delete()
{
	int i,x;
	if(rear==-1)
	{
		printf("Queue Empty \n");
		exit(1);
	}
	x=queue[0];
	for(i=0;i<rear;i++)
	{
		queue[i]=queue[i+1];
	}
	rear--;
	return x;
}
void Display()
{
	int i;
	for(i=0;i<=rear;i++)
	{
		printf("%d <-- ",queue[i]);
	}
	printf("/n");
}