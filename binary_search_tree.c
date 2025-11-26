#include<stdio.h>
#include<stdlib.h>
typedef struct element
{ 	
	int key;
	struct element *left, *right;
}NODE;
NODE *root=NULL;
void insert(int k)
{
	NODE *p=(NODE*)malloc(sizeof(NODE)), *q=root, *r;
	p->key=k;
	p->left=p->right=NULL;
	if(!root)
	{
		root=p;
		return;
	}
	while(q)
	{
		r=q;
		if(k<q->key)
			q=q->left;
		else
			q=q->right;
	}
	if(k<r->key)
		r->left=p;
	else
		r->right=p;
}
void inorder_display(NODE *r)
{
	if(r)
	{
		inorder_display(r->left);
		printf("%d  ",r->key);
		inorder_display(r->right);
	}
}
int main() {
    int choice, value;
    while (1) {
        printf("1. Insert \n");
        printf("2. Inorder Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert : ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                inorder_display(root);
                break;
            default:
                printf("Invalid choice \n");
        }
    }
    return 0;
}