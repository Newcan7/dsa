#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int rear = -1, front = -1;
int queue[MAX];
void insert(int x);
int delete();
void display();
int main()
{
    int n,ch;
    while (1)
    {
        printf("1: Insert \n");
        printf("2: Delete \n");
        printf("3. Display \n");
        printf("Enter choice : \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element : ");
            scanf("%d", &n);
            insert(n);
            break;
        case 2: 
            printf("Deleted element is : %d\n",delete());
            break;
        case 3:
            display();
            break;
        }
    }
    return 0;
}
void insert(int x)
{
    if (front == (rear + 1) % MAX)
    {
        printf("Queue Full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    printf("%d inserted \n", x);
}
int delete()
{
    int x;
    if (front == -1)
    {
        printf("Queue Empty\n");
        return -1;
    }
    x = queue[front];
    if (front == rear) 
        front = rear = -1;
    else
        front = (front + 1) % MAX;
    return x;
}
void display()
{
    int i;
    for(i=front;i<=rear;i=(i+1)%MAX)
    {
        printf("%d<-- ", queue[i]);
    }
    printf("\n");
}