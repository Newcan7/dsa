#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int key;
    struct list* next;
} NODE;
NODE* front = NULL;
NODE* rear = NULL;
NODE* create(int k);
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
    if (!front) 
	{
        front = rear = p;
    } else {
        rear->next = p;
        rear = p;
    }
}
int delete() 
{
    if (!front) 
	{
        printf("Queue Empty\n");
        exit(1);
    }
    NODE* p = front;
    int r = p->key;
    front = front->next;
    if (!front) rear = NULL;
    free(p);
    return r;
}
void display() 
{
    NODE* p = front;
    while (p) 
	{
        printf("%d --> ", p->key);
        p = p->next;
    }
    printf("\n");
}

