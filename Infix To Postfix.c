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

char popfromStack(struct Stack *St)
{
	char x;
	if(St->top == -1)
		printf("Stack Underflow\n");
	else
	 {
	 	x = St->Array[St->top];
	 	St->top--;
	 }
	 return x;
}

int isOperand(char x)
{
	if(x == '+' || x == '-' || x == '*' || x == '/')
	return 0;
	else
	return 1;
}

int precedence(char x)
{
	if(x == '+' || x == '-')
		return 1;
	else if(x == '*' || x == '/')
		return 2;
	return 0;
}

int isnotEmpty(struct Stack St)
{
	if(St.top == -1)
	return 0;
	else
	return 1;
}

char* intoPostfix(char *exp)
{
	struct Stack St;
	int len = strlen(exp);
	len = len+2;
	
	createStack(&St,len);
	
	int i=0,j=0;
	char *postfix;
	
	postfix = (char *)malloc((len)*sizeof(char));
	
	
	while(exp[i]!='\0')
	{
		if(isOperand(exp[i]))
		{
			postfix[j++] = exp[i++];
		}
		else
		{
			if(precedence(exp[i]) > precedence(St.Array[St.top]))
			pushinStack(&St,exp[i++]);
			
			else
			postfix[j++] = popfromStack(&St);
		}
	}
	
	while(isnotEmpty(St)) 
	{
		postfix[j++] = popfromStack(&St);
	}
	
	postfix[j] = '\0';
	
	return postfix;
}

int main()
{
	char *infix = "a+b*c*d*e";
	char *x;
	x = intoPostfix(infix);
	printf("%s",x);
}
