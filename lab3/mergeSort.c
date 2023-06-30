#include "mySort.h"
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of array[].
// First subarray is array[left..middle]
// Second subarray is array[middle+1..right]
void merge(int array[], int left, int middle, int right)
{
    int i, j, k;
    int s1 = middle - left + 1;
    int s2 =  right - middle; 

//create temporary arrays
    int tempL[s1], tempR[s2]; 

//for loops to copy data to temporary arrays    
//tempL[] 
    for (i = 0; i < s1; i++)
        myCopy(&array[left + i], &tempL[i]);
//tempR[]
    for (j = 0; j < s2; j++)
        myCopy(&array[middle + 1+ j], &tempR[j]);

//Merge the temp arrays back into arr[l..r]
    i = 0; // i represents the initial index of first subarray
    j = 0; // j represents the initial index of second subarray
    k = left; // k represenst the initial index of the merged subarray

    while (i < s1 && j < s2)
    {
        if (myCompare(tempL[i],tempR[j]) <= 0)
        {
            myCopy(&tempL[i++],&array[k]);
        }
        else
        {
            myCopy(&tempR[j++],&array[k]);
        }
        k++;
    }

// while loop copies any remaining elements of tempL[]
    
    while (i < s1)
    {
        myCopy(&tempL[i++],&array[k++]);
    }

 // while loop copies any remaining elements of tempR[]
    while (j < s2)
    {
        myCopy(&tempR[j++],&array[k++]);
    }
}

/* int left is for left index and int right is for the right index of the
sub-array that needs to be sorted */
void mySort(int array[], unsigned int left, unsigned int right)
{
    if (left < right)
    {
        int middle = (left+right)/2;

// Sort first and second halves
        mySort(array, left, middle);
        mySort(array, middle+1, right);
        merge(array, left, middle, right);
    }
}
