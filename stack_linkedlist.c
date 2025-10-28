#include <stdio.h>
#include <stdlib.h>
typedef struct list 
{
int key;
struct list* next;
} NODE;
NODE* head = NULL;
void push(int x);
int main() 
{
    int c, value;
    while (1) 
	{
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c) 
		{
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                if (head == NULL) {
                    printf("Stack Underflow\n");
                } else {
                    value = pop();
                    printf("Popped: %d\n", value);
                }
                break;
            case 3:
                if (head == NULL) {
                    printf("Stack is empty\n");
                } else {
                    value = peek();
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
        }
    }
    return 0;
}
NODE* create(int k) 
{
    NODE* p = (NODE*)malloc(sizeof(NODE));
    p->key = k;
    p->next = NULL;
    return p;
}
void push(int x) 
{
    NODE* p = create(x);
    if(head==NULL)
    {
        p->next=NULL;
        head=p;
    }
    else
    {
        p->next = head;
        head = p;
    }
}
int pop() 
{
    if (head == NULL) 
	{
        printf("Stack Empty\n");
        exit(1);
    }
    int r = head->key;
    NODE* temp = head;
    head = head->next;
    free(temp);
    return r;
}
int peek() 
{
    if (head == NULL) 
    {
        printf("Stack is empty !! \n");
        exit(1);
    }
    return head->key;
}
void display() 
{
    if (head == NULL) 
	{
        printf("Stack is empty !! \n");
        return;
    }
    NODE* p = head;
    printf("Stack elements : ");
    while (p) 
	{
        printf("%d <-- ", p->key);
        p = p->next;
    }
    printf("\n");
}
