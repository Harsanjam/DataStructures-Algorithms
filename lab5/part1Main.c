#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();
int main(int argc, char * argv[])
{
  int ch,popped;
  while ((ch = getchar()) != EOF) 
  {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
    continue;
	
	else if(ch=='<')
	{
		ch  = getchar();
		if ((isalpha(ch)))
		{
			push(ch);
		}
		else if(ch == '/')
		{
			ch  = getchar();
			if(isEmpty())
			{
			exit(0);
			}
			popped = pop();
		if(popped != ch)
		{
			printf("Not Valid\n");
			exit(1);
		}
	}
	} 
	}
	if(!(isEmpty()))
	{
		printf("Not Valid\n");
		exit(1);
	}
	else
	{
		printf("Valid\n");
		exit(0);
	}
    
}
