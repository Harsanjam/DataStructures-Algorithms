#include <stdlib.h>
#include "towers.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int n, from, dest;
/*this if statement is excuted when the user doesn't provide any inputs/arguments and runs the default setting*/
    if(argc == 1)
    {
    	n = 3;
	from = 1;
	dest = 2;
    }
/*This statement checks to see if the user doesn't enter a negative number or 0 as an input for disks when there is only 1 argument typed*/
    if(argc == 2)
    {
    	n = atoi (argv[1]);
	from = 1;
	dest = 2;

	if (n <= 0)
	{
		fprintf (stderr, "There cannot be 0 or negative disks.");
		exit (1);
	}
    }
    /*this statement is when user types in 3 arguments*/
    if(argc == 4)
	{    
	n = atoi (argv[1]);
	from = atoi (argv[2]);
	dest = atoi (argv[3]);
	/*this if statement checks if the user didn't enter negative or 0 values for the 3 inputs*/
	if (n <= 0 || from <= 0 || dest <= 0)
	{
		fprintf (stderr, "There cannot be negative disks or negative values for From and Dest. They have to be greater than 0.");
		exit (1);
	}
/*this else if statement checks if the user doesn't type similar values for "from" and "dest" variables*/
	else if (from == dest)
	{
		fprintf (stderr, "Incorrect Arguments, The From and the Dest values are the same.");
		exit (1);
	}
	/*this else if statement makes sure that the user only picks between 1,2 & 3 for tower*/
	else if (from > 3 || dest > 3)
	{
		fprintf (stderr, "There is only 3 towers. You must enter between 1 and 3 for both From and Dest");
		exit (1);
	}	
    }

    towers(n, from, dest);
    exit(0);
}
