 #include<stdio.h>
#include<stdlib.h>
typedef struct list
{
int key;
struct list *next, *prev;
} NODE;
NODE* head =NULL;
NODE* create(int k);
int main() 
{
    int ch, value;
    while (1) 
	{
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Display\n");
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
            case 3:
                printf("Linked List: ");
                display();
                break;
        }
    }
    return 0;
}
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





