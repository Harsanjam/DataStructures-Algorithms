#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();
extern void addHeap(int);
extern void printHeap(int);
extern int heapDelete();
extern int heapSize();

int main(int argc, char * argv[])
{
  int value;

  while (scanf("%d\n", &value) != EOF) {
   
    fprintf(stderr, "READING INPUT: %d\n", value);
    addHeap(value);
  }


  printHeap(0);
	
// Descending order
  int temp;
  int i;
  for (i = heapSize(); i > 0; i--) { 
    temp = heapDelete();
    push(temp);
 
    fprintf(stdout, "Descending order: %d\n", temp);
  }

// Ascending order
  while (isEmpty() != 1) 
     
     fprintf(stdout, "Ascending order: %d\n", pop());


  exit(0);
}
