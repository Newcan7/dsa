#include<stdio.h>
#include<stdlib.h>
#define Size 100
int top =-1;
int main()
{
int a[Size],n,x,i,y,c;
while(1)
{
printf(" 1 for push: \n");
printf(" 2 for pop: \n");
printf(" 3 for peek:\n");
printf(" 4 TO END:\n");
scanf("%d",&c);
	
switch(c)
{
	case 1 :
		printf("How many elements? \n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("Enter element to push : \n");
	scanf("%d",&x);
	push(a,x);
}
break;
case 2 :
	for(i=0;i<n;i++)
{
	x=pop(a);
	printf("%d \n",x);
}
break;
case 3 :
	y=peek(a);
printf("peek is %d \n",y);

break;
case 4: 
printf(" SYSTEM TERMINATING !!!!!!!! \n");
exit(1);
break;

}
}
return 0;
}
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
	int x;
	if(top==-1)
	{
		printf("Stack empty \n");
		exit(1);
		
	}
	x=a[top];
	top--;
	return x;
}

int peek(int a [])
{
	return(a[top]);
}
