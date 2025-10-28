#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int key;
    struct list* next;
} NODE;
NODE* head = NULL;
NODE* create(int k);
NODE* create(int k) 
{
    NODE* x = (NODE*)malloc(sizeof(NODE));
    x->key = k;
    x->next = NULL;
    return x;
}
void insert(int k) 
{
    NODE* p = create(k);
    if (!head) 
	{
        head=p;
    } 
    else 
    {
        p->next=head;
        head=p;
    }
}
int delete() 
{
    if (!head) 
	{
        printf("Queue Empty\n");
        exit(1);
    }
    int r;
    NODE* p = head;
    while(p->next->next)
        p=p->next;
    r=p->next->key;
    p->next=NULL;
    free(p->next);
    return r;
}
void display() 
{
    NODE* p = head;
    while (p) 
	{
        printf("%d --> ", p->key);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int ch, val;
    while (1) {
        printf("1: Insert\n");
        printf("2: Delete\n");
        printf("3: Display\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                printf("Deleted value: %d\n", delete());
                break;
            case 3:
                display();
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
