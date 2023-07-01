#include <stdio.h>
#include <stdlib.h>

/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

static int size = 0;
int heap[100];
static int Count = 0;


void swap(int *i, int *j) {
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
} 

void maxHeapify(int arr[], int arrSize, int element) {
	int left = 2 * element + 1;
	int right = 2 * element + 2;
	int largest = element;
	
	if (left < size && arr[left] > arr[largest])
		largest = left;

	if (right < arrSize && arr[right] > arr[largest])
		largest = right;

	if (largest != element) {
		swap(&arr[element], &arr[largest]);
		maxHeapify(arr, arrSize, largest);
	}
}

// positioning of the XML style heap
void MaxHeap(int arr[], int arrSize) {
	size = arrSize;
	int i;
	for (i = ((arrSize/2)-1); i >= 0; i--) 
		maxHeapify(arr, arrSize, i);
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
	heap[size] = thing2add;
	size++;

	MaxHeap(heap, size);

}

// Print xml style
void printHeap(int i) {

	int j;
	for (j = Count++; j > 0; j--)
		fprintf(stdout, "\t");

	fprintf(stdout, "<node id=\"%d\">\n", heap[i]);
	
	int left = 2 * i + 1;	

	if(left < size) {
		printHeap(left);
		Count--;
	}
	
	int right = 2 * i + 2;	

	if(right < size) {
		printHeap(right);
		Count--;
	}

	for (j = (Count - 1); j > 0; j--)
		fprintf(stdout, "\t");
	fprintf(stdout,"</node>\n");
}
	

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
	int max = heap[0];
	heap[0] = heap[size - 1];
	size--;
	MaxHeap(heap, size);

        return max;  //A dummy return statement
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;  
}
