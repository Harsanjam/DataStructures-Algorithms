#include <stdlib.h>
#include <stdio.h>
/*State Machine
A F E
B C F
C E G
D G H
E B A
F D F
G A H
H C B
 
The starting state is A */
typedef struct stateMachine{
        char  name;
	int var;
	int number;//The states number in the array
	int delete;
	struct stateMachine* nextzero;
	struct stateMachine* nextone;
} fsm;

fsm states[8];

void initial_states(){
     //State A
         states[0].name = 'A';
	 states[0].number = 0;
	 states[0].nextzero = states + 5; //State F
	 states[0].nextone = states + 4; //State E
	 states[0].delete = 0;
	 
	 //State B
	 states[1].name = 'B';
	 states[1].number = 1;
	 states[1].nextzero = states + 2; //State C
	 states[1].nextone = states + 5; //State F
 	 states[1].delete = 0;
	 
	 //State C
	 states[2].name = 'C';
	 states[2].number = 2;
	 states[2].nextzero = states + 6; //State G
	 states[2].nextone = states + 3; //State D
	 states[2].delete = 0;
	 
	 //State D
	 states[3].name = 'D';
	 states[3].number = 3;
	 states[3].nextzero = states + 6; //State G
	 states[3].nextone = states + 7; //State H
 	 states[3].delete = 0;
	 
	 //State E
	 states[4].name = 'E';
	 states[4].number = 4;
	 states[4].nextzero = states + 1; //State B
	 states[4].nextone = states + 0; //State A
 	 states[4].delete = 0;
 
         //State F
	 states[5].name = 'F';
	 states[5].number = 5;
	 states[5].nextzero = states + 3; //State D
	 states[5].nextone = states + 5; //State F
 	 states[5].delete = 0;
	 
	 //State G
	 states[6].name = 'G';
	 states[6].number = 6;
	 states[6].nextzero = states + 0; //State A
	 states[6].nextone = states + 7; //State H
	 states[6].delete = 0;

	 //State H
	 states[7].name = 'H';
	 states[7].number = 7;
	 states[7].nextzero = states + 2; //State C
	 states[7].nextone = states + 1; //State B	
         states[7].delete = 0; 
}

void printstates()
{
  int i;
  //fprintf(stdout, "\n");
  
  for (i=0; i < 8; i++)
  
    
    {
      fprintf(stdout, "%c ",  states[i].name);
      fprintf(stdout, "%c ",  states[i].nextzero -> name);
      fprintf(stdout, "%c\n", states[i].nextone  -> name);
    }
  
 //fprintf(stdout, "\n");
}
int main(int argc, char * argv[])
{
  int i, j=0;
  char comm[5]; //an array for taking in commands passed
  initial_states();
  fsm current_State = states[0]; //Starting State of FSM which is A
  //Display to the users:
	fprintf(stdout, "INSTRUCTIONS \n");
	fprintf(stdout, "------------\n");
	fprintf(stdout, "Enter a command (0 or 1) to switch states.\n");
	fprintf(stdout, "to print the entire state pattern, simple type 'p'. (it is case sensitive).\n");
	fprintf(stdout, "To set your own path for states (ex. starting in A changing path to B when 0 when normal path is A -> C for 0)\n");
	fprintf(stdout, "Use the command c 0 b where c is the change command, 0 or 1 is the path, and the last character is the destination (A-H)\n");
	fprintf(stdout, "To delete a state use the command d and then followed by a state name. (ex. da)\n");
	fprintf(stdout, "To check garbage collection use the command g.\n");
	fprintf(stdout, "to exit the program, simply type 'q' to quit. (it is case sensitive). \n");
  	fprintf(stdout, "Starting State: %c \n", current_State.name);
  
  while(j!=1)
{

	//An optional quit command
	  if(comm[0] == 'q')
	  {
	     j =1;
		 break;
	  }

	//If user enter p to print
   	 if(comm[0] == 'p')
	  {
	     printstates();
	  }
  
      for(i=0; i<=4;i++)
	  {
	    scanf("%c",&comm[i]);
		if (comm[i] == '\n')
		{
		   
		   break;
		}
	  }

     	//If the user enters 0
	  if(comm[0] == '0')
	  {
		if(current_State.delete == 1)
			{
				fprintf(stdout,"The state is deleted\n");
				break;
			}
	        fprintf(stdout, "%c\n",current_State.nextzero->name);
		current_State = states[current_State.nextzero->number];
	  }
	  
	   //If the user enters 1
	  if(comm[0] == '1')
	  {
		if(current_State.delete == 1)
			{
				fprintf(stdout,"The state is deleted\n");
				break;
			}
	        fprintf(stdout, "%c\n",current_State.nextone->name);
		current_State = states[current_State.nextone->number];
	  }

	if (comm[0] == 'd')
        {
            for(i=0; i<8;i++)
            {
                if (states[i].name == comm[2]){
                    states[i].delete = 1;
                    fprintf(stdout, "State %c deleted\n", states[i].name);
                }
            }
        }

        if(comm[0] == 'c' && current_State.delete != 1)
        {
            if (comm[2] == '1')
	     {
                for(i=0; i<8;i++)
                {
                if (states[i].name == comm[4]){
                   fprintf(stdout, "Changing 1 path for %c to %c\n",current_State.name,states[i].name);
                    current_State.nextone = states + i;
                    states[current_State.number].nextone = states + i;
                  }

              }

    
          }
            else if (comm[2]=='0' && current_State.delete !=1)

	{
	  for(i=0; i<8; i++)
            {
                if (states[i].name == comm[4]){
                    fprintf(stdout, "Changing 1 path for %c to %c\n",current_State.name,states[i].name);
                    current_State.nextzero = states + i;
                    states[current_State.number].nextzero = states + i;
                }
            }
	  }
	}
        }

	exit(0);
}
