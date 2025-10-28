#include<stdio.h>
#define MAX 5
int rear=-1;
int delete(int[]);
void insert(int k,int[]);
int main()
{
    int a[MAX], n, m, ch;
    while (1)
    {
        printf("1: Insert \n");
        printf("2: Delete \n");
        printf("Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element : ");
            scanf("%d", &n);
            insert(n,a);
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
void insert(int k , int a[])
{
    if(rear==MAX-1)
    {
        printf("Queue Full !! \n");
        return;
    }
    a[++rear]=k;
}
int delete(int a[])
{
    int i,t;
    if(rear==-1)
    {
        printf("Queue Empty !! \n");
        return -1;
    }
    t=a[0];
    for(i=0;i<=rear;i++)
    {
        a[i]=a[i+1];
    }
    rear--;
    return t;
}
