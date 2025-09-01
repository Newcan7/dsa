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
void insertFirst(int k)
{
	NODE* p=create(k);
	p->next=head;
	head->prev=p;
	head=p;
}
void insertPos(int k,int pos)
{
	NODE*p= create(k), *q=head;
	int i;
	for(i=1;pos-i;i++)
	{
		q=q->next;
	}
	p->next=q->next;
	p->prev=q;
	q->next=p;
}
void display()
{
	NODE*p=head;
	while(p)
	{
		printf("%d --> ",p->key);
		p=p->next;
	}
		printf("\n");
}
int main() 
{
    int ch, value,pos;
    while (1) 
	{
        printf("1. Insert at First \n");
        printf("2. Insert at Last \n");
		printf("3. Insert at Pos \n");
        printf("4. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value to insert at first: ");
                scanf("%d", &value);
                insertFirst(value);
                break;
            case 2:
                printf("Enter value to insert at last: ");
                scanf("%d", &value);
                insertLast(value);
                break;
            case 4:
                printf("Linked List: ");
                display();
                break;
			case3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert : ");
                scanf("%d", &pos);
                insertPos(value, pos);
                break;
        }
    }
    return 0;
}




