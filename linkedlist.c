 #include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int key;
	struct list* next;
} NODE;
NODE* head =NULL;
NODE* create(int k);
NODE* create(int k)
{
	NODE* x =(NODE*)malloc(sizeof(NODE));
	x->key=k;
	x->next=NULL;
	return x;
}

void reverse()
{
	NODE *prev=NULL, *next=NULL, *curr=head;
	while(curr)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;
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
}
void insertFirst(int k)
{
	NODE* p=create(k);
	p->next=head;
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
int deleteFirst()
{
	NODE* p=head;
	if(head==NULL)
	{
		printf("List Empty !! \n");
		exit(1);
	}
	int r=p->key;
	head=head->next;
	p->next=NULL;
	free(p);
	return r;
}
int deleteLast()
{
	NODE* p=head;
	if(head==NULL)
	{
		printf("List Empty !! \n");
		exit(1);
	}
	int k;
	while(p->next->next)
	p=p->next;
	k=p->next->key;
	p->next=NULL;
	return k;
}
int deletePos(int pos)
{
	NODE* p=head,*q;
	if(head==NULL)
	{
		printf("List Empty !! \n");
		exit(1);
	}
	int k,i;
	for(i=1;i<pos-1;i++)
	p=p->next;
	k=p->next->key;
	q=p->next;
	p->next=q->next;
	q->next=NULL;
	free(q);
	return k;
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
		printf("7. Reverse List.\n");
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
                printf("Enter position to delete : ");
                scanf("%d", &pos);
                printf("Deleted value from position %d: %d\n", pos, deletePos(pos));
                break;
			case 7:
				reverse();
				printf("List Reversed !! \n");
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


