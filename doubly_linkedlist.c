#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
int key;
struct list *next, *prev;
} NODE;
NODE* head =NULL;
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
	if(!head)     // just testing //
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
	if(!head)
	{
		head=p;
		return;
	}
	p->next=head;
	head->prev=p;
	head=p;
	p->prev=head;
}
void insertPos(int k,int pos)
{
	NODE*p= create(k), *q=head;
	int i;
	for(i=1;i<pos-1;i++)
	{
		q=q->next;
	}
	p->next = q->next;
    p->prev = q;
    q->next->prev = p;
    q->next = p;
}
int deleteLast()
{
	NODE*p=head,*q;
	int k;
	while(p->next->next)
		p=p->next;
	q=p->next;
	p->next=q->prev=NULL;
	k=q->key;
	free(q);
	return k;
}
int deleteFirst()
{
	NODE *p=head, *q=head->next;
	int k;
	q->prev=head;
	head=q;
	p->next=NULL;
	k=p->key;
	free(p);
    return k;
}
int deletePos(int pos)
{
	NODE *p=head,*q;
	int i,k;
	for(i=0;i<pos-1;i++)
		p=p->next;
	q=p->next;
	p->next=q->next;
	q->next->prev=p;
	q->next=q->prev=NULL;
	k=q->key;
	free(q);
	return k;
}
int deleteVal(int pos)
{
	NODE *p=head,*q;
	while(p)
	{
		if(p->key==pos)
		{
			q=p->prev;
			q->next=p->next;
			p->next->prev=q;
			p->next=p->prev=NULL;
			free(p);
			return pos;
		}
		else
		p =p->next;
	}
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
int main() {
    int choice, value, pos;
    while (1) {
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Pos\n");
        printf("4. Delete First\n");
        printf("5. Delete Last \n");
        printf("6. Delete at Pos\n");
		printf("7. Delete a specific value\n");
        printf("8. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
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
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert : ");
                scanf("%d", &pos);
                insertPos(value, pos);
                break;
             case 4:
                printf("Deleted value from first: %d\n", deleteFirst());
                break;
            case 5:
                printf("Deleted value from last: %d\n", deleteLast());
                break;
			case 6:
				printf("Enter postion to delete from : \n");
				scanf("%d",&pos);
				printf("Deleted value from position %d is : %d\n",pos, deletePos(pos));
				break;
			case 7:
				printf("Enter value to delete : \n");
				scanf("%d",&pos);
				printf("Deleted value : %d\n", deleteVal(pos));
				break;
            case 8:
                printf("Linked List: ");
                display();
                break;
            default:
                printf("Invalid choice \n");
        }
    }
    return 0;
}