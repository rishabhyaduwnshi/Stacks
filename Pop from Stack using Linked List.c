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


void popfromStack()
{
	struct Node *temp;
	temp = top;
	if(top == NULL)
	printf("\nStack UnderFlow");
	else
	 {
	 	temp = top->next;
	 	free(top);
	 	top = temp;
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
	int i,n;
	
	pushinStack(5);
	pushinStack(51);
	pushinStack(55);
	pushinStack(56);
	pushinStack(11);
	pushinStack(555);
	
	
	printf("Currenly elements in stack are : ");
	printStack(top);
	
	
	printf("\n\nEnter the number of elements to pop : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	popfromStack();
	
	printf("\nElements after deletion : ");
	
	
	printStack(top);



}
