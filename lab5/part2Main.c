#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[]){
  	int ch, popped, i ;
	int i = 0;
	char array [26][2] = {    {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, 
				              {'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0},
				              {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0},
				              {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0},
				              {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0},
	  		                  {'z', 0}}; 
	
	while ((ch = getchar()) != EOF) 
	{
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
		continue;
	
	  // If we are currently reading a tag
	    else if(ch =='<')
		{
			ch  = getchar();

			//Start tag
			if ((isalpha(ch)))
			{
				push(ch);
				for (i = 0; i < 26; i++) {
					if (array[i][0] == ch)
						array[i][1]++;
				}
			}

			//End Tag
			else if(ch == '/')
			{
				ch  = getchar();
				if(isEmpty())
				{
					exit(1);
				}
				popped = pop();
				if(popped != ch)
				{
					printf("Not Valid");
					exit(1);
				}
			}
		} 
	}
	if(!(isEmpty()))
	{
		printf("Not Valid");
		exit(1);
	}
	else
	{
		printf("Valid\n");
		for (i = 0; i < 26; i++) {
		if ((int)array[i][1] > 0)
			fprintf(stdout, "%c %d\n", array[i][0], array[i][1]);
			}	
		exit(0);
	}
}
