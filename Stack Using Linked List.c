#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *top = NULL;

void pushinStack(int x)
{
	struct Node *p;
	p = top;
	
	if(top == NULL)
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = x;
		p->next = NULL;
		top = p;
	}
	else
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = x;
		p->next = top;
		top = p;
	}
}

void printStack(struct Node *temp)
{
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
int main()
{
	int i,n,x;
	
	printf("Enter the no of elements to push : ");
	scanf("%d",&n);
	
	
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		pushinStack(x);
	}

	printf("Elements in Stack are : ");
	printStack(top);
}
