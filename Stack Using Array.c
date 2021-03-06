#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int size;
	int top;
	int *Array;
};

void createStack(struct Stack *St)
{
	printf("Enter Size : ");
	scanf("%d",&St->size);
	St->Array = (int *)malloc(St->size*sizeof(int));
	St->top = -1;
}

void pushinStack(struct Stack *St,int x)
{
	if(St->top == St->size-1)
	printf("Stack Overflow\n");
	else
	 {
	 	St->top++;
	 	St->Array[St->top] = x;
	 }
}

int popfromStack(struct Stack *St)
{
	int x = -1;
	if(St->top == -1)
		printf("Stack Underflow\n");
	else
	 {
	 	x = St->Array[St->top];
	 	St->top--;
	 }
	 return x;
}   

void printStack(struct Stack St)
{
	int i;
	printf("Elements present in Stack from top : ");
	for(i=St.top;i>-1;i--)
	printf("%d ",St.Array[i]);
}
int main()
{
	int i,n,x;
	struct Stack St;
	createStack(&St);
	
	printf("Enter the number of values to push : ");
	scanf("%d",&n);
	
	printf("\nEnter elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		pushinStack(&St,x);
	}
	
	printStack(St);
}
