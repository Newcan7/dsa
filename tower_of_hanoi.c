#include<stdio.h>
void TOH(int n,char from ,char to ,char aux);
int main()
{
    printf("Enter Number of Disks : \n");
    int n;
    char from = 'A';
    char to = 'C';
    char aux = 'B';
    scanf("%d",&n);
    TOH(n,from,to,aux);
    return 0;
}
void TOH(int n,char from ,char to ,char aux)
{
    if(n==1)
    {
        printf("Moved disk 1 from rod %c to rod %c \n",from,to);
        return;
    }
        TOH(n-1,from,aux,to);
        printf("Moved disk %d from rod %c to rod %c \n",n,from,to);
        TOH(n-1,aux,to,from);
}
