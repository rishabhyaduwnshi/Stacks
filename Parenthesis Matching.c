#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Stack
{
	int size;
	int top;
	char *Array;
};


void createStack(struct Stack *St, int x)
{
	St->Array = (char *)malloc(x*sizeof(char));
	St->size = x;
	St->top = -1;
}


void pushinStack(struct Stack *St,char x)
{
	if(St->top == St->size-1)
	printf("Stack Overflow\n");
	else
	 {
	 	St->top++;
	 	St->Array[St->top] = x;
	 }
}

void popfromStack(struct Stack *St)
{
	if(St->top == -1)
		printf("Stack Underflow\n");
	else
	 {
	 	St->top--;
	 }
}

int isEmpty(struct Stack St)
{
	if(St.top == -1)
	return 1;
	else
	return 0;
}

int isBalanced(char *string)
{
	struct Stack St;
	int i;
	int len = strlen(string);
	
	createStack(&St,len);
	
	for(i=0;string[i]!='\0';i++)
	{
		if(string[i] == '(')
		pushinStack(&St,i);
		else if(string[i] == ')')
		 {
		 	if(isEmpty(St))
		 	return 0;
		 	else
		 	{
		 		popfromStack(&St);
			 }
		 	
		 }
	}
	return isEmpty(St) ? 1 : 0;
}

int main()
{
	char string[100];
	printf("Enter the expression : ");
	scanf("%s",string);
	if(isBalanced(string))
	printf("Balanced");
	else
	printf("Unbalanced");
}
