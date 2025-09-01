#include <stdio.h>
#define Size 80
// function prototypes
void push(int a[],int x);
int eval(char exp[]);
int isdigit(char sym);
int oper(int sym,int op1,int op2);
int pop(int a[]);
int top=-1;
int main()
{
	char exp[Size];
	printf("\n Input the postfix expression");
	scanf("%d[\n]",exp);
	printf("%d",eval(exp));
	return 0;
}
int eval(char exp[])
{
	int i,op1,op2,j;
	char c;
	for(i=0;exp[i]!='\0';i++)
	{
		c=exp[i];
		if(c=='')
		continue;
		if(isdigit(c)==1) 
		push(a,c-'0');
		else
		{
			op2=pop(a);
			op1=pop(a);
			val=oper(c,op1,op2);
		}
	}
}
int isdigit(char sym)
{
	if((sym>='0') && (sym<='9'))
	return 1;
	else
	return 0;
}
int oper(int sym,int op1,int op2)
{
	switch(sym)
	{
		case '+': return(op1+op2);
		case '-': return(op1-op2);
		case '*': return(op1*op2);
		case '/': return(op1/op2);
	}
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
