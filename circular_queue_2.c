#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int rear = -1, front = -1;
void insert(int a[], int x);
int delete(int a[]);
void display(int a[]);
int main()
{
    int a[MAX], n, m, ch;
    while (1)
    {
        printf("\n1: Insert \n");
        printf("2: Delete \n");
        printf("Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element : ");
            scanf("%d", &n);
            insert(a, n);
            break;
        case 2:
            m = delete(a);
            if (m != -1)
                printf("Deleted element is : %d\n", m);
            break;
        }
    }
    return 0;
}
void insert(int a[], int x)
{
    if (front == (rear + 1) % MAX)
    {
        printf("Queue Full\n");
        return;
    }

    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    a[rear] = x;
    printf("%d inserted\n", x);
}
int delete(int a[])
{
    int x;
    if (front == -1)
    {
        printf("Queue Empty\n");
        return -1;
    }
    x = a[front];
    if (front == rear) 
        front = rear = -1;
    else
        front = (front + 1) % MAX;
    return x;
}