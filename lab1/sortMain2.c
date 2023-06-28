#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

int main(int argc, char* argv[])

{
  int data[100000]; 
  int nDataItems;   
  int i;

  if (argc > 1)
  {
    nDataItems = argc - 1;
    for (i = 1; i < argc; i++)
    {
      data[i - 1] = atoi(argv[i]);
    }
    for (i = 0; i < nDataItems; i++)
    {
      mySort(data, nDataItems);
    }
  }
  else if (argc == 1)
  {
    
    nDataItems = 5;
    data[0] = 3;
    data[1] = 1;
    data[2] = 5;
    data[3] = 2;
    data[4] = 8;
    mySort(data, nDataItems);
  }
  for (i = 0; i < nDataItems; i++)
  {
    printf("%d\n", data[i]);
  }
  exit(0);
}
