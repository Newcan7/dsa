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
int count_nodes(NODE *r)
{
	if(r==NULL)
	return 0;
	return 1+ count_nodes(r->left)+count_nodes(r->right);
}
int count_leaf(NODE *r)
{
	if(r==NULL)
	return 0;
	if(r->left==NULL && r->right==NULL)
	return 1;
	return count_leaf(r->left)+count_leaf(r->right);
}
int search(NODE *r,int key)
{
	while(r)
	{
		if(key==r->key)
			return 1;
		else if (key<r->key)
			r=r->left;
		else
			r=r->right;		
	}
	return 0;
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
		printf("3. Count nodes\n");
		printf("4. Count leaf\n");
		printf("5. Search an element\n");
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