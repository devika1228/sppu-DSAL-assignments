#include<stdio.h>
#include<ctype.h>
#define MAX 50

typedef struct stack
{
	char data[MAX];
	int top;
}stack;


char pop(stack *);
void push(stack *,char);


int main()
{
	stack s;
	char exp[MAX];
	char token,ch;
	int i=0,flag;
	s.top=-1;

	printf("\n\n\n\t\tEnter expression:");
        scanf("%s",exp);
	while(exp[i]!='\0')
	{
			if(exp[i] == '(')
			{
				push(&s,'(');

			}
			if(exp[i] == '[')
			{
				push(&s,'[');

			}
			 if(exp[i] == '{')
			{
				push(&s,'{');

			}

			if(exp[i] == ')')
			{
					token=pop(&s);
					if(token=='(')
						flag=1;
					else
					{
						flag=0;
						ch=')';
					    break;
					}
			}

			if(exp[i] == '}')
			{
					token=pop(&s);
					if(token=='{')
					flag=1;
					else
					{
						 flag=0;
						 ch='}';
						 break;
					}
			}
			if(exp[i] == ']')
			{
					token=pop(&s);
					if(token=='[')
					flag=1;
					else
					{
						flag=0;
						ch=']';
						break;
					}
			}
			i++;
	}
	ch=pop(&s);
	if(ch!='#')
	{
			flag=0;
	}
	
	if(flag==1)
		printf("\n\n\t\t no error\n\n\n ");
	else
		printf("\n\n\t\t Syntax error\n\n\t\terror at %c\n\n ",ch);
	return (0);
}

void push(stack *s,char x)
{
	s->top=s->top+1;
	s->data[s->top]=x;
}

char pop(stack *s)
{
	int x;
	if(s->top!=-1)
	{
		x=s->data[s->top];
		s->top=s->top-1;
		return(x);
		
	}
	else
		return('#');
}


