#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern char *  pop();
extern void push(char *);
extern int isEmpty();
extern void add(char *);
extern void print();

int main(int argc, char * argv[])
{
    int ch;
    char arr1[100], arr2[100];
    
    
    while ((ch = getchar()) != EOF) 
	{
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
	    continue;
		else if(ch=='<')
		{
			ch  = getchar();
				if ((isalpha(ch)))
				{	
					char *str;
					int i=0;
				while(ch!='>')
				{
					arr1[i]=ch;
					i++;
					ch= getchar();
		}
		
		str =(char *) malloc(i);
		strcpy(str, arr1);
		push(str);
		add(str);
		
	    }
	    else if(ch == '/')
		{		
		int i=0;
		ch  = getchar();
		
		while(ch!='>')
		{
		    arr1[i]=ch;
		    ch=getchar();
		    i++;
		}
		
		if(isEmpty() != 0)
		{
		    strcpy (arr2, pop());
		    if(strcmp(arr1, arr2) != 0)
			{
				printf("Not Valid\n");
				exit(1);
		    }
		}
		else
		{
		    printf(" Not Valid\n");
		    exit(1);
		}
	    }
	}
    }
    if(isEmpty() == 0)
	{
	    printf("Valid\n");
	    printResult();
	    exit(0);
   	}
    printf("Not Valid\n");
    exit(1);
}
