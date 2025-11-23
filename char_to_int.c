#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
int key;
struct list *next, *prev;
} NODE;
NODE* head =NULL;
NODE* create(int k);
NODE* create(int k)
{
	NODE* p =(NODE*)malloc(sizeof(NODE));
	p->key=k;
	p->next=p->prev=NULL;
	return p;
}
void insertLast(int k)
{
	NODE *p= create(k), *q=head;
	if(!head)
	{
		head=p;
		return;
	}
	while(q->next)
	q=q->next;
	q->next=p;
	p->prev=q;
}
void display()
{
	NODE*p=head;
	while(p)
	{
		printf("%d",p->key);
		p=p->next;
	}
		printf("\n");
}
int main() 
{
    int i,j=0;
    char arr[100];
    printf("Enter integer to be taken as string : \n");
    scanf("%[^\n]", arr);
    for(i=0;arr[i];i++)
    {
        j=arr[i]-48;
        insertLast(j);
    }
    printf("The given number represented as linked list is : \n");
    display();
    return 0;
}
