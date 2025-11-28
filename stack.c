#include<stdio.h>
#include<stdlib.h>
#define Size 100
int top =-1;
void push(int a[],int x)
{
	++top;
	if(top==Size)
	{
		printf("Stack Overflow !! \n");
		exit(1);
		
	}
	a[top]=x;
}
 
int pop(int a[])
{
	if(top==-1)
	{
		printf("Stack empty \n");
		exit(1);
		
	}
	return a[top--];
}
int peek(int a [])
{
	return(a[top]);
}
int main()
{
int a[Size],n,x,i,c;
while(1)
{
printf(" 1 for push: \n");
printf(" 2 for pop: \n");
printf(" 3 for peek: \n");
printf(" 4 to display: \n");
printf(" enter choice \n");
scanf("%d",&c);
switch(c)
{
	case 1 :
	printf("Enter element to push : \n");
	scanf("%d",&x);
	push(a,x);
	break;
case 2 :
	for(i=0;i<n;i++)
	{
		x=pop(a);
		printf("%d \n",x);
	}
break;
case 3 :
	printf("peek is %d \n",peek(a));
	break;
case 4: 
	for(i=top;i>=0;i--)
	{
		printf("%d \n",a[i]);
	}
	break;
}
}
return 0;
}