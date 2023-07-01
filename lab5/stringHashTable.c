//  
//
/*

#define HASH_TABLE_SIZE 1057
typedef struct Entry Entry, *EntryPtr;
struct Entry {
  char * string;
  int count;
};
Entry hash_table[HASH_TABLE_SIZE];

void add(char * tag)
{
}
*/

#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>

#define HASH_TABLE_SIZE 1057
typedef struct Entry Entry, *EntryPtr;
struct Entry 
{
  	char * string;
  	int count;
};

Entry hash_table[HASH_TABLE_SIZE];

void add(char *tag){
	int hash, i;
	int intTag = strlen(tag);
	hash = intTag%HASH_TABLE_SIZE;
	if(hash_table[hash].count == 0) {
		//hash_table[hash].string = tag
		hash_table[hash].string = (char *) malloc(500);
		strcpy(hash_table[hash].string, tag);
		hash_table[hash].count++;
	}
	else {
		for(i = hash + 1; i < HASH_TABLE_SIZE; i++) {
			if(hash_table[i].count == 0) {
				//hash_table[hash].string = tag;
				hash_table[i].string = (char *) malloc(500);
				strcpy(hash_table[i].string, tag);
				hash_table[i].count++;	     
				i = HASH_TABLE_SIZE;
			}
			if(i == HASH_TABLE_SIZE - 1)
				i = 0;
		}	   	   	   
	}
}

void print()
{
	
	for(int x =0; x<HASH_TABLE_SIZE;x++)
	{
		if(hash_table[x].count!=0)
		{
			printf("%s %d \n", hash_table[x].string, hash_table[x].count);
		}
	}
}
